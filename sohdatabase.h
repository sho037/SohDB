void printAllMode(void);

// orYesNo関数
// 引数の値がYes(y)かNo(n)かを判定する第二引数に判定する文字を入れる
// 返り値はtureかfalse
bool orYesNo(char yesorno[], char match[]);

// existFile関数
// 引数として与えられたファイルが存在するかどうかを判定する
// 存在する場合は戻り値がtrue、存在しない場合はfalseを返す
bool isExistFile(const char *path);


// whichOperation関数
// 第一引数に入れられた操作と、第二引数に入れられた操作が一致するかどうかを判定する
// 戻り値はture、falseになる。
bool whichOperation(char operation[], char match[]);

void addDataBase();

void updateDataBase();

void serchDataBase();