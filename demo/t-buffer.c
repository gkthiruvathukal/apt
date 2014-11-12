#include "buffer.h"

main()
{
  Buffer b = BufferNew();
  char *contents;

  BufferAddChar(b, 'A');
  BufferAddChar(b, 'P');
  BufferAddChar(b, 'T');
  contents = BufferToString(b);  
  printf("The buffer b = %s has %d bytes.\n", contents, BufferSize(b));

  BufferAddChar(b, ' ');
  BufferAddString(b, "Compiler");
  BufferAddChar(b, ' ');
  BufferAddString(b, "Toolkit");

  contents = BufferToString(b);  
  printf("The buffer b = %s has %d bytes.\n", contents, BufferSize(b));

  BufferAddChar(b, ' ');
  BufferAddString(b, contents);
  contents = BufferToString(b);  
  printf("The buffer b = %s has %d bytes.\n", contents, BufferSize(b));
}
