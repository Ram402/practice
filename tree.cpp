#include <iostream>
using namespace std;
struct tree
{
    int data;
    tree* left;
    tree* right;
    tree(int data) : data(data),left(nullptr),right(nullptr){}
};

tree* add(tree* root,int data)
{
    if(root==nullptr)
    return new tree(data);
    if(data < root->data)
    root->left = add(root->left,data);
    else if(data > root->data)
    root->right = add(root->right,data);
    else
    cout<<"Duplicates ont allowed\n";
    return root;
}
void print(tree* root)
{
    if(root == nullptr)
    return;
    print(root->left);
    cout<<" -> "<<root->data ;
    print(root->right);

}
tree* findmin(tree* root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root;
}
tree* del(tree* root,int key)
{
    if(root == nullptr)
    return root;
    if(key < root->data)
    root->left = del(root->left,key);
    else if(key > root->data)
    root->right = del(root->right,key); 
    else{
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr)
        {
            tree* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            tree* temp = root->left;
            delete root;
            return temp;
        }
        else{
            tree* temp = findmin(root->right);
            root->data = temp->data;
            root->right = del(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
    tree* root = nullptr;
    int opt,data;
    while(1)
    {
        cout<<"\n1.add\n2.print\n3.delete\n4.exit\nchoose the option : ";
        cin>>opt;
        switch(opt)
        {
            case 1 : cout<<"Enter data : ";
            cin>>data;
            root = add(root,data);
            break;
            case 2 : cout<<"Data : ";
            print(root);
            break;
           case 3 : 
           cout<<"Enter key : ";
            cin>>data;
            del(root,data);
           break;
            case 4 : return 0;
        }
    }
}