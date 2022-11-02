#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ARRAYSIZE 256

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

// existFile関数
// 引数として与えられたファイルが存在するかどうかを判定する
// 存在する場合は戻り値がtrue、存在しない場合はfalseを返す
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

// whichOperation関数
// 引数として与えられた文字列がどの操作を表すのかを判定し、簡単に分かるようにして返却する
// 返り値は"add","update","serch"になる
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

void addDataBase()
{
  char filename[ARRAYSIZE];
  printf("データベースを追加するため、ファイル名を決めてください。\n");
  do
  {
    scanf("%s", filename);
    if (existFile(filename))
    {
      printf("ファイルが存在するため、もう一度ファイル名を入力しなおしてください。\n");
    }
  } while (existFile(filename));
  printf("データベースの追加を終了します。\n");
}

void updateDataBase()
{
  char filename[ARRAYSIZE];
  printf("データベースを更新するため、ファイル名を入力してください\n");
  do
  {
    scanf("%s", filename);
    if (!existFile(filename))
    {
      printf("ファイルが存在しないため、もう一度ファイル名を入力しなおしてください。\n");
    }
  } while (!existFile(filename));
  printf("データベースの更新を終了します。\n");
}

void serchDataBase()
{
  char filename[ARRAYSIZE];
  printf("データベースを探索するため、ファイル名を入力してください\n");
  do
  {
    scanf("%s", filename);
    if (!existFile(filename))
    {
      printf("ファイルが存在しないため、もう一度ファイル名を入力しなおしてください。\n");
    }
  } while (!existFile(filename));
  printf("データベースの探索を終了します。\n");
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
      addDataBase();
    }
    else if (strcmp(whichOperation(operation), "update") == 0)
    {
      updateDataBase();
    }
    else if (strcmp(whichOperation(operation), "serch") == 0)
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
    } while (strcmp(orYesNo(yesorno), "error") == 0);

  } while (!(strcmp(orYesNo(yesorno), "y") == 0));

  return 0;
}