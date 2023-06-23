#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
struct NODE
{
    char *name;
    long long area;
    long long population;
    NODE* next;
};

struct list
{
    NODE* head, *tail;
};

void create_list(list &l){
    l.head = l.tail = NULL;
}

void input_name(char *&s){
    if (s == NULL)
        s = new char[256];
    cout << "Enter string: "; cin.getline(s, 256);
}

//b) Cai cac thao tac co ban cho danh sach lien ket don cac tinh (them, sua, xoa, duyet)

//Tạo node
NODE* getnode(char *s, long long area, long long population){
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p -> name = new char [256];
    strcpy(p -> name, s);
    p -> area = area;
    p -> population = population;
    p -> next = NULL;
    return p;
} 


//Them node vao cuoi danh sach
void insert_tail(list &l, NODE* p){
    if (l.head == NULL)
        l.head = l.tail = p;
    else{
        l.tail -> next = p;
        l.tail = p;
    }
}


//Tao list co n phan tu
void Problem_b_add_node_to_list(list &l){
    int n; cout << "Enter n: "; cin >> n; cin.ignore();
    long long area, population;
    char *name;
    for(int i=1; i <= n ;i++){
        printf("node [%d]: ", i); 
        cout << "Name: "; input_name(name);
        cout << "Area: "; cin >> area;
        cout << "Population: "; cin>> population; cin.ignore();
        insert_tail(l, getnode(name, area, population));
    }
}


//Sua thong tin tren node q
void Problem_b_edit_in4(list &l, NODE *q){
    cout << "Chon thong tin ban muon sua: \n 1. Name \n 2.Area \n 3.Population"; 
    int choice; cin >> choice; cin.ignore();
    if (choice == 1){
        delete q -> name;
        input_name(q -> name);
    }
    else if (choice == 2){
        cout <<"Nhập diện tích mới bạn muốn thay đổi: "; cin >>  q -> area ;
    }
    else if (choice == 3){
        cout <<"Nhập dân số mới bạn muốn thay đổi: "; cin >>  q -> population ;
    }

}

//Xoa dau
void delete_head(list &l){
    NODE* p =l.head;
    l.head = l.head -> next;
    p -> next = NULL;
    delete p;
}

//Xoa duoi
void delete_tail(list &l){
    NODE* p = l.head;
    while (p -> next != l.tail)
        p = p-> next;
    delete l.tail;
    l.tail = p;
    l.tail -> next = NULL;
}

//Xoa tong quat 
void Problem_b_delete_elements(list &l, NODE* q){
    if (q == l.head)
        delete_head(l);
    else if (q == l.tail)
        delete_tail(l);
    else{
        NODE* p = l.head;
        while (p -> next != q)
            p = p -> next;
        p -> next = q -> next;
        q -> next = NULL;
        delete q;
    }
}

//Xóa list
void delete_list(list &l){
    NODE* p = l.head;
    while(p != NULL){
        l.head = p -> next;
        delete [] p -> name;
        delete p;
        p = l.head;
    }
}

//Duyệt
void output(list l){
    NODE*p = l.head;
    for(int i=1; p != NULL; i++){
        cout << i << endl;
        cout << "Name: " << p -> name << endl;
        cout << "Area: " << p -> area << endl;
        cout << "Population: " << p -> population << endl;
        p = p -> next;
    }
}

//c)Tinh tong dien tich
long long Problem_c(list l){
    NODE* p = l.head;
    long long sum = 0;
    while (p != NULL) {
        sum += p -> area;
        p = p -> next;
    }
    return sum;
} 

//d) Tim dia chi cua node lon nhat trong danh sach
NODE* Problem_d_the_largest_area(list l){
    NODE* max = l.head;
    for(NODE* p = l.head -> next; p != NULL; p = p-> next)
        if (p -> area > max ->area)
            max = p;
    return max;
}

//e) Tim tinh co dan so lon nhat
char* Problem_e(list l){
    NODE* max = l.head;
    for(NODE* p = l.head -> next; p != NULL; p = p-> next)
        if (p -> population > max ->population)
            max = p;
    return max -> name;
}

//f) Sap xep danh sach tang dan theo dien tich
void Problem_f(list l){
    for(NODE* p = l.head; p -> next != NULL; p = p-> next){
        for(NODE* q = p -> next; q != NULL; q = q-> next){
            if (p -> area > q -> area){
                swap(p->name, q->name);
                swap(p->area, q->area);
                swap(p->population, q->population);
            }
        }
    }
}

int main(){
    list Province_List;
    SetConsoleOutputCP(CP_UTF8);
    create_list(Province_List);
    Problem_b_add_node_to_list(Province_List);
    output(Province_List);
   
   //Problem_b_edit_in4(Province_List, Province_List.head);
   
    cout << "c) Tổng diện tích: " << Problem_c(Province_List) << endl;
    cout << "d) Tên tỉnh có diện tích lớn nhất: " << Problem_d_the_largest_area(Province_List) -> name << endl;
    cout << "e) Tên tỉnh có dân số nhiều nhất: " << Problem_e(Province_List) << endl;
    Problem_f(Province_List);
    output(Province_List);
   
   
   
    delete_list(Province_List);
    return 0;
}