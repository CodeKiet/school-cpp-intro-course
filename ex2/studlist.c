/**
 * Student Name: Eitan Sternlicht
 * ID: 204070635
 * Exercise: 2
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "list.h"

/**
 * Generically inserts data into list in ascending order
 * @param createNode function to create a node
 * @param compare function to compare two nodes
 * @param getNext function to return the next node given a node
 * @param setNext function to set next node to given data
 * @param data data to add to list
 * @param list pointer to pointer to head of list
 */
void addToList(void* (*createNode)(void* data), int (*compare)(void *a1, void *a2),
               void* (*getNext)(void*), void (*setNext)(void* node, void* data), void *data, void **list) {
    void *node = createNode(data);
    void *head = *list;
    if (head == NULL) { // if list is empty
        *list = node;
    }
    else if (compare(head, node)){
        // if first element is greater than node to add (meaning we need to add node to head of list)
        setNext(node, *list);
        *list = node;
    } else {
        // node will be inserted someplace other than head
        void *current = head;
        while (getNext(current) != NULL && compare(node, getNext(current))) {
            // loop until we are at the end of the list OR until we have found an element greater than us
            // basically, current will be the place to put the new node in
            current = getNext(current);
        }
        setNext(node, getNext(current));
        setNext(current, node);
    }
}
/**
 * Generically prints list
 * @param list
 * @param print_item
 * @param get_next
 */
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
void printStudent(Stud *stud) {
    printf("id: %d\n", stud->id);
    print_list(stud->gradesList, printGradeNode, getNextGradeNode);
    printf("\n");
    print_list(stud->incomesList, printIncomeNode, getNextIncomeNode);
}

void printGradeNode(void *gradeNode) {
    Grade g = ((struct GradeNode*)gradeNode)->grade;
    printf("%s %d", g.courseName, g.grade);
}
void printIncomeNode(void *incomeNode) {
    Income i = ((struct IncomeNode*)incomeNode)->income;
    printf("%s %f", i.date, i.amount);
}
// true if success, false if failed
bool addStudent (Stud students[], int currentIndex, unsigned int id) {
    for (int i = 0; i < currentIndex; ++i) {
        if (students[i].id == id) {
            printf(ERROR_DOUBLE_STUD);
            return false;
        }
    }
    if (currentIndex == N)
        return false; // reached end of list
    students[currentIndex] = newStudent(id);
    return true;
}
/**
 *
 * @param students
 * @param id of student to get
 * @param currentIndex ammount of students in array right now
 * @return
 */
Stud* getStudent(Stud students[], int id, int currentIndex) {
    for (int i = 0; i < currentIndex; ++i) {
        if (students[i].id == id)
            return &students[i];
    }
    return NULL;
}
/**
 *
 * @param students
 * @param currentIndex ammount of students in array right now
 */
void printAllStudents(Stud students[], int currentIndex) {
    if (currentIndex == 0)
        return;
    printStudent(&students[0]);
    for (int i = 1; i < currentIndex; ++i) {
        printf("\n");
        printStudent(&students[i]);
    }
}
void* createIncomeNode(void* data) {
    Income i;
    i.amount = ((Income*)data)->amount;
    strcpy(i.date, ((Income*)data)->date);

    struct IncomeNode* nd =
            (struct IncomeNode*)malloc(sizeof(struct IncomeNode));
    assert(nd != NULL);

    nd->income = i;
    nd->next = NULL;
    return nd;
}
void* createGradeNode(void* data) {
    Grade g;
    g.grade = ((Grade*)data)->grade;
    strcpy(g.courseName, ((Grade*)data)->courseName);

    struct GradeNode* nd =
            (struct GradeNode*)malloc(sizeof(struct GradeNode));
    assert(nd != NULL);

    nd->grade = g;
    nd->next = NULL;
    return nd;
}
void* getNextGradeNode(void* node) {
    return ((struct GradeNode*)node)->next;
}
void* getNextIncomeNode(void* node) {
    return ((struct IncomeNode*)node)->next;
}
void setNextGradeNode(void* node, void* data) {
    ((struct GradeNode*)node)->next = data;
}
void setNextIncomeNode(void* node, void* data) {
    ((struct IncomeNode*)node)->next = data;
}
bool compareByAvgGradeAscending(const Stud* a, const Stud* b) {
    return a->averageOfGrades > b->averageOfGrades;
}
bool compareByAvgGradeDescending(const Stud* a, const Stud* b) {
    return a->averageOfGrades < b->averageOfGrades;
}
bool compareByIDAscending(const Stud* a, const Stud* b) {
    return a->id > b->id;
}
bool compareByIDDescending(const Stud* a, const Stud* b) {
    return a->id < b->id;
}
bool compareGradeNode (void *a1, void *a2) {
    return ((struct GradeNode*)a1)->grade.grade > ((struct GradeNode*)a2)->grade.grade;
}
bool compareIncomeNode (void *a1, void *a2) {
    return ((struct IncomeNode*)a1)->income.amount > ((struct IncomeNode*)a2)->income.amount;
}
/**
 * simple o(n^2) sort
 * @param compare comparator function
 * @param students
 * @param size ammount of students in array
 */
void sortArray(int (*compare)(const Stud* a, const Stud* b), Stud students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (compare(&students[i], &students[j])) {
                // swap
                Stud temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

}

/**
 * ctor for Student(int id)
 * @param id
 * @return
 */
Stud newStudent(unsigned int id) {
    return (Stud)
            { .id = id
                    , .averageOfGrades = 0
                    , .averageOfInserts = 0
                    , .gradesList = NULL
                    , .incomesList = NULL
            };
}

// Generically free any list
void destructLinkedList(void* (*getNext)(void*), void* list) {
    void* temp;
    while (list != NULL) {
        temp = list;
        list = getNext(list);
        free(temp);
    }
}