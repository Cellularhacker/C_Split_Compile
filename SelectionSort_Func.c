/*
* Copyright (c) Cellularhacker
* SelectionSort_Func.c
* GNU General Public License v3.0
*/
//If you want to know more about detail process, please uncommnet the below line.
//#define DEBUG 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int *p, int size) {
    int i;

    #ifdef DEBUG
    printf("printArr Called\n"); //DEUBG CODE
    #endif

    for(i=0;i<size;i++) printf("%d ",p[i]);

    #ifdef DEBUG
    /rintf("printArr END\n"); //DEBUG CODE
    #endif

    printf("\n");    
}

void SelectionSort(int *p, int size, int round) {
    int i,j,tmp,index;

    #ifdef DEBUG
    printf("\nSelectionSort Called! \n\tsize=%d, round:%d\n",size,round); //DEBUG CODE
    #endif

    for(i=0;i<size-1;i++) {
        index = i;
        for(j=i+1;j<size;j++) {
            #ifdef DEBUG
            printf("\tㄴNow calling if(p[j] < p[index] )...\n"); //DEBuG CODE
            printf("\t=> i:%d, j:%d, index:%d\n",i,j,index); //DEBUG CODE
            printf("\t=> p[i]:%d, p[j]:%d, p[index]:%d\n",p[i],p[j],p[index]); //DEBUG CODE
            #endif

            if( p[j] < p[index] ) index = j;
        }
        #ifdef DEBUG
        printf("\tㄴNow swaping p[index] <--> p[i]<\n"); //DEBUG CODE
        #endif

        tmp = p[index];
        p[index] = p[i];
        p[i] = tmp;

        #ifdef DEBUG
        printf("Calling printArr\n"); //DEUBG CODE
        printf("[%d Round]: ",i); printArr(p, size); //DEUBG CODE
        #endif

        if(i==round) { printf("[%d Round]: ",i); printArr(p, size); }
    }
    #ifdef DEBUG
    printf("SelectionSort END\n"); //DEUBG CODE
    #endif
}

int *openFile(char *filename, int *arr_size) {
    FILE *fp;
    int index, fSize=0, data;
    int *tmp_arr, *p;
    int i=0;
    
    #ifdef DEBUG
    printf("openFile() Called!\n"); //DEBUG CODE
    #endif
    
    fp = fopen(filename, "r"); //파일을 읽기전용으로 열기
    fseek(fp, 0L, SEEK_END); //파일 크기를 구하기 위해 맨 뒤로 이동
    fSize = ftell(fp);  //파일 크기를 기록
    fseek(fp, 0L, SEEK_SET); //다시 커서를 앞으로 이동
    
    #ifdef DEBUG
    printf("\tfilename: %s, fSize: %d\n",filename,fSize); //DEBUG CODE
    #endif
    
    tmp_arr = (int*) malloc( sizeof(int)*fSize );    

    #ifdef DEBUG
    printf("[Before fscanf]\n"); //DEBUG CODE
    #endif
    
    printf("[%s]=> ",filename);
    while(fscanf(fp, "%d ", &data) != EOF) {
        tmp_arr[i] = data;
        printf("%d ",tmp_arr[i]);
        i++;
    }

    printf("\n");

    *arr_size = i;
    p = (int*) malloc( sizeof(int)*(*arr_size));
    for(i=0;i<(*arr_size);i++)
        p[i] = tmp_arr[i];
    free(tmp_arr);
    
    fclose(fp);

    return p;    
}


void saveFile(char *filename, int *p, int size) {
    FILE *fp;
    int i, j;
    char save_filename[strlen(filename)+4];
    char *str1;
    
    #ifdef DEBUG
    printf("saveFile Called\n"); //DEBUG CODE
    #endif

    for(i=sizeof(filename)-2;i>=0;i--) {
        #ifdef DEBUG
        printf("\tㄴi:%d, filename[i]:%c\n",i,filename[i]); //DEBUG CODE
        #endif

        if(filename[i] == '.') {
            str1 = (char*) malloc(i);
            for(j=0;j<i;j++) str1[j] = filename[j];

            #ifdef DEBUG
            printf("\tㄴstrcpy(str1, filename); has been completed!\n"); //DEBUF CODE
            printf("\tㄴi:%d, sizeof(*str1):%lu, str1:%s, filename:%s\n",i,sizeof(*str1),str1,filename); //DEBUG CODE
            #endif
            
            strcpy(save_filename, str1);

            #ifdef DEBUG
            printf("\tㄴstr1:%s, save_filename:%s\n",str1,save_filename);//DEBUF CODE
            #endif

            strcat(save_filename, "_out.txt");

            #ifdef DEBUG
            printf("\tㄴstr1:%s, save_filename:%s\n",str1,save_filename);//DEBUF CODE
            #endif

            break;
        }
    }
    fp = fopen(save_filename, "w+");
    for(i=0;i<size;i++) fprintf(fp, "%d ",p[i]);
    fprintf(fp, "\n",p[i+1]);
    
    fclose(fp);

    printf("Result has been successfully saved in [%s] !\n",save_filename);
    free(p);
    free(str1);

    #ifdef DEBUG
    printf("saveFile END\n"); //DEBUG CODE
    #endif
}
