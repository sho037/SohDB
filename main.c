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
    if (whichOperation(operation, "create"))
    {
      createDatabase();
    }
    else if (whichOperation(operation, "delete"))
    {
      deleteDatabase();
    }
    else if (whichOperation(operation, "show"))
    {
      showDatabase();
    }
    else if (whichOperation(operation, "search"))
    {
      searchDatabase();
    }
    else if (whichOperation(operation, "add"))
    {
      addDatabase();
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