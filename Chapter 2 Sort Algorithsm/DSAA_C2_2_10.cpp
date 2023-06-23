
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void input(int a[], int &n){
    cout <<"Enter n = "; cin >> n;
    srand(time(NULL));
    for (int i=0; i < n; i++){
        a[i] = rand()%50 ; 
    }
}

void output(int a[], int n){
    for (int i=0; i < n; i++){
        cout << a[i]  <<" ";
    }
    cout << endl;
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void Bubble_Sort(int a[], int n){
    for(int stop = 0; stop < n-1; stop ++)
        for(int j=n-1;j > stop ;j--)
            if (a[j-1] < a[j]) 
                swap(a[j-1] , a[j]);
}

void k_value(int a[], int n, int k){
    int count = 0;
    for(int i=0; i<n && count < k; i++)
        if (a[i] != a[i+1]){
            cout << a[i] <<" ";
            count++;
        }
}

int main(){
    int a[100], n;
    input(a,n);
    output(a,n);
    Bubble_Sort(a,n);
    output(a,n);
    k_value(a,n,4);

    return 0;
}