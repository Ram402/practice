#include <iostream>
#include <memory>

using namespace std;

struct tree
{
    int data;
    unique_ptr<tree> left;
    unique_ptr<tree> right;
    
    tree(int d): data(d),left(nullptr),right(nullptr){}
};

void add_node(unique_ptr<tree>& root,int data)
{
    if (!(root))
        root= make_unique<tree>(data);
    if (data < root->data)
        add_node(root->left,data);
    else if (data > root->data)
        add_node(root->right,data);
}

void print(unique_ptr<tree>& root)
{
    if (!(root))
        return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void delete_node(unique_ptr<tree>& root,int data)
{
    if (!(root))
        return;
    if (data < root->data)
        delete_node(root->left,data);
    else if (data > root->data)
        delete_node(root->right,data);
    else
    {
        if(root->left == nullptr && root->right == nullptr)
            root.reset();
        else if (root->right == nullptr)
            root = move(root->left);
        else if (root->left == nullptr)
            root = move(root->right);
        else
        {
            tree* temp = root->right.get();
            while(temp->left != nullptr)
                temp = temp->left.get();
            
            root->data = temp->data;
            delete_node(root->right,temp->data);
        }
    }
}

int main()
{
    unique_ptr<tree> root;
    int option,data;
    while(1)
    {
        cout << "\n1.Add node\n2.Print Tree\n3.Delete node\n.4.Exit\nEnter the option: ";
        cin >> option;
        switch(option)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                add_node(root,data);
                break;
            case 2:
                print(root);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                delete_node(root,data);
                break;
            case 4:
                exit(0);
        }
    }
}