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
    printf("\nどの操作を行いますか？\n");
    printAllMode();
    printf("操作を入力してください: ");
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

    printf("続けますか？\n");
  } while (askYesNo("yes"));

  return 0;
}