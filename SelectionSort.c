/*
* Code by Cellularhacker
* Original Code from C_Crash_Course-Level2's SelectionSort_poject.c
* SelectionSort.cs
* GNU General Public License v3.0
* If you want to know more about detail process, please uncommnet the line 7 at
  "SelectionSort_Func.c"
* This application is based on text file.
*/
#include "SelectionSort.h"

int main(int argc, char* argv[]) {
    int size = 0;
    int *arr;
    int round = 0;

    if(argc != 2) { // Too less Arguments.
      printf("[Error] Too Less Arguments!\n\tusing: SelectionSort.out [ArrayFilePath]\n");
      return -1;
    }
    
    printf("\n출력할 Round 입력>> ");
    scanf("%d",&round);

    arr = openFile(argv[1], &size);
    SelectionSort(arr, size, round);
    saveFile(argv[1], arr, size);

    printf("\n");
    
    return 0;
}