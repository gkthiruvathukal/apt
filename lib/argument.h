/******************************************************************
**
** ARGUMENT.H:
**
**    Argument Parsing System - Less Overhead
**
** This file is part of Apt Computing Tools (ACT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ARGS_H
#define ARGS_H

/* ---------- Defines */

#define EOS '\0'
#define NullString ""
#define SwitchChar '-'

/* ---------- Types */

enum ArgumentTypes { Variable = -1, None = 0 };

#ifdef __ANSI_C__

typedef void (*OptionTriggerFunction)(int optidx,
  int optswitch, char *matchset, int optc, char **optv);

#else

typedef void (*OptionTriggerFunction)();

#endif

/*
/*
** The OptionDescriptor is a record which describes the characteristics of
** an option as completely as possible.  It is the responsibility of the user
** to construct a vector of OptionDescriptor or run the code generation tool.
*/

struct _OptionDescriptor {
  int OptionCode;
  char *Option;
  int OptionType;
  char *Switches;
  int Arguments;
  OptionTriggerFunction action;
};

typedef struct _OptionDescriptor OptionDescriptor;
typedef struct _OptionDescriptor OptionDescriptorBlock[];

enum OptionTypes {
  StraightFlag,
  StraightFlagWithArg,
  SwitchedFlag,
  GroupOfFlags
};

enum SwitchSettings { NotDefined = -1, Reset, Set };

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
void ArgumentParse(int,OptionDescriptorBlock,int,char**,OptionTriggerFunction);
#else
void ArgumentParse();
#endif /* __ANSI_C__ */

#endif /* ARGS_H */
