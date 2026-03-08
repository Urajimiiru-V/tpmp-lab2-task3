#include <stdio.h>
#include <string.h>
#include "interfaces.h"

void input(Note *notes, int count) {
    for (int i = 0; i < count; i++) {
        printf("\nEnter data %d \n", i + 1);
        if (i == 0){
            getchar();
        }        
        printf("Surname: ");
        fgets(notes[i].name, sizeof(notes[i].name), stdin);
        notes[i].name[strcspn(notes[i].name, "\n")] = 0;
        
        printf("Phone number: ");
        fgets(notes[i].tele, sizeof(notes[i].tele), stdin);
        notes[i].tele[strcspn(notes[i].tele, "\n")] = 0;
        
        printf("Birthday(d-m-y): ");
        scanf("%d %d %d", &notes[i].birth_date.day, &notes[i].birth_date.month, &notes[i].birth_date.year); 
        getchar();
    }
}

int compare_date(Date d1, Date d2) {
    if (d1.year != d2.year) return d1.year - d2.year;
    if (d1.month != d2.month) return d1.month - d2.month;
    return d1.day - d2.day;
}

void sort_date(Note *notes, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare_date(notes[j].birth_date, notes[j+1].birth_date) > 0) {
                Note temp = notes[j];
                notes[j] = notes[j+1];
                notes[j+1] = temp;
            }
        }
    }
}

void print_note(Note note) {
    printf("Name: %-20s | Num: %-15s | Birthday: %04d-%02d-%02d\n", note.name, note.tele, note.birth_date.year, note.birth_date.month, note.birth_date.day);
}

void print_all(Note *notes, int count) {
    printf("\nList of all notes\n");
    for (int i = 0; i < count; i++) {
        printf("%2d. ", i + 1);
        print_note(notes[i]);
    }
}

int search_phone(Note *notes, int count, char *phone) {
    for (int i = 0; i < count; i++) {
        if (strcmp(notes[i].tele, phone) == 0) {
            return i;
        }
    }
    return -1;
}
