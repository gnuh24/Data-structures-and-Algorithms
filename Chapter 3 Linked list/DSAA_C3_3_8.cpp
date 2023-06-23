#include<iostream>
#include<cstring>
using namespace std;
struct NODE
{
    int code;
    char *name;
    NODE* next;
};

struct list
{
    NODE* head = NULL;
    NODE* tail = NULL;
};

NODE* getnode(int x, char *s){
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p -> code = x;
    p -> name = new char [35];
    strcpy(p -> name, s);
    p -> next = NULL;
    return p;
}

void input_name(char *&s){
    s = new char [35];
    cin.getline(s, 35);
}

void insert_tail(list &l, NODE*p){
    if (l.head == NULL)
        l.head = l.tail = p;
    else{
        l.tail -> next = p;
        l.tail = p;
    }
}

void Create_list(list &l){
    int n; cout <<"Enter n: "; cin >> n;
    int x; char *s;
    for(int i=1; i<= n ;i++){
        cout << i << endl;
        cout <<"Enter code: "; cin >>x; cin.ignore();           
        cout <<"Enter name: "; input_name(s);
        insert_tail(l, getnode(x,s));
        delete [] s;
    }
}

void output(list &l){
    NODE*p = l.head; int serial = 1;
    while(p != NULL){
        cout << serial++ << endl;
        cout <<"Code: " << p -> code << endl;
        cout <<"Name: " <<p -> name << endl;
        p = p -> next;
    }
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap_name(char*&s, char *&k){
    char*temp = s;
    s = k;
    k = temp;
}

void Problem_a_sort_according_to_code(list l){
    for(NODE* p = l.head; p -> next != NULL; p = p -> next)
        for(NODE* q = p -> next; q != NULL; q = q -> next)
            if (q -> code < p -> code){
                swap(q -> code, p -> code); 
                swap_name(q -> name, p -> name); 
            }        
}

void insert_head(list &l, NODE* p){
    if (l.head == NULL)
        l.head = l.tail = p;
    else{
        p -> next = l.head;
        l.head = p;
    }
}
void insert(list &l, NODE* p, NODE* q) { //Them p vao sau q
    if (q == l.head)
        insert_head(l ,p);
    else if (q == l.tail)
        insert_tail(l, p);
    else{
        p -> next = q -> next;
        q -> next = p;
    }
}

void Problem_b(list &l){
    int x; cout << "Code: "; cin >> x; cin.ignore();
    char *s; cout <<"Enter name: ";input_name(s);
    NODE* p = l.head;
    while(x > p -> next -> code)
        p = p -> next;
    insert(l , getnode(x, s), p);
}

void delete_list(list &l){
    NODE*p = l.head;
    while(p != NULL){
        l.head = l.head -> next;
        delete[] p->name;
        delete p;
        p = l.head;
    }
}

int main(){
    list student;
    Create_list(student);
    output(student);

    Problem_a_sort_according_to_code(student);
    output(student);


    Problem_b(student);
    output(student);


    delete_list(student);
    return 0;
}