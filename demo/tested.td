#ifndef test_td
#define test_td

#include "aptlib.h"
#include "astlib.h"


enum _SemanticStackTypes {
   SST_Token,
   SST_Void
};

struct _SemanticStackElement {
   enum _SemanticStackTypes type;
   union _SemanticStackElementUnion {
      Token U_Token;
   } u;
};

#endif /* test_td */
