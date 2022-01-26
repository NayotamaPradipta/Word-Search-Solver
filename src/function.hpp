extern int xAxis[];
extern int yAxis[];

bool isValid(std::string userinput);
void getSpec(std::string userinput, int *matrixCol, int *matrixRow, int *words);
bool searchMatrix(char *matrix, std::string word, int row, int col, int matrixRow, int matrixCol, int *numOfCheck, int *x, int *y);
void printSolution(int matrixRow, int matrixCol, int row, int col, int x, int y);
void findPattern(char *matrix, std::string word, int matrixRow, int matrixCol, int *numOfCheck, int *x, int *y);