#include <stdio.h>
#include <string.h>

void addDataBase(void)
{
}

void removeDataBase(void)
{
}

void serchDataBase(void)
{
}

void updateDataBase(void)
{
}

// This program is DB
int main(void)
{
  char *operation;
  char *filename;
  printf("こんにちは\n");
  printf("どの操作を行いますか？\nDB追加(A), DB更新(B), DB探索(C)\n");
  scanf("%s", operation);
  if (strcmp(operation, "DB追加") == 0 || strcmp(operation, "A") == 0)
  {
    addDataBase();
  }
  else if (strcmp(operation, "DB更新") == 0 || strcmp(operation, "B") == 0)
  {
    removeDataBase();
  }
  else if (strcmp(operation, "DB探索") == 0 || strcmp(operation, "C") == 0)
  {
    serchDataBase();
  }

  return 0;
}