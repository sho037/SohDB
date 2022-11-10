#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "sohdatabase.h"

#define ARRAYSIZE 256

// This program is DB
int main(void)
{
  char operation[ARRAYSIZE];
  char filename[ARRAYSIZE];
  char yesorno[32];
  printf("こんにちは\n");

  do
  {
    printf("どの操作を行いますか？\n");
    printAllMode();
    scanf("%s", operation);
    printf("%s\n", operation); // develop
    if (whichOperation(operation, "add"))
    {
      addDataBase();
    }
    else if (whichOperation(operation, "update"))
    {
      updateDataBase();
    }
    else if (whichOperation(operation, "serch"))
    {
      serchDataBase();
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
    } while (!orYesNo(yesorno, "error"));

  } while (!orYesNo(yesorno, "no"));

  return 0;
}