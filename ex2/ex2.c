#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ex2.h"
#include "string.h"
#define N 30



void print_list(void* list, void (*print_item)(void* item), void* (*get_next)(void* item)) {

    for (void* current = list; current != NULL; current = get_next(current)) {
        print_item(current);
        printf("\n");
    }
}

Stud newStudent(int id) {
    return (Stud)
            { .id = id
            , .averageOfGrades = 0
            , .averageOfInserts = 0
            , .gradesList = NULL
            , .incomesList = NULL
            };
}
void newIncome(int id, char* date, double amount) {

}
void wantedStudent(int id) {

}
void printArray() {

}
// part B
void sortArray(enum Ordering (*compare)(const Stud a, const Stud b), enum SortBy sb, enum SortDirection sd) {
}
int sortArray_(enum Ordering (*cmp)(const Stud s1, const Stud s2)) {

}

void addIncome(Stud stud, struct Income income) {

}
void* getNextGrade(void* gradeNode) {
    struct GradeNode* gn = (struct GradeNode*) gradeNode;
    return (void*)(gn->next);
}


void printGrade(void* gradeNode) {
    struct GradeNode* gn = (struct GradeNode*)gradeNode;
    printf("%s %d", gn->data.courseName, gn->data.grade);
}
void printStudent(Stud* stud) {
    printf("%d\n", (*stud).id);
    print_list((*stud).gradesList, printGrade, getNextGrade);
}
void addGrade(struct GradeNode** gradesList, struct Grade* grade) {
    if (*gradesList == NULL) {
        // gradesList is empty
//        *gradesList = malloc(sizeof(struct GradeNode));
//        struct GradeNode* n = **gradesList;
        (*gradesList) = malloc(sizeof(**gradesList));
        (*gradesList)->data = *grade;
        (*gradesList)->next = NULL;
    } else {
        struct GradeNode* current = *gradesList;
        while (current->next != NULL)
            current = current->next;

        current->next = malloc(sizeof(struct GradeNode));
        current->next->data = *grade;
        current->next->next = NULL;
    }
}
int main() {

    Stud stud1 = newStudent(1234);


//    char s[5] = "test";
//    struct Grade stud1gradeInC;
//    strcpy(stud1gradeInC.courseName, s);
//    stud1gradeInC.grade = 90;

    struct Grade stud1gradeInD = {"test2", 99};
    struct Grade stud1gradeInC = {"test3", 59};

//    struct GradeNode gn = {.data = stud1gradeInC, .next = NULL};
//    struct GradeNode gn2 = {.data = stud1gradeInD, .next = &gn};

    addGrade(&(stud1.gradesList), &stud1gradeInD);
    addGrade(&(stud1.gradesList), &stud1gradeInC);



//    stud1.gradesList = &gn2;
    printStudent(&stud1);
//    printGrade(&gn2);
//    print_list(&gn2, printGrade, getNextGrade);
    return 0;
}
