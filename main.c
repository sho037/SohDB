#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ARRAYSIZE 256

// printAllMode関数
// すべてのモードを表示する
void printAllMode(void)
{
    printf("DBを作成する      : create, 作成\n");
    printf("DBを削除する      : delete, 削除\n");
    printf("DBの内容を表示する: show, 表示\n");
    printf("DB内を検索する    : search, 検索\n");
    printf("DBの内容を追加する: add, 追加\n");
}

// orYesNo関数
// 引数の値がYes(y)かNo(n)かを判定する第二引数に判定する文字を入れる
// 返り値はtureかfalse
bool orYesNo(char yesorno[], char match[])
{
  if (strcmp(match, "yes") == 0 && (strcmp(yesorno, "Y") == 0 || strcmp(yesorno, "y") == 0))
  {
    return true;
  }
  else if (strcmp(match, "no") == 0 && (strcmp(yesorno, "N") == 0 || strcmp(yesorno, "n") == 0))
  {
    return true;
  }
  else if (strcmp(match, "error") == 0)
  {
    return true;
  }
  else
  {
    return false;
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
// 第一引数に入れられた操作と、第二引数に入れられた操作が一致するかどうかを判定する
// 戻り値はture、falseになる。
bool whichOperation(char operation[], char match[])
{
  if (strcmp(match, "add") == 0 && (strcmp(operation, "DB追加") == 0 || strcmp(operation, "追加") == 0 || strcmp(operation, "add") == 0))
  {
    return true;
  }
  else if (strcmp(match, "update") == 0 && (strcmp(operation, "DB更新") == 0 || strcmp(operation, "更新") == 0 || strcmp(operation, "update") == 0))
  {
    return true;
  }
  else if (strcmp(match, "serch") == 0 && (strcmp(operation, "DB探索") == 0 || strcmp(operation, "探索") == 0 || strcmp(operation, "serch") == 0))
  {
    return true;
  }
  return false;
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