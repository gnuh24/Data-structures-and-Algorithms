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

int find_max(int a[][100], int n, int i, int j){
    // TÌm max đường chéo 
    int max= a[i][j];
    
    while (i < n && j < n){
        if ( max< a[i][j]) max = a[i][j];
        i++; j++; 
    }
    return max;
}

void Max(int a[][100], int n){
    int i=0, j = n-1;
    while (i == 0 && j >= 0){
        cout << find_max(a,n,i,j) <<" ";
        j--;
    }

    i = 1; // reset index
    j = 0; 
    while (j == 0 && i < n){
        cout << find_max(a,n,i,j) <<" ";

        i++;
    }
}


int main(){
    int a[100][100], n;
    input(a,n);
    output(a,n);

    Max(a,n);

    return 0;
}