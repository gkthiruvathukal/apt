#ifndef aptparse_td
#define aptparse_td

#include "aptlib.h"
#include "astlib.h"
#include "apttype.h"

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

#endif /* aptparse_td */
