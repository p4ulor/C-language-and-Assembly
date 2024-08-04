#include<stdio.h>

typedef struct appointment { //16 bytes
    char *description; // 8 bytes
    char *schedule; //8 bytes
} Appointment;

typedef struct appointments {
    int length; //4 bytes
    Appointment *events;
} Appointments;

typedef struct agenda { //256 bytes
    char *name;  // 8 bytes
    Appointments* calendar[31]; //8 bytes * 31 = 248
} Agenda;

//									  rdi             rsi          rdx	        rcx
Appointment *get_appointment(Agenda agenda[], size_t month, size_t day, size_t index) {
return agenda[month].calendar[day] != NULL
&& index < agenda[month].calendar[day]->length
? &(agenda[month].calendar[day]->events[index])
: NULL;