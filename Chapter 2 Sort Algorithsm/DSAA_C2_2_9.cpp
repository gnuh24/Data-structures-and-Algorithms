
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

void Bubble_Sort_decrease(int a[], int n){
    for(int stop = 0; stop < n-1; stop ++)
        for(int j=n-1;j > stop ;j--)
            if (a[j-1] < a[j]) 
                swap(a[j-1] , a[j]);
}

void Bubble_Sort_increase(int a[], int n){
    for(int stop = 0; stop < n-1; stop ++)
        for(int j=n-1;j > stop ;j--)
            if (a[j-1] > a[j]) 
                swap(a[j-1] , a[j]);
}

void Create_Even_Odd(int a[], int even[], int odd[], int n, int &count_even, int &count_odd){
    for (int i=0; i < n; i++){
        if ( a[i] % 2 == 0 && a[i] != 0){
            even[count_even] = a[i];
            count_even++;
        }
        else if ( a[i] % 2 == 1 && a[i] != 0){
            odd[count_odd] = a[i];
            count_odd++;
        }
    }
    Bubble_Sort_increase(even, count_even);
    Bubble_Sort_decrease(odd, count_odd);
}

void Sort_Array(int a[], int even[], int odd[], int n, int count_even, int count_odd){
    int count_even_cur = 0,  count_odd_cur = 0;
    for(int i=0; i< n && count_even_cur <= count_even && count_odd_cur <= count_odd; i++){
        if ( a[i] % 2 == 0 && a[i] != 0){
            a[i] = even[count_even_cur];
            count_even_cur++;
        }
        else if ( a[i] % 2 == 1 && a[i] != 0){
            a[i] = odd[count_odd_cur];
            count_odd_cur++;
        }
    }
}

int main(){
    int a[100], n;
    int even[100], count_even = 0;
    int odd[100], count_odd = 0;
    input(a,n);
    output(a,n);
    Create_Even_Odd(a,even,odd,n,count_even,count_odd);
    output(even, count_even);
    output(odd, count_odd);
    Sort_Array(a,even,odd,n,count_even,count_odd);
    output(a,n);

    
    

    return 0;
}