#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

// orYesNo関数
// 引数の値がYes(y)かNo(n)かを判定する
// 返り値は"y"か"n"か"error"
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

bool existFile(const char *path)
{
  FILE *fp = fopen(path, "r");
  if (fp == NULL)
  {
    return false;
  }

  fclose(fp);
  return true;
}

char *whichOperation(char operation[])
{
  if (strcmp(operation, "DB追加") == 0 || strcmp(operation, "追加") == 0 || strcmp(operation, "add") == 0)
  {
    return "add";
  }
  else if (strcmp(operation, "DB更新") == 0 || strcmp(operation, "更新") == 0 || strcmp(operation, "update") == 0)
  {
    return "update";
  }
  else if (strcmp(operation, "DB探索") == 0 || strcmp(operation, "探索") == 0 || strcmp(operation, "serch") == 0)
  {
    return "serch";
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
    printf("どの操作を行いますか？\nDB追加, DB更新, DB探索\n");
    scanf("%s", operation);
    printf("%s", operation); // develop
    if (strcmp(whichOperation(operation), "add") == 0)
    {
      printf("データベースを追加するため、ファイル名を決めてください。\n");
      do
      {
        scanf("%s", filename);
        if (existFile(filename))
        {
          printf("ファイルが存在するため、もう一度ファイル名を入力しなおしてください。\n");
        }
      } while (existFile(filename));

      addDataBase(filename);
      printf("データベースの追加を終了します。\n");
    }
    else if (strcmp(whichOperation(operation), "update") == 0)
    {
      printf("データベースを更新するため、ファイル名を入力してください\n");
      do
      {
        scanf("%s", filename);
        if (!existFile(filename))
        {
          printf("ファイルが存在しないため、もう一度ファイル名を入力しなおしてください。\n");
        }
      } while (!existFile(filename));

      updateDataBase(filename);
      printf("データベースの更新を終了します。\n");
    }
    else if (strcmp(whichOperation(operation), "serch") == 0)
    {
      printf("データベースを探索するため、ファイル名を入力してください\n");
      do
      {
        scanf("%s", filename);
        if (!existFile(filename))
        {
          printf("ファイルが存在しないため、もう一度ファイル名を入力しなおしてください。\n");
        }
      } while (!existFile(filename));

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