void printAllMode(void);

// askYesNo関数
// 引数にはモードを入力(yesかno)
// 返り値はtrueかfalse
bool askYesNo(char mode[]);

// existFile関数
// 引数として与えられたファイルが存在するかどうかを判定する
// 存在する場合は戻り値がtrue、存在しない場合はfalseを返す
bool isExistFile(const char *path);


// whichOperation関数
// 第一引数に入れられた操作と、第二引数に入れられた操作が一致するかどうかを判定する
// 戻り値はture、falseになる。
bool whichOperation(char operation[], char match[]);

void createDataBase(void);

void deleteDataBase(void);

void showDataBase(void);

void searchDataBase(void);

void addDataBase(void);