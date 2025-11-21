#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}Node;

Node * Create_Node()
{
    Node * new = (Node*)malloc(sizeof(Node));
    if(new == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the data: ");
    scanf("%d",&(new->data));
    new->next = NULL;
    return new;
}


Node * insert_end(Node * head)
{
    if(head == NULL)
    {
        Node * new = Create_Node();
        return new;
    }
    Node * temp = head;
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = Create_Node();
    return temp;
}

Node * insert_start(Node *head)
{
    if(head == NULL)
    {
        Node * new = Create_Node();
        return new;   
    }
    Node * new = Create_Node();
    new->next = head;
    return new;
}

void display(Node * head)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }
    while(head != NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
}

Node * reverse_list(Node * head)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    Node * p = head,* q = p->next,*r = q->next;
    while(q != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        if (r)
            r = r->next;
    }
    head->next = NULL;
    return p;
}

Node * Delete_first(Node * head)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return NULL;
    }
    Node * temp = head->next;
    free(head);
    return temp;
}

Node * Delete_end(Node * head)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return NULL;
    }
    Node * prev,*temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
    return head;
}


Node * reverse_from_node(Node * head)
{
    int data;
    printf("Enter the data:");
    scanf("%d",&data);
    Node * temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Data not found\n");
        return head;
    }
    printf("Data found\n");
    Node * p = head,* q = p->next;
    while(p != temp)
    {
        if (q == NULL) break;
        Node *r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    // printf("%d :  %d",temp->next->data,q->data);
    head->next = q;
    return p;
}
void create_loop(Node *head)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    int data;
    printf("Enter the data where loop should start: ");
    scanf("%d", &data);

    Node *start = head;
    Node *loop_node = NULL;

    // Find the loop start node by data
    while(start != NULL)
    {
        if(start->data == data)
        {
            loop_node = start;
            break;
        }
        start = start->next;
    }

    if(loop_node == NULL)
    {
        printf("No node found with given data\n");
        return;
    }

    // Move to last node
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    // Create loop
    temp->next = loop_node;

    printf("Loop created! Last node now points to %d\n", loop_node->data);
}

void detect_loop(Node * head)
{
    if (head== NULL){
        printf("List Empty\n");
        return;
    }
    Node * p = head,*q = head;
    while(p!=NULL)
    {
        p = p->next;
        if (q)
            q = q->next;
        if (q)
            q = q->next;
        if (p == q)
            break;
    }
    if ((p == NULL) && (q== NULL))
    {
        printf("No loop Detected\n");
        return;
    }
    else
    {
        printf("Loop Detected\n");
        p = head;
        Node * prev = NULL;
        while(p != q)
        {
            p = p->next;
            prev = q;
            q = q->next;
        }
        prev->next = NULL;
        printf("Loop break");
        return;
    }
   
}

Node * get_node(Node * head,int data)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return NULL;
    }
    while((head != NULL) && (head->data != data))
    {
        head = head->next;
    }
    if (head == NULL)
        return NULL;
    else
        return head;
}

void reverse_after_node(Node * head)
{
    int data;
    printf("Enter the data:");
    scanf("%d",&data);
    Node * temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Data not found\n");
        return;
    }
    if(temp->next == NULL)
    {
        printf("No nodes after the data to reverse\n");
        return;
    }
    printf("Data found\n");
    Node * last  =temp->next;
    Node * p = last,* q = p->next;
    while(p != temp)
    {
        if (q == NULL) break;
        Node *r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    last->next = NULL;
    temp->next = p;          // connect reversed part back
    return;
}

void delete_node_without_head(Node * node)
{
    if (node == NULL)
    {
        printf("Node not found\n");
        return;
    }
    Node * temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

void free_memory(Node * head)
{
    if (head == NULL)
    {
        return;
    }
    Node * temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node * rotate_list_by_nodes(Node * head)
{
    int num = 0;
    printf("Enter the number of nodes to rotate: ");
    scanf("%d",&num);

    if (num == 0 || head== NULL)
    {
        printf("No nodes to rotate\n");
        return head;
    }
    int count = 0;
    Node * temp = head;
    while((count < num -1) && (temp != NULL))
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Number of nodes is out of the boundary\n");
        return head;
    }
    if (temp->next == NULL)
    {
        printf("No nodes to rotate the list\n");
        return head;
    }

    Node * next = temp->next,*end = temp->next;
    temp->next = NULL;
    while (next->next != NULL)
    {
        next = next->next;
    }
    next->next = head;
    return end;
}

int main()
{
    Node * head = NULL;
    int option;
    while (1)
    {
        printf("1.Insert node at end\n2.Insert Node at Start\n3.Display the list\n4.Reverse the list\n5.Delete node at first\n6.Delete Node at last\n7.Reverse list from a node\n8.Detect loop\n9.Delete a node without head pointer\n10.Reverse after the node\n11.Rotate list by n nodes\n12. Create a loop in the list\n13.Exit\nEnter the option: ");
        while((scanf("%d",&option))!=1)
        {
            while(getchar()!='\n');
            printf("Invalid choice Enter again: ");
        }
        switch (option)
        {
        case 1:
            head = insert_end(head);
            break;
        case 2:
            head = insert_start(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            head = reverse_list(head);
            break;
        case 5:
            head = Delete_first(head);
            break;
        case 6:
            head = Delete_end(head);
            break;
        case 7:
            head = reverse_from_node(head);
            break;
        case 8:
            detect_loop(head);
            break;
        case 9:
            int num;
            printf("Enter the data: ");
            scanf("%d",&num);
            Node * node = get_node(head,num);
            delete_node_without_head(node);
            break;
        case 10:
            reverse_after_node(head);
            break;
        case 11:
            head = rotate_list_by_nodes(head);
            break;
        case 12:
            create_loop(head);
            break;
        case 13:
            free_memory(head);
            return 0;
        default:
            break;
        }
    }
}