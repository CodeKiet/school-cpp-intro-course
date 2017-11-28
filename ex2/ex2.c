#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define N 30

void destructStudents(Stud students[], int size) {
    for (int i = 0; i < size; ++i) {
        destructLinkedList(getNextGradeNode, students[i].gradesList);
        destructLinkedList(getNextIncomeNode, students[i].incomesList);
    }
}

int main() {
    Stud students[N];

    char op[4];
    int currentIndex = 0;

    scanf("%s", op);

    while (strcmp(op, "end") != 0) {
        if (strcmp(op, "ns") == 0) {
            unsigned int id;
            scanf("%u", &id);
            int success = addStudent(students, currentIndex, id);
            if (success)
                currentIndex++;
        } else if (strcmp(op, "ng") == 0) {
            unsigned int id;
            char courseName[COURSE_NAME_MAX_LENGTH];
            unsigned int grade;
            scanf("%d", &id);
            scanf("%s", courseName);
            scanf("%d", &grade);

            Stud* stud = getStudent(students, id, currentIndex);
            if (stud == NULL) {
                printf("NA");
                destructStudents(students, currentIndex);
                return 0;
            }

            Grade newGrade;
            strcpy(newGrade.courseName, courseName);
            newGrade.grade = grade;
            addToList(createGradeNode, compareGradeNode, getNextGradeNode, setNextGradeNode, &newGrade, (void **) &(stud->gradesList));
            (stud->gradesCount)++;
            stud->gradesTotal += grade;
            stud->averageOfGrades = stud->gradesTotal / stud->gradesCount;
        } else if (strcmp(op, "ni") == 0) {
            unsigned int id;
            char workName[WORK_NAME_MAX_LENGTH];
            float income;
            scanf("%d", &id);
            scanf("%s", workName);
            scanf("%f", &income);

            Stud* stud = getStudent(students, id, currentIndex);
            if (stud == NULL) {
                printf("NA");
                destructStudents(students, currentIndex);
                return 0;
            }
            Income newIncome;
            strcpy(newIncome.workName, workName);
            newIncome.amount = income;
            addToList(createIncomeNode, compareIncomeNode, getNextIncomeNode, setNextIncomeNode, &newIncome, (void **) &(stud->incomesList));

            stud->insertsTotal += income;
            stud->insertsCount++;
            stud->averageOfInserts = stud->insertsTotal / stud->insertsCount;
        } else if (strcmp(op, "ws") == 0) {
            unsigned int id;
            scanf("%d", &id);
            Stud* stud = getStudent(students, id, currentIndex);
            if (stud != NULL) {
                printStudent(stud);
            } else {
                printf("NA");
                destructStudents(students, currentIndex);
                return 0;
            }

        } else if (strcmp(op, "pa") == 0) {
            printAllStudents(students, currentIndex);
        } else if (strcmp(op, "sa") == 0) {
            char sortBy[3];
            scanf("%s", sortBy);
            if (strcmp(sortBy, "ia") == 0)
                sortArray(compareByIDAscending, students, currentIndex - 1);
//                mergesort(students, 0, currentIndex, compareByIDAscending);
//                qsort((void*)students, (size_t) currentIndex, sizeof(Stud), compareByIDAscending);
            else if (strcmp(sortBy, "id") == 0)
                sortArray(compareByIDDescending, students, currentIndex - 1);
//                qsort((void*)students, (size_t) currentIndex, sizeof(Stud), compareByIDDescending);
            if (strcmp(sortBy, "ga") == 0)
                sortArray(compareByAvgGradeAscending, students, currentIndex - 1);
//                qsort((void*)students, (size_t) currentIndex, sizeof(Stud), compareByAvgGradeAscending);
            if (strcmp(sortBy, "gd") == 0)
                sortArray(compareByAvgGradeDescending, students, currentIndex - 1);
//                qsort((void*)students, (size_t) currentIndex, sizeof(Stud), compareByAvgGradeDescending);
//                mergesort(students, 0, currentIndex, compareByAvgGradeDescending);

        }
        scanf("%s", op);
    }


    destructStudents(students, currentIndex);
    return 0;
}
