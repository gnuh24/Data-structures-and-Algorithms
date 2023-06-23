#include<iostream>
#include<math.h>
#include<windows.h>

using namespace std;
struct point{
    float x;
    float y;
};

struct NODE{
    point vertex; //Dinh cua da giac loi
    NODE* next;
};

struct list{
    NODE *head = NULL, *tail = NULL;
};

NODE* getnode(float x, float y){ //Moi node tuong ung voi moi dinh cua da giac loi
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p -> vertex.x = x;
    p -> vertex.y = y;
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

void Problem_a_add_node_to_list(list &l, int &n){
    cout <<"Nhap so dinh cua da giac loi: "; cin >> n; //So dinh cua da giac loi
    float x, y;
    for(int i=1; i<= n; i++){
        printf("Enter x%d = ", i); cin >> x;
        printf("Enter y%d = ", i); cin >> y;
        insert_tail(l, getnode(x,y) );
    }
}

void output(list l){
    NODE *p = l.head;
    while(p != NULL){
        printf("(%.1f, %.1f) \n", p -> vertex.x, p -> vertex.y);
        p = p -> next;
    }
}

double Distance(NODE* A, NODE* B){
    return sqrt( pow(B -> vertex.x - A -> vertex.x, 2) + pow(B -> vertex.y - A -> vertex.y, 2) );
}

double Problem_b_Perimeter(list l, int n){
    NODE* p = l.head, *q = l.head -> next;
    double Perimeter = 0;
    for(int i=0; i<n; i++){
        if (q == NULL)
            q = l.head;
        Perimeter += Distance(p, q);
        p = p -> next;
        q = q -> next;
    }
    return Perimeter;
}

double Heron(NODE*A, NODE*B, NODE*C){
    double a = Distance(A,B);
    double b = Distance(B,C);
    double c = Distance(C,A);
    double p = ( a + b + c ) / 2;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

double  Problem_c_Area(list l){
    NODE* p = l.head -> next;
    NODE* q = p -> next;
    double area = 0;
    while (q != NULL)
    {
        area += Heron(l.head, p ,q);
        p = p -> next;
        q = q -> next;
    }
    return area;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int n;
    list ConvexPolygon;
    Problem_a_add_node_to_list(ConvexPolygon, n);
    output(ConvexPolygon);
    cout << "b) " << Problem_b_Perimeter(ConvexPolygon, n) << endl;
    cout << "c) " << Problem_c_Area(ConvexPolygon) << endl;

    return 0;
}