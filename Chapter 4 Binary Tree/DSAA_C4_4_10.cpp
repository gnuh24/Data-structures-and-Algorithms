#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;

struct NODE
{
    int data;
    NODE* right;
    NODE* left;
};
typedef NODE* tree;

void CreateRoot(tree &root, int x){
    if (root != NULL){
        if (root->data < x)
            CreateRoot(root -> right, x);
        else
            CreateRoot(root -> left, x);
    }
    else{
        root = new NODE;
        root -> data = x;
        root -> left = root -> right = NULL;
    }
}

void CreateTree(tree &root){
    int n, x; cout <<"Enter n: "; cin >> n;
    for(int i=0; i<n; i++){
        printf("x[%d] = ", i+1); cin >> x;
        CreateRoot(root, x);
    }
}

void LNR(tree root){
    if (root != NULL){
        LNR(root -> left);
        cout << root -> data <<" ";
        LNR(root -> right);
    }
}
void NLR(tree root){
    if (root != NULL){
        cout << root -> data << " ";
        NLR(root -> left);
        NLR(root -> right);
    }
}
void LRN(tree root){
    if (root != NULL){
        LRN(root -> left);
        LRN(root -> right);
        cout << root -> data << " ";
    }
}
//a) Tim chieu cao cua cay
int Problem_a_HeightOfTree(tree root){
    if (root == NULL)
        return 0;
    int HeightOfLeftBranch = Problem_a_HeightOfTree(root -> left);
    int HeightOfRightBranch = Problem_a_HeightOfTree(root -> right);

    if (HeightOfLeftBranch > HeightOfRightBranch )
        return HeightOfLeftBranch + 1;
    
    return HeightOfRightBranch  + 1;
}

//b) Tim do lech cua cay
int Problem_b(tree root){}

//c) Xoa mot node co gia tri x trong cay
tree FindPreNodeOfTarget(tree root, tree NODE){
    tree cur = root;
    while ( cur -> left != NODE && cur -> right != NODE && cur != NULL){
        if (cur -> data < NODE -> data)
            cur = cur -> right;
        else
            cur = cur -> left;
    }
    return cur;
}

void DeleteNode(tree root, tree Target){ 
    //Truong hop 1: Target la NODE la
    if (Target -> left == NULL && Target -> right == NULL)
        tree temp = FindPreNodeOfTarget(root, Target);
        if (Target -> data > temp -> data)
            temp -> right = NULL;
           
        else
            temp -> left = NULL;

        delete Target;
        Target = temp; //Sau khi xoa Target thi con tro Targer se tro ve node cha cua chinh no
    //Truong hop 2: Target la NODE co 2 NODE con
    else if ( )
    //Truong hop 3: Target la NODE co 1 NODE con
    else if ( Target -> left != NULL || Target -> right != NULL ){
        tree temp = FindPreNodeOfTarget(root, Target);
        if (temp -> right == Target){
            
        }
        if (temp -> left == Target){

        }
    }

            

    

}

//d) Xoa so nguyen to khoi cay
bool isPrime(int n){
    int k = sqrt(n);
    for(int i=0; i<=k; i++){
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
void Problem_d_DeletePrimeNumber(tree root){

}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    tree BinaryTree = NULL;
    CreateTree(BinaryTree);
    NLR(BinaryTree);    cout << endl;
    LNR(BinaryTree);    cout << endl;
    LRN(BinaryTree);    cout << endl;
    cout << "a) Chieu cao cua cay: " << Problem_a_HeightOfTree(BinaryTree) << endl;
    return 0;
}