#include <stdio.h>
#include <string.h>

void addDataBase(char *filename)
{
}

void updateDataBase(char *filename)
{
}

void serchDataBase(char *filename)
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
    printf("データベースを追加するため、ファイル名を決めてください。\n");
    scanf("%s", filename);
    addDataBase(filename);
  }
  else if (strcmp(operation, "DB更新") == 0 || strcmp(operation, "B") == 0)
  {
    updateDataBase(filename);
  }
  else if (strcmp(operation, "DB探索") == 0 || strcmp(operation, "C") == 0)
  {
    serchDataBase(filename);
  }

  return 0;
}