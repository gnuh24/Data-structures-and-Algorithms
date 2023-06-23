#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
void swap(long &a, long &b);
void output(int a[], int n);

void InterchangeSort(int a[], int n);
void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void BubbleSort(int a[], int n);




int main(){
    //SetConsoleOutputCP(CP_UTF8);

    int a[10] = {9,5,6,3,10,2,30,7,14,12}; // Mảng ngẫu nhiên
    int b[10] = {100, 98 ,50, 34, 29, 28, 24, 12, 10, 2}; // Mảng giảm
    int c[10] = {1,2,3,4,5,6,7,8,9,10}; //Mảng tăng
    //input(a,n);
    
    InterchangeSort(a,10); 
    InterchangeSort(b,10); 
    InterchangeSort(c,10); 
    
    //SelectionSort(a,10);
    //SelectionSort(b,10);
    //SelectionSort(c,10);

    //InsertionSort(a,10);
    //InsertionSort(b,10);
    //InsertionSort(c,10);

    //BubbleSort(a,10);
    //BubbleSort(b,10);
    //BubbleSort(c,10);

   
    
    output(a,10);
    output(b,10);
    output(c,10);

    return 0;
}

void output(int a[], int n){
    for (int i=0; i < n; i++){
        printf("a[%i] = %i \n", i, a[i]);
    }
}

void swap(long &a, long &b){ 
    a = a + b; 
    b = a - b; 
    a = a - b; 
}

void InterchangeSort(int a[], int n){
    for (int i=0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]) swap(a[i],a[j]);
        }
    }
}

void SelectionSort(int a[], int n){
    for (int i=0; i < n-1; i++){
        int index_min = i;
        for (int j = i + 1; j < n; j++){
            if ( a[index_min] > a[j]) {
                index_min = j;                
            }
        }
        if (index_min != i){
            swap(a[i], a[index_min]);
        }
    }
}

void InsertionSort(int a[], int n){
    int index;
    for (int i=1; i < n; i++){
        index = i;
        for (int j= i-1; j >= 0; j--){
            if ( a[index] < a[j] ) {
                swap(a[index], a[j]);
                index = j;
            }
        }
    }
}

void BubbleSort(int a[], int n){
    for (int stop = 0; stop < n-1; stop++){
        for (int i=n-1; i > stop ;i--){
            if ( a[i-1] > a[i]){
                swap(a[i-1] , a[i]);
            }
        }
    }
}


