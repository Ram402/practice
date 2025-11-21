#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define CAN_FAULT       (1U << 0)
#define AUDIO_FAULT     (1U <<1)
#define SENSOR_FAULT    (1U << 2)
#define OVERHEAT_FAULT  (1U << 3)
enum EventType
{
    INFO_LOG = 1,
    USER_ACTION,
    WARNING_LOW_FUEL,
    FAULT_CAN_BUS,
    SYSTEM_BOOT
};

struct Timestamp
{
    int hour;
    int minute;
    int second;
};

union EventData
{
    char message[50];
    int button_id;
    float fuel_percentage;
};

typedef struct Event
{
    enum EventType type;
    struct Timestamp time;
    union EventData data;
}Event;

extern Event** g_event_log;
extern int g_log_count;
extern int g_log_capacity;



void init_logger(void);
void add_event(void);
const char * get_event_type_string(enum EventType v);
void display_log(void);
void clear_log(void);
void save_log_to_file(void);
void load_log_from_file(void);
void set_fault(void);
void clear_fault(void);
void display_system_status(void);
int compare_by_timestamp(const void * a,const void *b);
long factorial(int n);