/*
* Copyright (c) Cellularahcker
* SelectionSort.h
* GNU General Public License v3.0
*/
#ifndef SelectionSort_H
#define SelectionSort_H

void printArr(int *p, int size);
void SelectionSort(int *p, int size, int round);
int *openFile(char *filename, int *arr_size);
void saveFile(char *filename, int *p, int size);

#endif