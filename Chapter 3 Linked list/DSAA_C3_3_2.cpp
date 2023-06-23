#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
using namespace std;

struct NODE
{
    int data;
    NODE* next;

};

struct list
{
    NODE *head;
    NODE *tail;
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
    int n; cout << "Enter n = "; cin >> n;
    srand(time(NULL));
    for(int i = 1; i <= n; i++){
        insert_tail(l, getnode( rand()%50 ));
    }
}

void output(list l){
    while(l.head != NULL){
        cout << l.head -> data << " ";
        l.head = l.head -> next;
    }
    cout << endl;
}
bool isPrime(int n){
    if (n < 2) return 0;
    int k = sqrt(n);
    for(int i=2; i <= k; i++)
        if (n % i == 0)
            return 0;
    return 1;
} 

//a) XOa phan tu dau tien khoi danh sach
void Problem_a(list &l){
    NODE* p = l.head;
    l.head = l.head -> next;
    p -> next = NULL;
    delete p;
}

//b) XOa phan tu cuoi cung khoi danh sach
void Problem_b(list &l){
    NODE* p = l.head;
    while( p -> next != l.tail)
        p = p -> next;
    delete l.tail;
    l.tail = p;
    l.tail -> next = NULL;
}

//c) XOa phan tu duoc tro boi con tro q
void Problem_c(list &l, NODE*q){
    if (q == l.head)
        Problem_a(l);
    else if (q == l.tail)
        Problem_b(l);
    else{
        NODE* p = l.head;
        while (p -> next != q)
            p = p -> next;
        p -> next = q -> next;    
        q -> next = NULL;
        delete q;
    }
}

//d) Xoa phan tu phia truoc phan tu duoc con tro q tro toi
void Problem_d(list &l, NODE* q){
    if (q == l.head) 
        return;
    if (l.head -> next == q)
        Problem_a(l);
    else{
        NODE* p = l.head;
        while(p -> next -> next != q){
            p = p -> next;
        } 
        NODE* temp = p -> next;
        p -> next = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
}

//e) Xoa phan tu co gia tri k
void Problem_e(list &l, int k){
    if (l.head -> data == k)
        Problem_a(l);
    else if (l.tail -> data == k)
        Problem_b(l);
    else{
        NODE* p = l.head;
        while (p -> data != k)
            p = p -> next;
        Problem_c(l, p);
    }
}

//f) Xoa tat ca cac phan tu la so nguyen so
void Problem_f(list &l){
    NODE* p = l.head, *temp;
    while (p != NULL){
        if ( isPrime(p -> data)){
            Problem_c(l, p); //Xoa phan tu duoc tro boi con tro q
            p = temp -> next;
        }
        else{
            temp = p;
            p = p->next;
        }
    }
}

int main(){
    list best_list_ever;
    create_list(best_list_ever);
    add_node_to_list(best_list_ever);
    output(best_list_ever);
    
    //cout << "a) "; Problem_a(best_list_ever); output(best_list_ever);
    //cout << "b) "; Problem_b(best_list_ever); output(best_list_ever);
    //NODE* p = best_list_ever.head;
    //p = p -> next -> next -> next;
    //cout << "c) "; Problem_c(best_list_ever, p); output(best_list_ever);
    //cout << "d) "; Problem_d(best_list_ever, p); output(best_list_ever);
    //cout << "e) "; Problem_e(best_list_ever, 3); output(best_list_ever);
    cout << "f) "; Problem_f(best_list_ever); output(best_list_ever);
    return 0;
}
S

