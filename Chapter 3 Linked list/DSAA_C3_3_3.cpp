#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
using namespace std;
struct NODE
{
    int data;
    NODE* next;
};

struct list
{
    NODE* head, * tail;
};

void create_list(list &l){
    l.head = l.tail = NULL;
}

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

void add_node_to_list(list &l){
    int n, x; cout <<"Enter n = "; cin >> n;
    srand(time(NULL));
    for(int i=1; i <= n; i++){
        insert_tail(l, getnode( rand() % 50 ) );
    }
}

void output(list l){
    NODE* cur = l.head;
    while(cur != NULL){
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << endl;
}
//a) Tao danh sach moi chi chua cac phan tu la so nguyen to cua danh sach cu
bool isPrime(int n){
    if (n < 2)
        return false;
    int k = sqrt(n);
    for(int i = 2; i <= k; i++)
        if(n % i == 0)
            return false;
    return true;
}
void Problem_a(list l1, list &l2){
    NODE* current = l1.head;
    while(current != NULL){
        if ( isPrime(current -> data) )
            insert_tail(l2 , getnode(current -> data) );
        current = current -> next;
    }
}

//b) Tach danh sach l thanh 2 danh sach chua 1 danh sach chua toan so chan, mot danh sach chua toan so le
void Problem_b(list l, list &even, list &odd){
    NODE* current = l.head;
    while ( current != NULL){
        if ( current -> data % 2 == 0)
            insert_tail(even, getnode(current -> data));
        else
            insert_tail(odd, getnode(current -> data));
        current = current -> next;
    }
}

int main(){
    list best_list_ever;
    create_list(best_list_ever);
    add_node_to_list(best_list_ever);
    output(best_list_ever);

    list prime_list;
    create_list(prime_list);
    Problem_a(best_list_ever, prime_list);
    output(prime_list);

    list even_list, odd_list;
    create_list(even_list);     
    create_list(odd_list);
    Problem_b(best_list_ever, even_list, odd_list);
    output(even_list);
    output(odd_list);


    return 0;
}