#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "ex2.h"
#include <string.h>
#define N 30


// TODO free malloc, asset malloc worked

Stud newStudent(int id) {
    return (Stud)
            { .id = id
            , .averageOfGrades = 0
            , .averageOfInserts = 0
            , .gradesList = NULL
            , .incomesList = NULL
            };
}


//
//void* getNextGradeNode(void* node) {
//    struct GradeNode* n = (struct GradeNode*) node;
//    return (void*)(n->next);
//}
//void printGradeNode(void *gradeNode) {
//    struct GradeNode* gn = (struct GradeNode*)gradeNode;
//    printf("%s %d", gn->data.courseName, gn->data.grade);
//}
void printStudent(Stud *stud) {
    printf("id: %d\n", stud->id);
    print_list(stud->gradesList, printGradeNode, getNextGradeNode);
}

void print_list(void* list, void (*print_item)(void* item), void* (*get_next)(void* item)) {
    void* current = list;
    if (current == NULL)
        return;
    print_item(current);
    current = get_next(current);

    while (current != NULL) {
        printf(", ");
        print_item(current);
        current = get_next(current);
    }
}


struct IncomeNode* createIncomeNode(Income* income) {
    struct IncomeNode* nd =
            (struct IncomeNode*)malloc(sizeof(struct IncomeNode));
    assert(nd != NULL);

    nd->income = income;
    nd->next = NULL;
    nd->prev = NULL;

    return(nd);
}
struct GradeNode* createGradeNode(Grade grade) {
    struct GradeNode* nd =
            (struct GradeNode*)malloc(sizeof(struct GradeNode));
    assert(nd != NULL);


    (*nd).grade = grade;
    nd->next = NULL;
    nd->prev = NULL;

    return (nd);
}
void addGrade(void **gradesList, Grade data) {
    struct GradeNode *node = createGradeNode(data);
    struct GradeNode *head = *gradesList;
    if (head == NULL) {
        *gradesList = node;
    }
    else if (head->grade.grade > node->grade.grade){
        node->next = *gradesList;
        *gradesList = node;
        node->prev = *gradesList;
        node->next->prev = node;
    } else {
        struct GradeNode* current = head;
        while (current->next != NULL && current->next->grade.grade < node->grade.grade) {
            current = current->next;
        }
        node->next = current->next;
        node->prev = current;
        if (node->next != NULL)
            node->next->prev = node;
        current->next = node;
    }
}
void printGradeNode(void *gradeNode) {
    struct GradeNode* gn = gradeNode;
    Grade g = gn->grade;
    printf("%s %d", g.courseName, g.grade);
}

void* getNextGradeNode(void* node) {
    return ((struct GradeNode*)node)->next;
}

void test() {
    Stud stud1 = newStudent(1234);
    Grade stud1gradeInA = {"testA", 44};
    Grade stud1gradeInB = {"testB", 88};
    Grade stud1gradeInC = {"testC", 66};


    addGrade((void **) &(stud1.gradesList), stud1gradeInC);
    addGrade((void **) &(stud1.gradesList), stud1gradeInB);
    addGrade((void **) &(stud1.gradesList), stud1gradeInA);

    print_list(stud1.gradesList, printGradeNode, getNextGradeNode);
}
/**
 * returns next available index
 * @return if student exists, or if array is full - returns -1
 */
int getNextAvailableIndex(Stud students[], int size, int id) {


}
/**
 *
 * @param students
 * @param currentIndex
 * @param id
 * @return 1 if success, 0 if failed
 */
int addStudent (Stud students[], int currentIndex, unsigned int id) {
    for (int i = 0; i < currentIndex; ++i) {
        if (students[i].id == id) {
            printf("DOUBLESTUD");
            return 0;
        }
    }
    students[currentIndex] = newStudent(id);
    return 1;
}

Stud* getStudent(Stud students[], int id, int currentIndex) {
    for (int i = 0; i < currentIndex; ++i) {
        if (students[i].id == id)
            return &students[i];
    }
    return NULL;
}

void printAllStudents(Stud students[], int currentIndex) {
    if (currentIndex == 0)
        return;
    printStudent(&students[0]);
    for (int i = 1; i < currentIndex; ++i) {
        printf("\n");
        printStudent(&students[i]);
    }
}

int main() {
    Stud students[N];
    int currentIndex = 0;

    char op[3];

    scanf("%s", op);

    while (strcmp(op, "end") != 0) {
        if (strcmp(op, "ns") == 0) {
            unsigned int id;
            scanf("%u", &id);
            Stud s = newStudent(id);
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
                return 0;
            }

            Grade newGrade;
            strcpy(newGrade.courseName, courseName);
            newGrade.grade = grade;
            addGrade((void **) &(stud->gradesList), newGrade);

        } else if (strcmp(op, "ni") == 0) {
        } else if (strcmp(op, "ws") == 0) {
            unsigned int id;
            scanf("%d", &id);
            Stud* stud = getStudent(students, id, currentIndex);
            if (stud != NULL) {
                printStudent(stud);
            } else {
                printf("NA");
                return 0;
            }

        } else if (strcmp(op, "pa") == 0) {
            printAllStudents(students, currentIndex);
        } else if (strcmp(op, "sa") == 0) {

        }
        scanf("%s", op);
    }


    return 0;
}
