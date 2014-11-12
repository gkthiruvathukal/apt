/******************************************************************
**
** APTCLASS.C:
**
**    APT Token Classification Module.
**
**    Scanner calls classify to potentially map a token into
**    another token.  A common use is to map identifiers to keywords.
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- Headers */

#include "apt.h"
#include "aptclass.h"
#include "aptparse.h"

#include "aptlib.h"
#include "astlib.h"

#include "sstring.h"

/* ---------- Functions */

int Classify( token, attribute )
Token token;
int attribute;
{
  if (attribute == T_ident && token->column == 1) {
    if (StringCompare(token->text,"%ACTIONS") == 0) return (T_actions);
    if (StringCompare(token->text,"%ALIASES") == 0) return (T_aliases);
    if (StringCompare(token->text,"%FIDUCIALS") == 0) return (T_fiducials);
    if (StringCompare(token->text,"%PHASES") == 0) return (T_phases);
    if (StringCompare(token->text,"%PRODUCTIONS") == 0) return (T_productions);
    return (T_ident);
  }
  return (attribute);
}
