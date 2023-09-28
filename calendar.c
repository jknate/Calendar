#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to represent calendar events
struct CalendarEvent {
    int day;
    int month;
    int year;
    char description[100];
};

// Function to add an event
void addEvent(struct CalendarEvent calendar[], int *eventCount) {
    if (*eventCount >= 100) {
        printf("Calendar is full. Cannot add more events.\n");
        return;
    }

    struct CalendarEvent newEvent;

    printf("Enter event date (day month year): ");
    scanf("%d %d %d", &newEvent.day, &newEvent.month, &newEvent.year);
    printf("Enter event description: ");
    scanf(" %[^\n]", newEvent.description);

    calendar[*eventCount] = newEvent;
    (*eventCount)++;
    printf("Event added to the calendar.\n");
}

// Function to view events for a specific date
void viewEvents(struct CalendarEvent calendar[], int eventCount, int day, int month, int year) {
    printf("Events for %d/%d/%d:\n", day, month, year);

    for (int i = 0; i < eventCount; i++) {
        if (calendar[i].day == day && calendar[i].month == month && calendar[i].year == year) {
            printf("%s\n", calendar[i].description);
        }
    }
}

// Function to delete events for a specific date
void deleteEvents(struct CalendarEvent calendar[], int *eventCount, int day, int month, int year) {
    int deleted = 0;

    for (int i = 0; i < *eventCount; i++) {
        if (calendar[i].day == day && calendar[i].month == month && calendar[i].year == year) {
            // Remove the event by shifting remaining events
            for (int j = i; j < (*eventCount - 1); j++) {
                calendar[j] = calendar[j + 1];
            }
            (*eventCount)--;
            deleted = 1;
        }
    }

    if (deleted) {
        printf("Events for %d/%d/%d deleted.\n", day, month, year);
    } else {
        printf("No events found for %d/%d/%d.\n", day, month, year);
    }
}

int main() {
    struct CalendarEvent calendar[100]; // Maximum of 100 events
    int eventCount = 0;

    while (1) {
        printf("\nCalendar/Planner Application\n");
        printf("1. Add Event\n");
        printf("2. View Events for a Date\n");
        printf("3. Delete Events for a Date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEvent(calendar, &eventCount);
                break;
            case 2:
                {
                    int day, month, year;
                    printf("Enter date to view events (day month year): ");
                    scanf("%d %d %d", &day, &month, &year);
                    viewEvents(calendar, eventCount, day, month, year);
                }
                break;
            case 3:
                {
                    int day, month, year;
                    printf("Enter date to delete events (day month year): ");
                    scanf("%d %d %d", &day, &month, &year);
                    deleteEvents(calendar, &eventCount, day, month, year);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
