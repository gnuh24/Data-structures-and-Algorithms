#include<iostream>
#include<math.h>
#include<ctime>
#include<cstdlib>
using namespace std;
struct NODE{
    int data;
    NODE* next;
};

struct list
{
    NODE *head = NULL, *tail = NULL;
};

NODE* getnode(int x){
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p -> data = x;
    p -> next = NULL;
    return p;
}

void insert_tail(list &l, NODE* p){
    if (l.head == NULL)
        l.head = l.tail = p;
    else{
        l.tail -> next = p;
        l.tail = p;
    }
}

void add_node(list &l){
    int n; cout << "Enter n: "; cin >> n;
    srand(time(NULL));
    for(int i=1; i<= n; i++){
        insert_tail(l, getnode( rand() %10 ));
    }
}

void output(list l){
    NODE* p = l.head;
    while(p != NULL){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

bool isPrime(int n){
    if (n < 2) 
        return false;
    int k = sqrt(n);
    for(int i=2; i <= k; i++)
        if (n % i == 0)
            return false;
    return true;
}

int Problem_a_count_Prime(list l){
    int count = 0;
    NODE* p = l.head;
    while(p != NULL){
        if( isPrime(p -> data) )
            count++;
        p = p -> next;
    }
    return count;
}

void Problem_b_count_even_3(list l, list &ll){
    NODE*p = l.head;
    while(p != NULL){
        if (p -> data % 2 == 0 || p -> data %3 == 0)
            insert_tail(ll, getnode(p->data) );
        p = p ->next;
    }
}

void Problem_c_SelectionSort(list l){
    NODE* min;
    for(NODE* p = l.head; p -> next != NULL; p = p ->next){
        min = p;
        for(NODE* q = p -> next; q != NULL; q = q -> next){
            if (q -> data < min -> data){
                min = q;
            }
        }
        if (min != p){
            swap(min->data, p->data);
        }
    }
}

int main(){
    list number, even3;
    add_node(number);
    output(number);
    Problem_b_count_even_3(number, even3);
    output(even3);

    Problem_c_SelectionSort(number);
    output(number);
    return 0;
}