#ifndef ntparse_td
#define ntparse_td

#include "aptlib.h"
#include "astlib.h"
#include "nttype.h"

enum _SemanticStackTypes {
   SST_Queue,
   SST_Enum,
   SST_Node,
   SST_Slot,
   SST_Token,
   SST_Void
};

struct _SemanticStackElement {
   enum _SemanticStackTypes type;
   union _SemanticStackElementUnion {
      Queue U_Queue;
      Enum U_Enum;
      Node U_Node;
      Slot U_Slot;
      Token U_Token;
   } u;
};

#endif /* ntparse_td */
