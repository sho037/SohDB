#include <stdio.h>
#include <string.h>


// This program is DB
int main (void) {
  char *operation;
  printf("こんにちは\n");
  printf("どの操作を行いますか？\nDB追加(A), DB削除(B), DB探索(C)\n");
  scanf("%s", operation);
  if (strcmp(operation, "DB追加") == 0 || strcmp(operation, "A") == 0)
  {
    /* code */
  }
  else if (strcmp(operation, "DB削除") == 0 || strcmp(operation, "B") == 0)
  {
    /* code */
  }
  else if (strcmp(operation, "DB探索") == 0 || strcmp(operation, "C") == 0)
  {
    /* code */
  }
  

  return 0;
}