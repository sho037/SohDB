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

char *orYesNo(char yesorno[])
{
  if (strcmp(yesorno, "Y") == 0 || strcmp(yesorno, "y") == 0)
  {
    return "y";
  }
  else if (strcmp(yesorno, "N") == 0 || strcmp(yesorno, "n") == 0)
  {
    return "n";
  }
  else
  {
    return "error";
  }
}

// This program is DB
int main(void)
{
  char operation[ARRAYSIZE];
  char filename[ARRAYSIZE];
  char yesorno[32];
  printf("こんにちは\n");

  do
  {
    printf("どの操作を行いますか？\nDB追加(A), DB更新(B), DB探索(C)\n");
    scanf("%s", operation);
    printf("%s", operation); // develop
    if (strcmp(operation, "DB追加") == 0 || strcmp(operation, "A") == 0)
    {
      printf("データベースを追加するため、ファイル名を決めてください。\n");
      scanf("%s", filename);
      addDataBase(filename);
      printf("データベースの追加を終了します。\n");
    }
    else if (strcmp(operation, "DB更新") == 0 || strcmp(operation, "B") == 0)
    {
      printf("データベースを更新するため、ファイル名を入力してください\n");
      scanf("%s", filename);
      updateDataBase(filename);
      printf("データベースの更新を終了します。\n");
    }
    else if (strcmp(operation, "DB探索") == 0 || strcmp(operation, "C") == 0)
    {
      printf("データベースを探索するため、ファイル名を入力してください\n");
      scanf("%s", filename);
      serchDataBase(filename);
      printf("データベースの探索を終了します。\n");
    }
    else
    {
      printf("正しく入力を行ってください\n");
      continue;
    }

    do
    {
      printf("データベースの操作を続けますか？(Y/n)\n");
      scanf("%s", yesorno);
    } while (strcmp(orYesNo(yesorno), "error") == 0);

  } while (!(strcmp(orYesNo(yesorno), "y") == 0));

  return 0;
}