/**
 * Student Name: Eitan Sternlicht
 * ID: 204070635
 * Exercise: 2
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"



int main() {
    Stud students[N];

    char op[OP_LENGTH + 1]; // op code
    int currentIndex = 0; // students in array

    scanf("%s", op);
    // main program loop
    while (strcmp(op, OP_CODE_END_PROGRAM) != 0) {
        if (strcmp(op, OP_CODE_NEW_STUDENT) == 0) {
            unsigned int id;
            scanf("%u", &id);
            bool success = addStudent(students, currentIndex, id);
            if (success) // increase student count
                currentIndex++;
        } else if (strcmp(op, OP_CODE_NEW_GRADE) == 0) {
            unsigned int id;
            char courseName[COURSE_NAME_MAX_LENGTH];
            unsigned int grade;
            scanf("%d", &id);
            scanf("%s", courseName);
            scanf("%d", &grade);

            Stud* stud = getStudent(students, id, currentIndex);
            if (stud == NULL) {
                printf(ERROR_NOT_AVAILABLE);
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
        } else if (strcmp(op, OP_CODE_NEW_INCOME) == 0) {
            unsigned int id;
            char workName[DATE_MAX_LENGTH];
            float income;
            scanf("%d", &id);
            scanf("%s", workName);
            scanf("%f", &income);


            Stud* stud = getStudent(students, id, currentIndex);
            if (stud == NULL) {
                printf(ERROR_NOT_AVAILABLE);
                destructStudents(students, currentIndex);
                return 0;
            }
            Income newIncome;
            strcpy(newIncome.date, workName);
            newIncome.amount = income;
            addToList(createIncomeNode, compareIncomeNode, getNextIncomeNode, setNextIncomeNode, &newIncome, (void **) &(stud->incomesList));

            stud->insertsTotal += income;
            stud->insertsCount++;
            stud->averageOfInserts = stud->insertsTotal / stud->insertsCount;
        } else if (strcmp(op, OP_CODE_WANTED_STUD) == 0) {
            unsigned int id;
            scanf("%d", &id);
            Stud* stud = getStudent(students, id, currentIndex);
            if (stud != NULL) {
                printStudent(stud);
            } else {
                printf(ERROR_NOT_AVAILABLE);
                destructStudents(students, currentIndex);
                return 0;
            }
        } else if (strcmp(op, OP_CODE_PRINT_ARRAY) == 0) {
            printAllStudents(students, currentIndex);
        } else if (strcmp(op, OP_CODE_SORT_ARRAY) == 0) {
            char sortBy[SORT_BY_LENGTH + 1];
            scanf("%s", sortBy);
            if (strcmp(sortBy, OP_CODE_SORT_BY_INCOME_ASC) == 0)
                sortArray(compareByIDAscending, students, currentIndex);
            else if (strcmp(sortBy, OP_CODE_SORT_BY_INCOME_DES) == 0)
                sortArray(compareByIDDescending, students, currentIndex);
            else if (strcmp(sortBy, OP_CODE_SORT_BY_GRADE_ASC) == 0)
                sortArray(compareByAvgGradeAscending, students, currentIndex);
            else if (strcmp(sortBy, OP_CODE_SORT_BY_GRADE_DES) == 0)
                sortArray(compareByAvgGradeDescending, students, currentIndex);
        }
        scanf("%s", op);
    }
    destructStudents(students, currentIndex);
    return 0;
}

void destructStudents(Stud students[], int size) {
    for (int i = 0; i < size; ++i) {
        destructLinkedList(getNextGradeNode, students[i].gradesList);
        destructLinkedList(getNextIncomeNode, students[i].incomesList);
    }
}
