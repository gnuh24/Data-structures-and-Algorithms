#include<iostream>
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
    NODE *head = NULL, * tail = NULL; 
};

NODE* getnode(int x){
    NODE* p =new NODE;
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

void create_list(list &l){
    int n, x; cout << "Enter n: "; cin >> n;
    srand(time(NULL));
    for(int i=1; i <= n; i++){
        insert_tail(l , getnode( rand() % 5 ) );
    }
}

void output(list l){
    NODE* p = l.head;
    while(p != NULL){
        cout << p -> data <<" ";
        p = p -> next;
    }
    cout << endl;
}

void insert_head(list &l, NODE* p){
    if (l.head == NULL)
        l.head = l.tail = p;
    else{
        p -> next = l.head;
        l.head = p;
    }
}

//a) Chen 1 node co gia tri x vao dau danh sach
void Problem_a(list &l){
    int x; cout <<"Enter x: "; cin >> x;
    insert_head(l, getnode(x) );
}


//b) Moi gia tri x chi ton tai 1 node
void Delete_head(list &l){
    NODE* temp = l.head;
    l.head = l.head -> next;
    temp -> next = NULL;
    delete temp;
}

void Delete_tail(list &l){
    NODE* cur = l.head;
    while(cur -> next != l.tail)
        cur = cur -> next;
    cur -> next = NULL;
    delete l.tail;
    l.tail = cur;
}

void Delete_element(list &l, NODE*q){
    if (q == l.head)
        Delete_head(l);
    else if (q == l.tail)
        Delete_tail(l);
    else{
        NODE* p = l.head;
        while (p -> next != q)
            p = p -> next;
        p -> next = q -> next;    
        q -> next = NULL;
        delete q;
    }
}

void Problem_b(list &l){
    NODE* temp;
    for(NODE* p = l.head; p != NULL; p = p -> next){
        temp = p;
        for(NODE* q = p -> next; q != NULL; q = q -> next){
            if (p -> data == q -> data){
                Delete_element(l ,q);
                q = temp;
            }
            else
                temp = q;
        }
    }
}

int main(){
    list best_list_ever;
    create_list(best_list_ever);
    output(best_list_ever);

    Problem_a(best_list_ever);
    output(best_list_ever);

    Problem_b(best_list_ever);
    output(best_list_ever);
    return 0;
}
