#include<iostream>
#include<math.h>
using namespace std;

bool Check_Prime_Number(int n){
    if (n < 2) return false;
    int k = sqrt(n);
    for (int i=2; i <= k; i++)
        if (n % i == 0) return false;
    return true;
}

void Luu_gia_tri_cac_ptu_la_so_ngto(int a[], int b[], int n, int &count){
    for (int i=0; i < n; i++){
        if ( Check_Prime_Number( a[i] ) == true ){
            b[count] = a[i];
            count++;
        }
    }
}

void swap(long &a, long &b){ 
    a = a + b; 
    b = a - b; 
    a = a - b; 
}

void InterchangeSort(int b[], int n){ //Sap xep doi cho truc tiep
    for (int i=0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if (b[i] > b[j]) swap(b[i],b[j]);
        }
    }
}

void Prime_Sort(int a[], int b[] ,int n, int count){
    int count2 = 0;
    for (int i=0; i < n && count2 < count; i++ ) {
        if ( Check_Prime_Number( a[i] ) == true){
            a[i] = b[count2];
            count2++;
        }
    }
}

void output(int a[], int n){
    for (int i=0; i < n; i++){
        cout << a[i] <<" ";
    }
}


int main(){
    int n = 10, count = 0; 
    int a[n] = {3, 9, 10, 7, 2, 1, 3, 6 ,7 ,10 }; // Mang a: mang mau de test
    int b[n] = {}; //Mang b: Luu gia tri cac phan tu la so ngto
    Luu_gia_tri_cac_ptu_la_so_ngto(a,b,n,count);
    InterchangeSort(b,count);
    Prime_Sort(a,b,n,count);
    output(a,n);
    return 0;
}