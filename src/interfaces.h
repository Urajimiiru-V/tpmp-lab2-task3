#ifndef INTERFACES_H
#define INTERFACES_H

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[50];
    char tele[20];
    Date birth_date;
} Note;

void input(Note *notes, int count);
void sort_date(Note *notes, int count);
void print_note(Note note);
int search_phone(Note *notes, int count, char *phone);
void print_all(Note *notes, int count);
#endif
