#include <iostream>
#include <sstream>
#include  <iomanip>
#include <string>
using namespace std;


class vehicle
{
    private:
    int vehicleId;
    string onwerName;
    int serviceType;
    string arrivalTime;
    public:
    vehicle(){}
    vehicle(int id,string name,int service,string time) : vehicleId(id),onwerName(name),serviceType(service),arrivalTime(time){}

    int get_id(){return vehicleId;}
    string get_name(){return onwerName;}
    int get_service(){return serviceType;}
    string get_time(){return arrivalTime;}
};

class double_list
{
    public:
    double_list* prev;
    vehicle object;
    double_list* next;
    double_list(){}
    double_list(vehicle object) : object(object),prev(nullptr),next(nullptr){}

    double_list* insert(double_list* head,vehicle d)
    {
        double_list * temp = head;
        double_list* new_node = new double_list(d);
        if (head == nullptr)
            return new_node;
        while(head->next != nullptr)
        {
            head = head->next;
        }
        head->next = new_node;
        new_node->prev = head;
        return temp;
    }

    void display_data(double_list * head)
    {
        if (head == nullptr){
            cout << "list Empty" << endl;
            return;
        }
        while(head != nullptr)
        {
            cout << "Vehicle Id: " <<(head->object).get_id() << endl;
            cout << "Owner Name: "<<(head->object).get_name() << endl;
            cout << "Service Type: ";
            switch((head->object).get_service())
            {
                case 1:
                    cout << "Normal" << endl;
                    break;
                case 2:
                    cout << "VIP" << endl;
                    break;
                case 3:
                    cout << "Emergency" << endl;
            }
            cout << "Arrival Time: " <<(head->object).get_time() << endl << endl;
            head = head->next;
        }
    }
};


class stack
{
    public:
        vehicle object;
        stack* next;
        stack(){}
        stack(vehicle object): object(object),next(nullptr){}

    stack* push(stack* head,stack*& top,vehicle d)
    {
        stack* temp = head;
        stack* new_node = new stack(d);
        if (head == nullptr)
        {
            top = new_node;
            return new_node;
        }
        while(head->next != nullptr)
        {
            head = head->next;
        }
        head->next = new_node;
        top = new_node;
        return temp;
    }

    void display(stack* head)
    {
        if(head == nullptr)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        while(head != nullptr)
        {
            cout << "Vehicle Id: " <<(head->object).get_id() << endl;
            cout << "Owner Name: "<<(head->object).get_name() << endl;
            cout << "Service Type: ";
            switch((head->object).get_service())
            {
                case 1:
                    cout << "Normal" << endl;
                    break;
                case 2:
                    cout << "VIP" << endl;
                    break;
                case 3:
                    cout << "Emergency" << endl;
            }
            cout << "Arrival Time: " <<(head->object).get_time() << endl << endl;
            head =head->next;
        }
    }


    void top(stack* top)
    {
        if(top == nullptr)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Vehicle Id: " <<(top->object).get_id() << endl;
            cout << "Owner Name: "<<(top->object).get_name() << endl;
            cout << "Service Type: ";
            switch((top->object).get_service())
            {
                case 1:
                    cout << "Normal" << endl;
                    break;
                case 2:
                    cout << "VIP" << endl;
                    break;
                case 3:
                    cout << "Emergency" << endl;
            }
            cout << "Arrival Time: " <<(top->object).get_time() << endl << endl;
    }
};


class queue
{
    public:
    vehicle object;
    queue* next;
    queue(){}
    queue(vehicle object) :object(object),next(nullptr){}

    queue* push(queue* head,vehicle d)
    {
        queue* temp = head;
        queue* new_node = new queue(d);
        if (head == nullptr)
            return new_node;
        while(head->next != nullptr)
        {
            head = head->next;
        }
        head->next = new_node;
        return temp;
    }

    void display(queue* head)
    {
        if(head == nullptr)
        {
            cout << "queue empty" << endl;
            return;
        }
        while(head != nullptr)
        {
            cout << "Vehicle Id: " <<(head->object).get_id() << endl;
            cout << "Owner Name: "<<(head->object).get_name() << endl;
            cout << "Service Type: ";
            switch((head->object).get_service())
            {
                case 1:
                    cout << "Normal" << endl;
                    break;
                case 2:
                    cout << "VIP" << endl;
                    break;
                case 3:
                    cout << "Emergency" << endl;
            }
            cout << "Arrival Time: " <<(head->object).get_time() << endl << endl;
            head = head->next;
        }
    }

    queue* pop(queue* head,vehicle& v)
    {
        if (head == nullptr)
        {
            cout << "queue empty" << endl;
            return nullptr;
        }
        v = head->object;
        queue* temp = head->next;
        delete head;
        return temp;
    }

    void top(queue* top)
    {
        if(top == nullptr)
        {
            cout << "queue is Empty" << endl;
            return;
        }
        cout << "Vehicle Id: " <<(top->object).get_id() << endl;
            cout << "Owner Name: "<<(top->object).get_name() << endl;
            cout << "Service Type: ";
            switch((top->object).get_service())
            {
                case 1:
                    cout << "Normal" << endl;
                    break;
                case 2:
                    cout << "VIP" << endl;
                    break;
                case 3:
                    cout << "Emergency" << endl;
            }
            cout << "Arrival Time: " <<(top->object).get_time() << endl << endl;
    }


};

class priority_queue
{
    public:
    int priority;
    vehicle object;
    priority_queue* next;
    priority_queue(){}
    priority_queue(vehicle object): object(object),priority(object.get_service()),next(nullptr) {}

    priority_queue* push(priority_queue* head,vehicle d)
    {
        priority_queue* new_node = new priority_queue(d);
        if(head == nullptr || (head->priority < d.get_service()))
        {
            new_node->next = head;
            return new_node;
        }
        priority_queue* temp = head;
        while(((temp->next) != nullptr) && ((temp->next->priority) >= d.get_service()))
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        return head;
    }

    void display(priority_queue* head)
    {
        if(head == nullptr)
        {
            cout << "Priority list empty" << endl;
            return;
        }
        while(head != nullptr)
        {
            cout << "Vehicle Id: " <<(head->object).get_id() << endl;
            cout << "Owner Name: "<<(head->object).get_name() << endl;
            cout << "Service Type: ";
            switch((head->object).get_service())
            {
                case 1:
                    cout << "Normal" << endl;
                    break;
                case 2:
                    cout << "VIP" << endl;
                    break;
                case 3:
                    cout << "Emergency" << endl;
            }
            cout << "Arrival Time: " <<(head->object).get_time() << endl << endl;
            head = head->next;
        }
    }

    priority_queue* pop(priority_queue* head,vehicle& v)
    {
        if (head == nullptr)
        {
            cout << "Priority list empty" << endl;
            return nullptr;
        }
        v = move(head->object);
        priority_queue* temp = head->next;
        delete head;
        return temp;
    }

    int is_Empty(priority_queue* head)
    {
        if (head == nullptr)
            return 0;
        return 1;
    }

    void top(priority_queue* top)
    {
        if(top == nullptr)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Vehicle Id: " <<(top->object).get_id() << endl;
            cout << "Owner Name: "<<(top->object).get_name() << endl;
            cout << "Service Type: ";
            switch((top->object).get_service())
            {
                case 1:
                    cout << "Normal" << endl;
                    break;
                case 2:
                    cout << "VIP" << endl;
                    break;
                case 3:
                    cout << "Emergency" << endl;
            }
            cout << "Arrival Time: " <<(top->object).get_time() << endl << endl;
    }

};

string get_current_time()
{
    ostringstream oss;
    time_t now = time(0);
    tm local_t;
    localtime_s(&local_t,&now);
    oss << put_time(&local_t,"%H:%M:%S");
    return oss.str();
}


int main()
{
    double_list* d_root = nullptr, d;
    stack* s_root = nullptr,s;
    queue* q_root = nullptr,q;
    priority_queue* pq_root = nullptr,pq;
    stack* top = nullptr;
    vehicle v;
    int opt;
    while(1)
    {
        cout << "\n1.Add vehicle for Service\n2.Process Next Vehicle\n3.Show Waiting Queue\n4.Show VIP/Emergency Queue\n5.Show Last Serviced Vehicle\n6.Display Full Service History\n7.Exit\n\nChoose the option: ";
        cin >> opt;
        switch(opt)
        {
            case 1:
                {
                    int id,service_type;
                    string owner_name;
                    cout << "Enter the Vehicle Id: ";
                    cin >> id;
                    cout << "Enter the owner name: ";
                    getchar();
                    getline(cin,owner_name);
                    cout << "Enter the service type (1 = Normal,2 = VIP,3 = Emergency): ";
                    cin >> service_type;
                    cout << "Time:";
                    string time = get_current_time();
                    cout << time << endl;
                    if (service_type == 1)
                    {
                        q_root = q.push(q_root,vehicle(id,owner_name,service_type,time));
                    }
                    else
                    {
                        pq_root = pq.push(pq_root,vehicle(id,owner_name,service_type,time));
                    }
                }
                break;
            case 2:
                {
                    if (pq.is_Empty(pq_root))
                    {
                        cout << "Vehicle Servicing Finished for ";
                        pq.top(pq_root);
                        pq_root = pq.pop(pq_root,v);
                        s_root = s.push(s_root,top,v);
                        d_root = d.insert(d_root,v);
                    }
                    else
                    {
                        cout << "Vehicle Servicing Finished for ";
                        q.top(q_root);
                        q_root = q.pop(q_root,v);
                        s_root = s.push(s_root,top,v);
                        d_root = d.insert(d_root,v);
                    }
                }
                break;
            case 3:
                {
                    cout << "\n=== Waiting Queue of Normal Vehicles ===" << endl;
                    q.display(q_root);
                }
                break;
            case 4:
                {
                    cout << "\n=== Waiting Queue of VIP/Emergency Vehicles ===" << endl;
                    pq.display(pq_root);
                }
                break;
            case 5:
                {
                    cout << "=== Last Serviced Vehicle ===" << endl;
                    s.display(top);
                }
                break;
            case 6:
                {
                    cout << "==== All the service Vehicles List ====" << endl;
                    d.display_data(d_root);
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "Please Enter Valid Option" << endl;
        }
    }

}