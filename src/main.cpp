#include <iostream>
#include "function.hpp"
#include <bits/stdc++.h>


using namespace std;
int main(){
    clock_t start, end;
    string userinput;
    string output;
    char alfabet = 0;
    bool allfound = false;
    int matrixCol = 0; 
    int matrixRow = 0;
    int line = 0;
    int i = 0;
    int j = 0;
    int k = -1;
    int words;
    int numOfCheck = 0;
    int checktest = 0;
    int x = 0;
    int y = 0;
    cout << "Welcome to Word Search!\n";
    cout << "Please enter an input file: ";
    cin >> userinput;
    
    // Invalid input
    while (!isValid(userinput)){
        cout << "Invalid file name! Please input the correct file: ";
        cin >> userinput;
    }
  
    getSpec(userinput, &matrixCol, &matrixRow, &words);
    // Create 2D and 1D Array to store text file into array 
    char crossWordMatrix[matrixRow][matrixCol];
    string wordsToSearch[words];
    // Read File 
    FILE* inputFile = fopen(userinput.c_str(), "r");
    // Read crossword and store inside matrix/2D array
    while (line != matrixRow){
        alfabet = getc(inputFile);
        if (alfabet != '\n'){
            crossWordMatrix[i][j] = alfabet;
        }
        if (alfabet == '\n'){
            line++;
            i++;
            j=0;
        } else {
            if (alfabet != ' '){
                j++;
            }
        }
    }
    // Read words and store inside 1D array
    while (!feof(inputFile)){
        alfabet = getc(inputFile);
        if (alfabet != '\n'){
            wordsToSearch[k] += alfabet;
            if (alfabet == ' '){
                wordsToSearch[k].pop_back();
            }
        } else {
            k++;
        }
    }
    // Erase last character of the last word
    wordsToSearch[k].pop_back();
    // Close file
    fclose(inputFile);
    // Algoritma Brute Force 
    cout << "CrossWord Puzzle solution for " << userinput << ": \n\n";
    start = clock();
    for (int m = 0; m < words; m++){
        findPattern((char *)crossWordMatrix, wordsToSearch[m], matrixRow, matrixCol, &numOfCheck, &x, &y);
    }
    // Testing Display Array of String
    end = clock();
    double time_taken = double(end - start)/ double(CLOCKS_PER_SEC);
    cout << "Number of Checks: " << numOfCheck << "\n";
    cout << "Execution time: " << fixed << time_taken << setprecision(5) << " second(s)";
    cout << "\n";

}