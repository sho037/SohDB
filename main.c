#include <stdio.h>
#include <string.h>
#define ARRAYSIZE 256

void addDataBase(char filename[])
{
}

void updateDataBase(char filename[])
{
}

void serchDataBase(char filename[])
{
}

// This program is DB
int main(void)
{
  char operation[ARRAYSIZE];
  char filename[ARRAYSIZE];
  printf("こんにちは\n");
  printf("どの操作を行いますか？\nDB追加(A), DB更新(B), DB探索(C)\n");
  scanf("%s", operation);
  printf("%s", operation);
  if (strcmp(operation, "DB追加") == 0 || strcmp(operation, "A") == 0)
  {
    printf("データベースを追加するため、ファイル名を決めてください。\n");
    scanf("%s", filename);
    addDataBase(filename);
  }
  else if (strcmp(operation, "DB更新") == 0 || strcmp(operation, "B") == 0)
  {
    printf("データベースを更新するため、ファイル名を入力してください\n");
    scanf("%s", filename);
    updateDataBase(filename);
  }
  else if (strcmp(operation, "DB探索") == 0 || strcmp(operation, "C") == 0)
  {
    printf("データベースを探索するため、ファイル名を入力してください\n");
    scanf("%s", filename);
    serchDataBase(filename);
  }

  return 0;
}