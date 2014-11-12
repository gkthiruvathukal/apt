/******************************************************************
**
** ARGS.H:
**
**    Argument Parsing System
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

/*
** The MatchDescriptor is a record which describes a successful match of one
** of the said options in the OptionDescriptorVector.  When a match occurs for
** some option, a MatchDescriptor is created and filled with information which
** completely describes the match.  The MatchDescriptor is linked to the
** previous one to form a linked list of matches.
*/
struct _MatchDescriptor {
  char *Option;
  int OptionMatched;
  char **Arguments;
  int ArgumentCount;
  char SwitchSetting;
  struct _MatchDescriptor *next;
};
typedef struct _MatchDescriptor MatchDescriptor;
typedef struct _MatchDescriptor *MatchDescriptorPtr;
typedef struct _MatchDescriptor *MatchDescriptorList;

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
void FreeMatchDescriptorList(MatchDescriptorPtr);
MatchDescriptorPtr ParseCommandLine(int,OptionDescriptorBlock,int,char**);
#else
void FreeMatchDescriptorList();
MatchDescriptorPtr ParseCommandLine();
#endif /* __ANSI_C__ */

#endif /* ARGS_H */
