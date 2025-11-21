#include "event_logger.h"

Event** g_event_log = NULL;
int g_log_count;
int g_log_capacity;


int main()
{
    init_logger();
    
    int option;
    while(1)
    {
        printf("1. Add Event\n2. Display Log\n3. Clear Log\n4. Save Log to File\n5. Load Log from File\n6. Set Fault\n7. Clear Fault\n8. Display System Status\n9. Sort Log by Timestamp\n10. Test Recursion (Factorial)\n0. Exit\n ");
        printf("Enter option: ");
        while(((scanf("%d",&option))!=1)||(option < 0 || option > 10))
        {
            while(getchar()!='\n');
            printf("Invalid option, choose again: ");
        }
        switch(option)
        {
            case 1:
                {
                    add_event();
                    break;                    
                }
            case 2:
                {
                    display_log();
                    break;
                }
            case 3:
                {
                    clear_log();
                    break;
                }
            case 4:
                {
                    save_log_to_file();
                    break;
                }
            case 5:
                {
                    load_log_from_file();
                    break;
                }
            case 6:
                {
                    set_fault();
                    break;
                }
            case 7:
                {
                    clear_fault();
                    break;
                }
            case 8:
                {
                    display_system_status();
                    break;
                }
            case 9:
                {
                    qsort(g_event_log,g_log_count,sizeof(Event*),compare_by_timestamp);
                    break;
                }
            case 10:
                {
                    int n;
                    printf("Enter number: ");
                    while((scanf("%d",&n))!=1)
                    {
                        while(getchar()!='\n');
                        printf("Invalid input,Enter again: ");
                    }
                    printf("factorial of %d: %ld\n",n,factorial(n));
                }
                break;
            case 0:
                {
                    return 0;
                }
            default:
                printf("Invalid Choice");
        }
    }
}