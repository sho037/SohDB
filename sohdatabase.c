#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FILENAMESIZE 200

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
bool isExistFile(const char *path)
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
  if (strcmp(match, "create") == 0 && (strcmp(operation, "create") == 0 || strcmp(operation, "作成")))
  {
    return true;
  }
  else if (strcmp(match, "delete") == 0 && (strcmp(operation, "delete") == 0 || strcmp(operation, "削除")))
  {
    return true;
  }
  else if (strcmp(match, "show") == 0 && (strcmp(operation, "show") == 0 || strcmp(operation, "表示")))
  {
    return true;
  }
  else if (strcmp(match, "search") == 0 && (strcmp(operation, "search") == 0 || strcmp(operation, "検索")))
  {
    return true;
  }
  else if (strcmp(match, "add") == 0 && (strcmp(operation, "add") == 0 || strcmp(operation, "追加")))
  {
    return true;
  }
  else
  {
    return false;
  }
}

void createDataBase()
{
  char filename[FILENAMESIZE];
  printf("データベースを作成するため、ファイル名を決めてください。\n");
  do
  {
    scanf("%s", filename);
    if (isExistFile(filename))
    {
      printf("ファイルが存在するため、もう一度ファイル名を入力しなおしてください。\n");
    }
  } while (isExistFile(filename));

  // ここからデータベースの作成
  FILE *fp = fopen(filename, "w");
  if (fp == NULL)
  {
    printf("ファイルの作成に失敗しました。\n");
    return;
  }
  
  printf("データベースの作成を終了します。\n");
}

void deleteDataBase()
{
  char filename[FILENAMESIZE];
  printf("データベースを削除するため、ファイル名を入力してください。\n");
  do
  {
    scanf("%s", filename);
    if (!isExistFile(filename))
    {
      printf("ファイルが存在しないため、もう一度ファイル名を入力しなおしてください。\n");
    }
  } while (!isExistFile(filename));

  // ここからデータベースの削除
  char yesorno[10];
  printf("ファイル名は:%sです。本当に削除しますか？(Y/N)\n", filename);
  do
  {
    scanf("%s", yesorno);
    if (orYesNo(yesorno, "error"))
    {
      printf("YかNを入力してください。\n");
    }
  } while (!orYesNo(yesorno, "error"));

  if (orYesNo(yesorno, "yes"))
  {
    if (remove(filename) == 0)
    {
      printf("ファイルの削除に成功しました。\n");
    }
    else
    {
      printf("ファイルの削除に失敗しました。\n");
    }
  }
  else if (orYesNo(yesorno, "no"))
  {
    printf("ファイルの削除をキャンセルしました。\n");
  }
}

void showDataBase()
{
  char filename[FILENAMESIZE];
  printf("データベースの内容を表示するため、ファイル名を入力してください。\n");
  do
  {
    scanf("%s", filename);
    if (!isExistFile(filename))
    {
      printf("ファイルが存在しないため、もう一度ファイル名を入力しなおしてください。\n");
    }
  } while (!isExistFile(filename));

  // ここからデータベースの表示
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("ファイルの読み込みに失敗しました。\n");
    return;
  }

}

void searchDataBase()
{
  char filename[FILENAMESIZE];
  printf("データベースの内容を検索するため、ファイル名を入力してください。\n");
  do
  {
    scanf("%s", filename);
    if (!isExistFile(filename))
    {
      printf("ファイルが存在しないため、もう一度ファイル名を入力しなおしてください。\n");
    }
  } while (!isExistFile(filename));

  // ここからデータベースの検索
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("ファイルの読み込みに失敗しました。\n");
    return;
  }

}

void addDataBase()
{
  char filename[FILENAMESIZE];
  printf("データベースにデータを追加するため、ファイル名を入力してください。\n");
  do
  {
    scanf("%s", filename);
    if (!isExistFile(filename))
    {
      printf("ファイルが存在しないため、もう一度ファイル名を入力しなおしてください。\n");
    }
  } while (!isExistFile(filename));

  // ここからデータベースにデータを追加
  FILE *fp = fopen(filename, "a");
  if (fp == NULL)
  {
    printf("ファイルの読み込みに失敗しました。\n");
    return;
  }
}