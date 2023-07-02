#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define INTARRLEN 10
#define INTPTRARRLEN 2
typedef struct fat {
    int** pptr;
    int len;
    long sum;
} FAT;

FAT* createFAT(){
    FAT *ptr;
    ptr = (FAT *)malloc(sizeof(FAT));
    ptr->pptr = (int **) malloc(INTPTRARRLEN * sizeof(int *));
    for(int i=0; i<INTPTRARRLEN; i++)
        ptr->pptr[i]=NULL;
    ptr->len = ptr->sum = 0;
    return ptr;
}

long sum(FAT* fat){
    int *arr;
    long returnSum = 0;
    int ptrIndex = (fat->len-1) / INTARRLEN;
    int arrIndex = (fat->len-1) % INTARRLEN;

    for(int j=0; j<=ptrIndex; j++){
        int len;
        if(j== ptrIndex) len=arrIndex+1;
        else len = INTARRLEN;
        
        arr = fat->pptr[j];
        cout<<*arr<<endl;
        for(int i=0; i<len; i++) {
            returnSum+=arr[i];
        }
    }
    return returnSum;
}

int main(){
    int arr1[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10]={11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    FAT* fatt=createFAT();
    fatt->pptr[0]=arr1;
    fatt->pptr[1]=arr2;
    fatt->len=20;
    fatt->sum=210;
    cout<<sum(fatt)<<" "<<fatt->sum;
    return 0;
}


