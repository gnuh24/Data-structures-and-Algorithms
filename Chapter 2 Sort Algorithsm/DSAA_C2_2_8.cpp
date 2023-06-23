#include<iostream>
using namespace std;

void swap(int &a, int &b){ 
    a = a + b; 
    b = a - b; 
    a = a - b; 
}

void QuickSort(int a[], int left, int right){
    if (left >= right) return;
    int x,i,j;
    x = a[(right+left)/2];
    do{
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    } while(i < j);
    if (left < j) QuickSort(a,left,j);
    if (i < right) QuickSort(a,i,right); 
}

void output(int a[], int n){
    for (int i=0; i < n; i++){
        cout << a[i] <<" ";
    }
    cout << endl;
}

int main(){
    int n = 10;
    int a[] = {3, 5, 6, 200, 15, 13, 4 ,2 ,11 ,56};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int c[] = {10,9,8,7,6,5,4,3,2,1};
    QuickSort(a,0,n-1);
    QuickSort(b,0,n-1);
    QuickSort(c,0,n-1);
    output(a,n);
    output(b,n);
    output(c,n);

    return 0;
}