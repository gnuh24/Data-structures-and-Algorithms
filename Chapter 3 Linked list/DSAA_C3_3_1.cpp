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

//Tao node
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
    int n, x; cout << "Enter n = "; cin >> n;
    //srand(time(NULL));
    for(int i = 1; i <= n; i++){
        printf("x[%d]", i); cin >> x;
        insert_tail(l, getnode( x ));
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

void noilist(list &l1, list&l2){
    l1.tail->next=l2.head;
    l1.tail->next=l2.tail;
    int s=0;
    for (NODE *p=l1.head;p!=NULL;p=p->next)
    s=s+p-> data;
    cout<<s;
}


//a)  Tim phan tu lon nhat trong danh sach
int Problem_a(list l){
    NODE* cur = l.head;
    int max = cur -> data;
    while (cur != NULL){
        if (cur -> data > max)
            max = cur -> data;
        cur = cur -> next;
    }
    return max;
}

//b) Tong cac phan tu trong danh sach
int Problem_b(list l){
    int sum = 0;
    NODE* cur = l.head;
    while (cur != NULL){
        sum += cur -> data;
        cur = cur -> next;
    }
    return sum;
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

//c) Dem xem trong danh sach co bao nhieu so nguyen to
int Problem_c(list l){
    NODE*p = l.head;
    int count = 0;
    while(p != NULL){
        if ( isPrime(p -> data) )
            count++;
        p = p -> next;
    }
    return count;
}

//d) Dem xem trong danh sach co bao nhieu so chan, le , so khong
void Problem_d(list l){
    NODE* p = l.head;
    int count_even = 0, count_odd = 0, count_zero = 0;
    while (p != NULL){
        if (p -> data == 0)
            count_zero++;
        else if (p -> data % 2 == 0)
            count_even++;
        else if (p -> data % 2 == 1)
            count_odd++;
        p = p -> next;
    }
    cout << "d) Even: " << count_even << endl;
    cout << "   Odd: " << count_odd << endl;
    cout << "   Zero: " << count_zero << endl;
}

//e) Tim xem trong danh sach co bao nhieu so bang x
int Problem_e(list l, int x){
    int count = 0;
    NODE *p = l.head;
    while(p != NULL){
        if ( p -> data == x)
            count++;
        p = p -> next;
    }
    return count;
}

//f) Tim so duong nho nhat trong danh sach
int Problem_f(list l){
    int min = -1;
    NODE* cur = l.head;
    while(cur -> data <= 0 && cur != NULL)
        cur = cur -> next;
    min = cur -> data;
    while (cur != NULL){
        if (cur -> data < min && cur -> data > 0)
            min = cur -> data;
        cur = cur -> next;
    }
    return min;
}

NODE* test(list l, int x){
    NODE* p = l.head;
    while( (p != NULL ) && (p -> data != x))
        p = p -> next;
    return p;
}

int value(list l){
    NODE* p = l.head -> next;
    int s=0;
    while(p != l.tail){
        s = s + p -> data;
        p = p -> next;
    }
    return s;
    
}

int main(){
    list best_list_ever1;
    list best_list_ever2;

    create_list(best_list_ever1);
    add_node_to_list(best_list_ever1);
    output(best_list_ever1);

    cout << value(best_list_ever1);
    //NODE *p =test(best_list_ever1,7);
    //cout<<p->next-> data; 
    // create_list(best_list_ever2);
    // add_node_to_list(best_list_ever2);
    // output(best_list_ever2);


    //noilist(best_list_ever1, best_list_ever2);
    //cout <<"a) " << Problem_a(best_list_ever) << endl;
    //cout <<"b) " << Problem_b(best_list_ever) << endl;
    //cout <<"c) " << Problem_c(best_list_ever) << endl;
    //Problem_d(best_list_ever);
    //cout <<"e) " << Problem_e(best_list_ever, 3) << endl;
    //cout <<"f) " << Problem_f(best_list_ever) << endl;

    return 0;
}


