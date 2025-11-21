#include "event_logger.h" 
static volatile uint32_t g_system_status = 0;

void init_logger(void)
{
    g_log_capacity = 10;
    g_log_count = 0;
    g_event_log = (Event**)calloc(g_log_capacity,sizeof(Event*));
    if(g_event_log == NULL)
    {
        printf("Memory not allocated for the Event pointers\n");
        exit(1);
    }
}

void add_event(void)
{
    if (g_log_count == g_log_capacity)
    {
        Event** temp = (Event**)realloc(g_event_log,(g_log_capacity+g_log_capacity)*(sizeof(Event*))); 
        if (temp == NULL)
        {
            printf("Memory not reallocated\n");
            return;
        }
        // free(g_event_log);
        g_event_log = temp;
        g_log_capacity += g_log_capacity;
    }
    int option;
    printf("1. INFO_LOG\n2. USER_ACTION\n3. WARNING_LOW_FUEL\n4. FAULT_CAN_BUS\n5. SYSTEM_BOOT\n6. Back to main Menu\n");
    printf("Enter Option: ");
    while((scanf("%d",&option))!=1)
    {
        while(getchar()!='\n');
        printf("Invalid option, choose again: ");
    }
    switch(option)
    {
        case 1:
            {
                g_event_log[g_log_count] = (Event*)malloc(sizeof(Event));
                if (g_event_log[g_log_count] == NULL)
                {
                    printf("Memory not allocated for the EVent\n");
                    return;
                }
                g_event_log[g_log_count]->type = INFO_LOG; 
                printf("Enter Time(HH MM SS): ");
                scanf("%d%d%d",&(g_event_log[g_log_count]->time.hour),&(g_event_log[g_log_count]->time.minute),&(g_event_log[g_log_count]->time.second));
                printf("Enter message: ");
                scanf(" %49[^\n]",(g_event_log[g_log_count]->data.message));
                g_log_count++;
            }
            break;
        case 2:
            {
                g_event_log[g_log_count] = (Event*)malloc(sizeof(Event));
                if (g_event_log[g_log_count] == NULL)
                {
                    printf("Memory not allocated for the EVent\n");
                    return;
                }
                g_event_log[g_log_count]->type = USER_ACTION; 
                printf("Enter Time(HH MM SS): ");
                scanf("%d%d%d",&(g_event_log[g_log_count]->time.hour),&(g_event_log[g_log_count]->time.minute),&(g_event_log[g_log_count]->time.second));
                printf("Enter button Id: ");
                scanf("%d",&(g_event_log[g_log_count]->data.button_id));
                g_log_count++;
            }
            break;
        case 3:
            {
                g_event_log[g_log_count] = (Event*)malloc(sizeof(Event));
                if (g_event_log[g_log_count] == NULL)
                {
                    printf("Memory not allocated for the EVent\n");
                    return;
                }
                g_event_log[g_log_count]->type = WARNING_LOW_FUEL; 
                printf("Enter Time(HH MM SS): ");
                scanf("%d%d%d",&(g_event_log[g_log_count]->time.hour),&(g_event_log[g_log_count]->time.minute),&(g_event_log[g_log_count]->time.second));
                printf("Enter Fuel Percentage: ");
                scanf("%f",&(g_event_log[g_log_count]->data.fuel_percentage));
                g_log_count++;
            }
            break;
        case 4:
            {
                g_event_log[g_log_count] = (Event*)malloc(sizeof(Event));
                if (g_event_log[g_log_count] == NULL)
                {
                    printf("Memory not allocated for the EVent\n");
                    return;
                }
                g_event_log[g_log_count]->type = FAULT_CAN_BUS; 
                printf("Enter Time(HH MM SS): ");
                scanf("%d%d%d",&(g_event_log[g_log_count]->time.hour),&(g_event_log[g_log_count]->time.minute),&(g_event_log[g_log_count]->time.second));
                g_log_count++;
            }
            break;
        case 5:
            {
                g_event_log[g_log_count] = (Event*)malloc(sizeof(Event));
                if (g_event_log[g_log_count] == NULL)
                {
                    printf("Memory not allocated for the EVent\n");
                    return;
                }
                g_event_log[g_log_count]->type = SYSTEM_BOOT; 
                printf("Enter Time(HH MM SS): ");
                scanf("%d%d%d",&(g_event_log[g_log_count]->time.hour),&(g_event_log[g_log_count]->time.minute),&(g_event_log[g_log_count]->time.second));
                g_log_count++;
            }
            break;
        case 6:
            {
                return;
            }
        default:
            printf("Invalid option");
    }
}

const char * get_event_type_string(enum EventType v)
{
    // switch(v)
    // {
    //     case 1:
    //         return "INFO LOG";
    //         break;
    //     case 2:
    //         return "USER ACTION";
    //         break;
    //     case 3:
    //         return "WARNING LOW FUEL";
    //         break;
    //     case 4:
    //         return "FAULT CAN BUS";
    //         break;
    //     case 5:
    //         return "SYSTEM BOOT";
    //         break;
    // }

    static const char * lookup_table[] = {"INFO LOG","USER ACTION","WARNING LOW FUEL","FAULT CAN BUS","SYSTEM BOOT"};
    return lookup_table[v-1];

}

void display_log(void)
{
    printf("\n======Event Details======\n");
    if (g_log_count == 0)
    {
        printf("log is Empty\n");
        return;
    }
    for(int i=0;i<g_log_count;i++)
    {
        printf("\n*******Event %d*******\n",i+1);
        printf("Event Type: %s\n",get_event_type_string(g_event_log[i]->type));
        printf("Event Time: %d:%d:%d\n",g_event_log[i]->time.hour,g_event_log[i]->time.minute,g_event_log[i]->time.second);
        switch(g_event_log[i]->type)
        {
            case 1:
                printf("Event Message: %s\n",g_event_log[i]->data.message);
                break;
            case 2:
                printf("Event Button id: %d\n",g_event_log[i]->data.button_id);
                break;
            case 3:
                printf("Event Fuel percentage: %.2f\n",g_event_log[i]->data.fuel_percentage);
                break;
            default:
                break;
        }
    }    
}


void clear_log(void)
{
    if (g_log_count == 0)
    {
        printf("No logs\n");
        return;
    }
    for(int i=0;i<g_log_count;i++)
    {
        free(g_event_log[i]);
    }
    free(g_event_log);
    g_log_capacity = 0;
    g_log_count = 0;
    init_logger();
}

void save_log_to_file(void)
{
    if (g_log_count == 0)
    {
        printf("No logs to save into file\n");
        return;
    }
    printf("\n");
    char str[20];
    printf("Enter the file name: ");
    scanf(" %19[^\n]",str);
    FILE * fp = fopen(str,"wb");
    if(fp == NULL)
    {
        printf("File is not opened");
        return;
    }
    for(int i=0;i<g_log_count;i++)
    {
        fwrite(g_event_log[i],sizeof(Event),1,fp);
    }
    fclose(fp);
    printf("Logs saved to file %s\n",str);
}

void load_log_from_file(void)
{
    printf("\n");
    char str[20];
    printf("Enter the file name: ");
    scanf(" %19[^\n]",str);
    FILE * fp = fopen(str,"rb");
    if(fp == NULL)
    {
        printf("File is not opened");
        return;
    }
    clear_log();
    Event temp;
    while((fread(&temp,sizeof(Event),1,fp))==1)
    {
        if (g_log_count == g_log_capacity)
        {
            Event** temper = (Event**)realloc(g_event_log,(g_log_capacity+g_log_capacity)*(sizeof(Event*))); 
            if (temper == NULL)
            {
                printf("Memory not reallocated\n");
                return;
            }
            // free(g_event_log);
            g_event_log = temper;
            g_log_capacity += g_log_capacity;
        }
        g_event_log[g_log_count] = (Event*)malloc(sizeof(Event));
        if (g_event_log[g_log_count] == NULL)
        {
            printf("Memory not allocated for the EVent\n");
            exit(1);
        }
        memcpy(g_event_log[g_log_count], &temp, sizeof(Event));
        g_log_count++;        
    }
    fclose(fp);
    printf("Logs read from the file\n");
}

void set_fault(void)
{
    int option;
    printf("1. CAN Fault\n2. Audio Fault\n3. Sensor Fault\n4. Overheat Fault\nEnter option: ");
    while((scanf("%d",&option))!=1)
    {
        while(getchar()!='\n');
        printf("Invalid option, choose again: ");
    }
    switch (option)
    {
    case 1:
        g_system_status |= CAN_FAULT;
        printf("CAN Fault Set\n");
        break;
    case 2:
        g_system_status |= AUDIO_FAULT;
        printf("Audio Fault Set\n");
        break;
    case 3:
        g_system_status |= SENSOR_FAULT;
        printf("Sensor Fault Set\n");
        break;
    case 4:
        g_system_status |= OVERHEAT_FAULT;
        printf("Overheat Fault Set\n");
        break;
    default:
        printf("Inavlid option");
        break;
    }
}


void clear_fault(void)
{
    int option;
    printf("1. CAN Fault\n2. Audio Fault\n3. Sensor Fault\n4. Overheat Fault\nEnter option: ");
    while((scanf("%d",&option))!=1)
    {
        while(getchar()!='\n');
        printf("Invalid option, choose again: ");
    }
    switch (option)
    {
    case 1:
        g_system_status &=~ CAN_FAULT;
        printf("CAN Fault clear\n");
        break;
    case 2:
        g_system_status &=~ AUDIO_FAULT;
        printf("Audio Fault clear\n");
        break;
    case 3:
        g_system_status &=~ SENSOR_FAULT;
        printf("Sensor Fault clear\n");
        break;
    case 4:
        g_system_status &=~ OVERHEAT_FAULT;
        printf("Overheat Fault clear\n");
        break;
    default:
        printf("Inavlid option");
        break;
    }
}


void display_system_status(void)
{
    if(g_system_status == 0)
    {
        printf("All systems clear,No faults\n");
        return;
    }
    printf("Active faults\n");
    if (g_system_status&(1<<0))
        printf("CAN Fault\n");
    if (g_system_status & (1<<1))
        printf("Audio Fault\n");
    if (g_system_status&(1<<2))
        printf("Sensor Fault\n");
    if (g_system_status&(1<<3))
        printf("OverHeat Fault\n");
}

int compare_by_timestamp(const void * a,const void *b)
{
    Event* e1 = *(Event**)a;
    Event* e2 = *(Event**)b;
    if (e1->time.hour < e2->time.hour) return -1;
    if (e1->time.hour > e2->time.hour) return 1;

    if (e1->time.minute < e2->time.minute) return -1;
    if (e1->time.minute > e2->time.minute) return 1;

    if (e1->time.second < e2->time.second) return -1;
    if (e1->time.second > e2->time.second) return 1;
    return 0;
}

long factorial(int n)
{
    if(n==0 || n==1)
        return 1; 
    return n*factorial(n-1);
}
