/*
4 5 6 7 6 
6 5 2 1 8
9 8 7 5 2
1 2 0 4 10
*/
#include<iostream>
using namespace std;

void input(int *&a, int &m, int &n){
    cout <<"Enter m = "; cin >> m;
    cout <<"Enter n = "; cin >> n;
    a = new int[m*n];
    for (int i=0; i < m; i++){
        for (int j=0; j<n; j++){
            printf("a[%d][%d] = ", i,j); cin >> *(a+ (n*i+j) );
        }
    }
}

void output(int *a, int m, int n){
    for (int i=0; i < m; i++){
        for (int j=0; j<n; j++){
            cout << *(a + (n*i+j) ) <<" ";
        }
        cout << endl;
    }
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void Sort_matrix(int *a, int m, int n){
	for (int i=0; i < m*n - 1; i++){
        for (int j = i + 1; j < m*n; j++){
            if ( *(a+i) > *(a+j) ) swap(*(a+i), *(a+j));
        }
    } 
}

int main(){
    int *a, m, n;
    input(a,m,n);
    output(a,m,n);
    cout << endl;

    Sort_matrix(a,m,n);
    output(a,m,n);
    
    delete a;
    return 0;
}