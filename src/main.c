#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaces.h"

#define NOTE_COUNT 5

int main() {
    Note notebook[NOTE_COUNT];
    char s_phone[20];
    int index;

    printf("\nEnter data for %d people:\n", NOTE_COUNT);
    input(notebook, NOTE_COUNT);

    printf("\nData before sorting");
    print_all(notebook, NOTE_COUNT);

    sort_date(notebook, NOTE_COUNT);
    printf("\nPrint all sorted by date");
    print_all(notebook, NOTE_COUNT);

    printf("\nEnter phone number: ");
    getchar();
    fgets(s_phone, sizeof(s_phone), stdin);
    s_phone[strcspn(s_phone, "\n")] = 0;

    index = search_phone(notebook, NOTE_COUNT, s_phone);

    if (index != -1) {
        printf("\nFound a person with num %s:\n", s_phone);
        print_note(notebook[index]);
    } else {
        printf("\nA person with num %s NOT found.\n", s_phone);
    }

    printf("\nProgram finished\n");
    return 0;
}
