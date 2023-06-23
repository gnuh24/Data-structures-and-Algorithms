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
    NODE* head, *tail;
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
    int n, x; cout <<"Enter = "; cin >> n;
    srand(time(NULL));
    for(int i=1; i<= n; i++){
        insert_tail(l, getnode(rand() % 20));
    }
}

void output(list l){
    NODE* current = l.head;
    while(current != NULL){
        cout << current -> data <<" ";
        current = current -> next;
    }
    cout << endl;
}

//a) Tron 2 danh sach tang dan thanh 1 danh sach tang dan
void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}
void interchange_Sort(list &l){
    for(NODE* p = l.head; p -> next != NULL; p = p->next){
        for(NODE* q = p -> next; q != NULL; q = q -> next){
            if (p -> data > q ->data){
                swap(p->data, q->data);
            }
        }
    }
}

void Problem_a(list &l, list l1, list l2){
    NODE* cur1 = l1.head, *cur2 = l2.head;
    while(cur1 != NULL || cur2 != NULL){
        if (cur1 == NULL){
            insert_tail(l, getnode(cur2 -> data));
            cur2 = cur2 -> next;
        }
        else if (cur2 == NULL){
            insert_tail(l, getnode(cur1 -> data));
            cur1 = cur1 -> next;
        }
        else if (cur1 -> data < cur2 -> data ){
            insert_tail(l, getnode(cur1 -> data));
            cur1 = cur1 -> next;
        }
        else if (cur1 ->data > cur2 -> data){
            insert_tail(l, getnode(cur2 -> data));
            cur2 = cur2 -> next;
        }
        else {
            insert_tail(l, getnode(cur1 -> data));
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
    }
}

//b) Dung selection sort de sap xep danh sach theo thu tu giam dan
void Selection_Sort_Decrease(list &l){
    NODE* max;
    for(NODE* p = l.head;p -> next != NULL ;p = p -> next){
        max = p;
        for(NODE* q= p -> next; q != NULL; q = q -> next)
            if (q -> data > max -> data)
                max = q;
        if ( max != p)
            swap(p -> data, max -> data);
    }

}

int main(){
    list increase_list_1, increase_list_2, best_list_ever;
    
    //Tao danh sach tang dan thu 1
    create_list(increase_list_1);
    add_node_to_list(increase_list_1);
    interchange_Sort(increase_list_1);
    output(increase_list_1);
    
    //Tao danh sach tang dan thu 2
    create_list(increase_list_2);
    add_node_to_list(increase_list_2);
    interchange_Sort(increase_list_2);
    output(increase_list_2);

    //Tao list tang dan duoc tong hop tu 2 list tang dan
    create_list(best_list_ever);
    Problem_a(best_list_ever, increase_list_1, increase_list_2);
    cout << "a) ";
    output(best_list_ever);


    cout << "b) ";
    Selection_Sort_Decrease(best_list_ever);
    output(best_list_ever);


    return 0;
}