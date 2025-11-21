#include <iostream>
#include <string>
using namespace std;

class tree
{
    public:
    string vechicle_part;
    tree* left;
    tree* right;
    tree(){}
    tree(string name) :vechicle_part(name),left(nullptr),right(nullptr){}

    tree* insert(tree* root,string nm)
    {
        if (!(root))   return new tree(nm);
        if (nm < root->vechicle_part)   
            root->left = insert(root->left,nm);
        if (nm > root->vechicle_part)   
            root->right = insert(root->right,nm);
        return root;
    }

    void display_inorder(tree* root)
    {
        if (!(root))    return;
        display_inorder(root->left);
        cout << root->vechicle_part << "->";
        display_inorder(root->right);
    }

    void display_preorder(tree* root)
    {
        if (!(root)) return;
        cout << root->vechicle_part  << "->";
        display_preorder(root->left);
        display_preorder(root->right);
    }

    void display_postorder(tree* root)
    {
        if (!(root)) return;
        display_postorder(root->left);
        display_postorder(root->right);
        cout << root->vechicle_part  << "->";
    }
};

int main()
{
    int opt;
    tree* root= nullptr;
    string nm;
    while(1)
    {
        cout << "\n1.Insert Vehicle Part\n2.Dislay Parts in inorder(Alphabetical)\n3.Display parts in preorder(System scan)\n4.Display parts in postorder(Maintenance scan)\n5.Exit\n\nEnter the option: " ;
        cin >> opt;
        switch(opt)
        {
            case 1:
                {
                    cout << "Enter the part name: ";
                    getchar();
                    getline(cin,nm);
                    root = root->insert(root,nm);
                    break;
                }
            case 2:
                {
                    cout << "Alphabetical order:- ";
                    root->display_inorder(root);
                    break;
                }
            case 3:
                {
                    cout << "System scan:- ";
                    root->display_preorder(root);
                    break;
                }
            case 4:
                {
                    cout << "Maintenance scan:- ";
                    root->display_postorder(root);
                    break;
                }
            case 5:
                exit(0);
                break;
            default:
                cout << "Invalid option Enter again"; 
        }
    }
}
