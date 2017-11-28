#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "list.h"

Stud newStudent(unsigned int id) {
    return (Stud)
            { .id = id
                    , .averageOfGrades = 0
                    , .averageOfInserts = 0
                    , .gradesList = NULL
                    , .incomesList = NULL
            };
}


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

void printGradeNode(void *gradeNode) {
    struct GradeNode* gn = gradeNode;
    Grade g = gn->grade;
    printf("%s %d", g.courseName, g.grade);
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
void* createIncomeNode(void* data) {
    Income i;
    i.amount = ((Income*)data)->amount;
    strcpy(i.workName, ((Income*)data)->workName);

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
int compareGradeNode (void *a1, void *a2) {
    return ((struct GradeNode*)a1)->grade.grade > ((struct GradeNode*)a2)->grade.grade;
}
int compareIncomeNode (void *a1, void *a2) {
    return ((struct IncomeNode*)a1)->income.amount > ((struct IncomeNode*)a2)->income.amount;
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
void addToList(void* (*createNode)(void* data), int (*compare)(void *a1, void *a2), void* (*getNext)(void*), void (*setNext)(void* node, void* data), void *data, void **list) {
    void *node = createNode(data);
    void *head = *list;
    if (head == NULL) { // if list is empty
        *list = node;
    }
    else if (compare(head, node)){ // if first element is greater than node to add (meaning we need to add node to head of list)
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
int compareByAvgGradeAscending(const Stud* a, const Stud* b) {
    if (a->averageOfGrades > b->averageOfGrades)
        return 1;
    if (a->averageOfGrades == b->averageOfGrades)
        return 0;
    return -1;
}
int compareByAvgGradeDescending(const Stud* a, const Stud* b) {
    if (a->averageOfGrades < b->averageOfGrades)
        return 1;
    if (a->averageOfGrades == b->averageOfGrades)
        return 0;
    return -1;
}
int compareByIDAscending(const Stud* a, const Stud* b) {
    if (a->id > b->id)
        return 1;
    if (a->id == b->id)
        return 0;
    return -1;
}
int compareByIDDescending(const Stud* a, const Stud* b) {
    if (a->id < b->id)
        return 1;
    if (a->id == b->id)
        return 0;
    return -1;
}
void sortArray(int (*compare)(const Stud* a, const Stud* b), Stud students[], int size) {
    sortArray_(compare, students, 0, size);
}
void sortArray_(int (*compare)(const Stud* a, const Stud* b), Stud students[], int i, int j) {
    if (i < j) {
        int mid=(i+j)/2;
        sortArray_(compare, students,i,mid);        //left recursion
//        printf("\n 1st half: \n");
        printAllStudents(students, mid);

        sortArray_(compare, students,mid+1,j);    //right recursion
//        printf("\n 2nd half: \n");
        printAllStudents(students, j);

        merge(compare, students,i,mid,mid+1,j);
    }
}
//// Merges two subarrays of arr[].
//// First subarray is arr[l..m]
//// Second subarray is arr[m+1..r]
//
void merge(int (*compare)(const Stud* a, const Stud* b), Stud a[],int i1,int j1,int i2,int j2)
{
    Stud temp[50];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;

    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(compare(&a[j], &a[i]))
            temp[k++]= a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];

    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];

    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}


void destructLinkedList(void* (*getNext)(void*), void* list) {
    void *temp;
    while (list != NULL) {
        temp = list;
        list = getNext(list);
        free(temp);
    }
}