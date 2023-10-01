#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
    int height;
};

struct Tree* Create(int x)
{
    struct Tree* temp=(struct Tree*)malloc(sizeof(struct Tree));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=0;
    return temp;
}

int max(int x1, int x2)
{
    //return x1>x2 ? x1:x2 ;
    if(x1>=x2) return x1;
    else return x2;
}

int Height_of_the_Node(struct Tree* node)
{
    if(node==NULL) return -1;
    int LH=Height_of_the_Node(node->left);
    int RH=Height_of_the_Node(node->right);
    return (max(LH,RH)+1);
}

int Balance_Factor(struct Tree* node)
{
    if(node==NULL) return 0;
    return ( Height_of_the_Node(node->left)-Height_of_the_Node(node->right) );
}

struct Tree* Left_Rotate(struct Tree* x)
{                                          //              x                                           y
    struct Tree* new_root=x->right;        //             / \  R                    Left Rotation    /   \      //
    x->right=new_root->left;               //           T1   y <-------new_root      ------>        x     z
    new_root->left=x;                     //                / \  R                                 / \   / \ 
    return new_root;                      //              T2   z                                  T1 T2  T3 T4
}                                         //                 /   \                                               //
                                          //                T3     T4   

struct Tree* Right_Rotate(struct Tree* z)  //                 z                                         y
{                                         //             L   / \                                       / \       //
    struct Tree* new_root=z->left;   //  new_root---------> y    T4       Right Rotation             x     z
    z->left=new_root->right;         //                L   / \             ------->                 / \    / \   //
    new_root->right=z;              //                    x   T3                                   T1 T2  T3 T4 
    return new_root;                //                   / \                                                      //
}                                  //                   T1  T2

struct Tree* Insert(struct Tree* root, int x)
{
    if(root==NULL) return Create(x);
    else if( x< root->data) root->left= Insert(root->left,  x);
    else root->right= Insert(root->right, x);
    
    int Bf= Balance_Factor(root);
    printf("Bf= %d\n", Bf);
   
    // LEFT LEFT CASE
    if(Bf>1 && x<root->left->data) root= Right_Rotate(root);
    // LEFT RIGHT CASE
    if(Bf>1 && x>root->left->data)
    {
        root->left=Left_Rotate(root->left);
        root=Right_Rotate(root);
    }
    // RIGHT RIGHT CASE
    if(Bf<-1 && x>root->right->data) root=Left_Rotate(root);
    // RIGHT LEFT CASE
    if(Bf<-1 && x<root->right->data)
    {
        root->right=Right_Rotate(root->right);
        root=Left_Rotate(root);
    }

    return root;
}

void Inorder(struct Tree* root)
{
    if(root==NULL) return ;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

int main()
{
    struct Tree* root=NULL;
    root=Insert(root, 9);       
    root=Insert(root, 7);       Inorder(root);
    root=Insert(root, 4);       Inorder(root);
    printf("\n%d\n", root->right->data);
    root=Insert(root, 3);       Inorder(root);
    root=Insert(root, 5);       Inorder(root);
    root=Insert(root, 6);       Inorder(root);   
    printf("\n%d\n", root->right->right->data);

    return 0;
}