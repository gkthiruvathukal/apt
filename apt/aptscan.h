#include "aptlib.h"
#include "aptparse.h"
#include "astlib.h"
#include "buffer.h"
#include "bufio.h"

/* States is a merge of states from aptscan1 and aptscan2 */

enum States {
  S_StringEsc,
  S_String,
  S_Char1,
  S_Char,
  S_Number,
  S_Ident,
  S_Section,
  S_Start,
  S_Minus,
  S_NewLine,
  S_Error
};

enum ScanStates {
  NotActionsSection,
  ActionsSection
};

#define StateCount S_Error

#ifdef __ANSI_C__
Token scan1(FILE *file);
Token scan2(FILE *file);
#else
Token scan1();
Token scan2();
#endif /* __ANSI_C__ */
