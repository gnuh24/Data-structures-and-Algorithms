/*
4 5 6 7
6 5 2 1
9 8 7 5
1 2 0 4
-> 7 6 5 7 8 9 1
*/
#include<iostream>
using namespace std;

void input(int a[][100], int &n){
    cout <<"Enter n = "; cin >> n;
    for (int i=0; i < n; i++){
        for (int j=0; j<n; j++){
            printf("a[%d][%d] = ", i,j); cin >> a[i][j];
        }
    }
}

void output(int a[][100], int n){
    for (int i=0; i < n; i++){
        for (int j=0; j<n; j++){
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void Sort_duong_cheo(int a[][100], int n, int i, int j){
    int h,k;
    while (i < n-1 && j < n-1){
        h = i+1; k = j+1;
        while(h < n && k < n){
            if( a[i][j] > a[h][k]) swap(a[i][j], a[h][k]);
            h++; k++;
        }
        i++; j++; 
    } 
}

void Sort_matrix(int a[][100], int n){
    int i=0, j = n-1;
    while (i == 0 && j >= 0){
        Sort_duong_cheo(a,n,i,j);
        j--;
    }

    i = 1; // reset index
    j = 0; 
    while (j == 0 && i < n){
        Sort_duong_cheo(a,n,i,j);
        i++;
    }
}


int main(){
    int a[100][100], n;
    input(a,n);
    output(a,n);

    Sort_matrix(a,n);
    output(a,n);
    return 0;
}