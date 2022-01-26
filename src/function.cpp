#include <iostream>
#include "function.hpp"

int xAxis[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int yAxis[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

bool isValid(std::string userinput){
    return (userinput == "small.txt" || userinput == "medium1.txt" || userinput == "medium2.txt" ||userinput == "medium3.txt" || userinput == "medium4.txt" || userinput == "medium5.txt" || userinput == "hard1.txt" || userinput == "hard2.txt");
}
void getSpec(std::string userinput, int *matrixCol, int *matrixRow, int *words){
    // Get array and matrix size depending on the user input
    if (userinput == "small.txt"){ // P.S. Small Crossword Puzzle saya ambil contoh dari spesifikasi tucil karena tidak ada di web pada pdf file
        *matrixCol = 8;
        *matrixRow = 7;
        *words = 8;
    }
    else if (userinput == "medium1.txt" || userinput == "medium2.txt" || userinput == "medium3.txt" || userinput == "medium4.txt" || userinput == "medium5.txt"){ // Medium berukuran 22x20
        *matrixCol = 15;
        *matrixRow = 15;
        *words = 15;
    }
    else { // Large berukuran 34x32
        *matrixCol = 22;
        *matrixRow = 20;
        *words = 20;
    }
}


bool searchMatrix(char *matrix, std::string word, int row, int col, int matrixRow, int matrixCol, int *numOfCheck, int *x, int *y){
    // Core/Main function to search and find the words inside the matrix 
    // If first letter is not equal -> break 
    if (*(matrix+row*matrixCol+col) != word[0]){
        return false;
    }
    int path;
    for (path = 0; path < 8; path++){
        int a; 
        int ra = row + xAxis[path];
        int ca = col + yAxis[path];
        for (a = 1; a < word.length(); a++){
            if (ra >= matrixRow || ca >= matrixCol || ra < 0 || ca < 0){
                *numOfCheck += 1;
                break;
            }
            if (*(matrix+ra*matrixCol+ca) != word[a]){
                *numOfCheck += 1;
                break;
            }
            ra += xAxis[path];
            ca += yAxis[path];
        }
        if (a == word.length()){
            *x = xAxis[path];
            *y = yAxis[path];
            return true;
        }
    }
    return false; 
}
void printSolution(std::string word, int matrixRow, int matrixCol, int row, int col, int x, int y){
    // This function is used to display the solution in a matrix form (Assume that the word has already been found)
    char matrixSolution[matrixRow][matrixCol];
    for (int i = 0; i < matrixRow; i++){
        for (int j = 0; j < matrixCol; j++){
            matrixSolution[i][j] = '-';
        }
    }
    matrixSolution[row][col] = word[0];
    for (int i = 1; i < word.length(); i++){
        matrixSolution[row+x*i][col+y*i] = word[i];
    } 
    for (int i = 0; i < matrixRow; i++){
        for (int j = 0; j < matrixCol; j++){
            std::cout << matrixSolution[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
void findPattern(char *matrix, std::string word, int matrixRow, int matrixCol, int *numOfCheck, int *x, int *y){
    for (int row = 0; row < matrixRow; row++){
        for (int col = 0; col < matrixCol; col++){
            if (searchMatrix(matrix, word, row, col, matrixRow, matrixCol, numOfCheck, x, y)){
                printSolution(word, matrixRow, matrixCol, row, col, *x, *y);
            }
            *numOfCheck += 1; 
        }
        *numOfCheck += 1;
    }
}