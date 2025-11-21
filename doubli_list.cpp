#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* prev;
    Node* next;
};
 
Node* create_node() {
    int data;
    cout << "Enter the data: ";
    cin >> data;
    Node* new_node = new Node{data, nullptr, nullptr};
    if (new_node == nullptr)
        return nullptr;
    else
        return new_node;
}
 
void insert_at_first(Node** head) {
    Node* new_node = create_node();
    if (new_node == nullptr) {
        cout << "Node creation failed" << endl;
        return;
    }
    new_node->next = *head;
    if (*head != nullptr)
        (*head)->prev = new_node;
    *head = new_node;
}
 
void insert_at_last(Node** head) {
    Node* new_node = create_node();
    if (new_node == nullptr) {
        cout << "Node creation failed" << endl;
        return;
    }
    if (*head == nullptr) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}
 
void insert_at_position(Node** head) {
    int pos;
    cout << "Enter the position to insert (starting from 1): ";
    cin >> pos;
    if (pos <= 0) {
        cout << "Invalid position." << endl;
        return;
    }
    Node* new_node = create_node();
    if (new_node == nullptr) {
        cout << "Node creation failed." << endl;
        return;
    }
    if (pos == 1) {
        new_node->next = *head;
        if (*head != nullptr)
            (*head)->prev = new_node;
        *head = new_node;
        return;
    }
 
    Node* temp = *head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position " << pos << " is out of bounds." << endl;
        delete new_node;
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
 
    if (temp->next != nullptr)
        temp->next->prev = new_node;
 
    temp->next = new_node;
}
 
void delete_at_first(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty!!" << endl;
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != nullptr)
        (*head)->prev = nullptr;
    delete temp;
    cout << "First node deleted." << endl;
}
 
void delete_at_last(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty!!!" << endl;
        return;
    }
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        cout << "Last node deleted!!!" << endl;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
    cout << "Last node deleted." << endl;
}
 
void delete_at_position(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
 
    int pos;
    cout << "Enter the node position to delete (starting from 1): ";
    cin >> pos;
 
    if (pos <= 0) {
        cout << "Invalid position." << endl;
        return;
    }
 
    Node* temp = *head;
    for (int i = 1; temp != nullptr && i < pos; i++) {
        temp = temp->next;
    }
 
    if (temp == nullptr) {
        cout << "Position " << pos << " is out of bounds." << endl;
        return;
    }
 
    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
 
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
 
    delete temp;
    cout << "Node at position " << pos << " deleted." << endl;
}
 
void print_list(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "\nList: ";
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
 
int main() {
    Node* head = nullptr;
    int opt;
    while (true) {
        cout << "\n1.Insert_at_first\n2.Insert_at_position\n3.Insert_at_last\n4.Delete_at_first\n5.Delete_at_position\n6.Delete_at_last\n7.Print_list\n8.Exit\nChoose the option : ";
        cin >> opt;
        switch (opt) {
            case 1: insert_at_first(&head);
            break;
            case 2: insert_at_position(&head);
            break;
            case 3: insert_at_last(&head);
            break;
            case 4: delete_at_first(&head);
            break;
            case 5: delete_at_position(&head);
            break;
            case 6: delete_at_last(&head);
            break;
            case 7: print_list(head);
            break;
            case 8: return 0;
            default: cout << "Invalid Option!!!" << endl;
        }
    }
}