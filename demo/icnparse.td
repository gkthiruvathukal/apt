#ifndef icnparse_td
#define icnparse_td

#include "aptlib.h"
#include "astlib.h"

typedef void *Queue;
typedef void *Type;
typedef void *Misc;
typedef void *Expression;
typedef void *CaseClause;

enum _SemanticStackTypes {
   SST_Queue,
   SST_Type,
   SST_Misc,
   SST_Expression,
   SST_CaseClause,
   SST_Token,
   SST_Void
};

struct _SemanticStackElement {
   enum _SemanticStackTypes type;
   union _SemanticStackElementUnion {
      Queue U_Queue;
      Type U_Type;
      Misc U_Misc;
      Expression U_Expression;
      CaseClause U_CaseClause;
      Token U_Token;
   } u;
};

#endif /* icnparse_td */
