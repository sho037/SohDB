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
    if (whichOperation(operation, "create"))
    {
      createDataBase();
    }
    else if (whichOperation(operation, "delete"))
    {
      deleteDataBase();
    }
    else if (whichOperation(operation, "show"))
    {
      showDataBase();
    }
    else if (whichOperation(operation, "search"))
    {
      searchDataBase();
    }
    else if (whichOperation(operation, "add"))
    {
      addDataBase();
    }
    else
    {
      printf("入力された操作は存在しません\n");
    }

    do
    {
      printf("データベースの操作を続けますか？(Y/n)\n");
      scanf("%s", yesorno);
    } while (!orYesNo(yesorno, "error"));

  } while (!orYesNo(yesorno, "no"));

  return 0;
}