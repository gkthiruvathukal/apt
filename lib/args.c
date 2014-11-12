/******************************************************************
**
** ARGS.C:
**
**    Argument Parsing System
**
** This file is part of Apt Computing Tools (ACT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

#include "allocate.h"
#include "args.h"

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__
void BuildMatchSet(char *, char *, char *);
void CollectArguments(OptionDescriptor *, char **, int, char **, char **);
void CollectArgumentsUntil(char **, char **, int);
void CollectArgumentsUpToFlag(char **, int, char **, char **);
char CollectSwitch(OptionDescriptor *, char *);
int CountArguments(char **, int, char **);
OptionDescriptor *MatchOption(int, OptionDescriptorBlock, char *);
int MatchString(char *, char *);
MatchDescriptorPtr BuildMatchDescriptor(int, char *, char **, int, char);
char *OptionToArgument(OptionDescriptor *, char *);
int IsArgument(OptionDescriptor *, char *);
int MaxValue(int, int);
int cins(char, char *);
#else
char CollectSwitch();
void CollectArguments();
void CollectArgumentsUpToFlag();
void CollectArgumentsUntil();
int CountArguments();
OptionDescriptor *MatchOption();
int MatchString();
void BuildMatchSet();
MatchDescriptorPtr BuildMatchDescriptor();
char *OptionToArgument();
int IsArgument();
int MaxValue();
int cins();
#endif /* __ANSI_C__ */

int MaxValue(x,y)
int x,y;
{
  return x > y ? x : y;
}

MatchDescriptorPtr ParseCommandLine(OptCount, OptInfo, argc, argv)
int OptCount;
OptionDescriptorBlock OptInfo;
int argc;
char **argv;
{
  char **argp,
  *MatchSet = NullString,
  **OptArgs = NULL,
  Switch = EOS;
  int ArgumentCount,
  offset = 1;
  MatchDescriptorPtr FirstMatch = NULL,
      LastMatch = NULL,
      CurrentMatch;
  OptionDescriptor *MatchedOption;

  for (argp=argv + 1; argp < argv + argc; argp += offset) {
    MatchedOption = MatchOption(OptCount, OptInfo, *argp);
    if (MatchedOption == NULL) {
      /* called a no-match element */
      OptArgs = (char **)Allocate(sizeof(char *));
      OptArgs[0] = *argp;
      CurrentMatch = BuildMatchDescriptor(-1,NullString,OptArgs,1,EOS);
      ArgumentCount = 0;
      offset = 1;
    } else {
      switch(MatchedOption->OptionType) {
      case StraightFlagWithArg:
        /* StraightFlagWithArg falls through when the option is NOT an argument */
        if (IsArgument(MatchedOption, *argp)) {
          if (MatchedOption->Arguments == Variable)
            ArgumentCount = 1 + CountArguments(argv,argc,argp + 1);
          else
            ArgumentCount = MaxValue(1,MatchedOption->Arguments);
          OptArgs = (char **)Allocate(ArgumentCount * sizeof(char *));
          OptArgs[0] = OptionToArgument(MatchedOption, *argp);
          if (ArgumentCount > 1) {
            CollectArguments(MatchedOption,argp+1,argc,argv,OptArgs+1);
          }
          MatchSet = MatchedOption->Option;
          offset = ArgumentCount;
          break;
        }
      case StraightFlag:
        if (MatchedOption->Arguments == Variable)
          ArgumentCount = CountArguments(argv,argc,argp + 1);
        else
          ArgumentCount = MaxValue(0,MatchedOption->Arguments);
        if (ArgumentCount) {
          OptArgs = (char **)Allocate(ArgumentCount * sizeof(char *));
          CollectArguments(MatchedOption,argp+1,argc,argv,OptArgs);
        }
        offset = ArgumentCount + 1;
        MatchSet = MatchedOption->Option;
        break;
      case SwitchedFlag:
        Switch = CollectSwitch(MatchedOption, *argp);
        if (MatchedOption->Arguments == Variable)
          ArgumentCount = CountArguments(argv, argc, argp + 1);
        else
          ArgumentCount = MatchedOption->Arguments;
        if (ArgumentCount) {
          OptArgs = (char **)Allocate(ArgumentCount *sizeof(char *));
          CollectArguments(MatchedOption, argp+1, argc, argv, OptArgs);
        }
        offset = ArgumentCount + 1;
        MatchSet = MatchedOption->Option;
        break;
      case GroupOfFlags:
        if (MatchedOption->Arguments == Variable)
          ArgumentCount = CountArguments(argv, argc, argp + 1);
        else
          ArgumentCount = MatchedOption->Arguments;
        if (ArgumentCount) {
          OptArgs = (char **)Allocate(ArgumentCount * sizeof(char *));
          CollectArguments(MatchedOption, argp+1, argc, argv, OptArgs);
        }
        MatchSet = (char *)Allocate(strlen(MatchedOption->Option)+1);
        BuildMatchSet(*argp, MatchedOption->Option, MatchSet);
        offset = 1;
        break;
      default:
        offset = 1;
      }
      CurrentMatch = BuildMatchDescriptor(MatchedOption - OptInfo,
          MatchSet, OptArgs, ArgumentCount, Switch);
    }
    if (FirstMatch == NULL)
      FirstMatch = CurrentMatch;
    else
      LastMatch->next = CurrentMatch;
    LastMatch = CurrentMatch;
  }
  return FirstMatch;
}

int IsArgument(option,argument)
OptionDescriptor *option;
char *argument;
{
  if (*argument == SwitchChar) {
    if (argument[1 + strlen(option->Option)] == EOS)
      return 0;
    if (option->Switches != NULL)
      if (MatchString(argument+strlen(option->Option)+1,option->Switches))
        return 0;
    return 1;
  }
  return 0;
}

#ifdef __ANSI_C__
MatchDescriptorPtr BuildMatchDescriptor(int OptionMatched, char *Option,
char **Arguments, int ArgumentCount, char SwitchSetting)
#else
MatchDescriptorPtr BuildMatchDescriptor(OptionMatched,Option,Arguments,ArgumentCount,SwitchSetting)
int OptionMatched;
char *Option;
char **Arguments;
int ArgumentCount;
char SwitchSetting;
#endif
{
  MatchDescriptorPtr newMD;
  newMD = (MatchDescriptorPtr)Allocate(sizeof(MatchDescriptor));
  newMD->OptionMatched = OptionMatched;
  newMD->Option = Option;
  newMD->Arguments = Arguments;
  newMD->ArgumentCount = ArgumentCount;
  newMD->SwitchSetting = SwitchSetting;
  newMD->next = NULL;
  return newMD;
}

/*
** CollectSwitch : Collect switches present in a given argument which just
**                   matched an option.
** Assumption: The argument matches the option and is a StraightFlag.  No other
**             flag type is permitted to have a switch present.
** Inputs: option -> the option descriptor
**         argument -> the argument which matched the option descriptor
** Output: a character switch, if the assumption is true and a switch follows
**         the flag...otherwise, 0.
*/

char CollectSwitch(option, argument)
OptionDescriptor *option;
char *argument;
{
  char *p;

  if (option->OptionType != SwitchedFlag)
    return EOS;
  if (option->Switches == NULL)
    return EOS;
  for (p=option->Switches; *p; p++) {
    if ( argument[strlen(option->Option)+1] == *p )
      return *p;
  }
  return EOS;
}

void CollectArguments(option, argp, argc, argv, oargv)
OptionDescriptor *option;
char **argp, **argv, **oargv;
int argc;
{
  switch(option->Arguments) {
  case None:
    break;
  case Variable:
    CollectArgumentsUpToFlag(argp, argc, argv, oargv);
    break;
  default:
    CollectArgumentsUntil(argp, oargv, option->Arguments);
    break;
  }
}

void CollectArgumentsUpToFlag(argp, argc, argv, oargv)
int argc;
char **argv, **argp, **oargv;
{
  for ( ; argp < argv+argc; argp++, oargv++) {
    if (**argp == SwitchChar)
      break;
    *oargv = *argp;
  }
}

void CollectArgumentsUntil(argp, oargv, n)
int n;
char **argp, **oargv;
{
  char **pargv;

  for (pargv=oargv ; pargv < oargv + n; argp++, pargv++)
    *pargv = *argp;
}

/*
** CountArguments : Count arguments for a given option...
** Assumption: Current argument is an option
** Inputs: argc, argv -> command line arguments
**         argp -> current argument
*/
int CountArguments(argv, argc, argp)
char **argv, **argp;
int argc;
{
  char **argq;

  for (argq = argp ; argq < argv+argc; argq++)
    if (**argq == SwitchChar)
      break;
  return argq - argp;
}

/*
** MatchOption : Find an option which matches the current argument.
** Inputs: OptCount, OptInfo -> Option Descriptor Block
**         argument -> the current argument (char *)
** Outputs: an option descriptor or NULL
*/
OptionDescriptor *MatchOption(OptCount, OptInfo, argument)
int OptCount;
OptionDescriptorBlock OptInfo;
char *argument;
{
  OptionDescriptor *option;

  if (*argument++ != SwitchChar) return NULL;
  for (option=OptInfo; option < OptInfo + OptCount; option++) {
    if (option->Option == NULL) continue;
    switch(option->OptionType) {
    case StraightFlag: /* exact match required */
      if (strcmp(argument,option->Option) == 0)
        return option;
      break;
    case StraightFlagWithArg:
      if (strncmp(argument,option->Option,strlen(option->Option)) == 0)
        return option;
      break;
    case SwitchedFlag:
      if (strncmp(argument,option->Option,strlen(option->Option)) == 0) {
        if (cins(argument[strlen(option->Option)],option->Switches))
          return option;
        if (argument[strlen(option->Option)] == EOS)
          return option;
      }
      break;
    case GroupOfFlags:
      if (MatchString(argument,option->Option))
        return option;
      break;
    default:
      fprintf(stdout,"Fatal Error: Unsupported Option Code (opt = %d).\n",option-OptInfo);
      exit(1);
    }
  }
  return NULL;
}

/*
** MatchString : Determine if every character of a source string is a character
**               in a set of characters.
** Inputs: string -> source string
**         set -> a character set
**         image -> a string to indicate whether a character in the set was
**                  found...
** Outputs: 1 iff all characters in string appear in set
**          0 otherwise
*/
int MatchString(string, set)
char *string, *set;
{
  char *p, *q;

  if (string == NullString || *string == EOS)
    return 0;
  for (p=string; *p; p++) {
    for (q=set; *q; q++)
      if (*p == *q)
        break;
    if (!*q) return 0;
  }
  return 1;
}

#ifdef __ANSI_C__
int cins(char c, char *s)
#else
int cins(c, s)
char c, *s;
#endif
{
  if (s == NULL)
    return 0;
  for ( ; *s; s++)
    if (*s == c)
      return 1;
  return 0;
}

/*
** BuildMatchSet: Find characters from a set which appear in string...
*/

void BuildMatchSet(string, set, match_set)
char *string, *set, *match_set;
{
  char *r, *p;

  r = match_set;
  for (p=set; *p; p++) {
    *r++ = *p;
    if (!MatchString(match_set,string))
      r--;
  }
  *r = EOS;
}

char *OptionToArgument(option, argument)
OptionDescriptor *option;
char *argument;
{
  return argument+strlen(option->Option)+1;
}

void FreeMatchDescriptorList(MatchList)
MatchDescriptorPtr MatchList;
{
  MatchList = NULL;
}
