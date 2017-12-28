/**
 * Student Name: Eitan Sternlicht
 * ID: 204070635
 * Exercise: 2
 */
#define N 30
#define COURSE_NAME_MAX_LENGTH 20
#define DATE_MAX_LENGTH 20
#define ERROR_DOUBLE_STUD "DOUBLESTUD"
#define OP_LENGTH 3
#define SORT_BY_LENGTH 2
#define ERROR_NOT_AVAILABLE "NA"
#define OP_CODE_END_PROGRAM "end"
#define OP_CODE_NEW_STUDENT "ns"
#define OP_CODE_NEW_GRADE "ng"
#define OP_CODE_NEW_INCOME "ni"
#define OP_CODE_PRINT_ARRAY "pa"
#define OP_CODE_WANTED_STUD "ws"
#define OP_CODE_SORT_ARRAY "sa"
#define OP_CODE_SORT_BY_GRADE_ASC "ga"
#define OP_CODE_SORT_BY_GRADE_DES "gd"
#define OP_CODE_SORT_BY_INCOME_ASC "ia"
#define OP_CODE_SORT_BY_INCOME_DES "id"

typedef struct
{
    unsigned int id;
    float averageOfGrades;
    float averageOfInserts;
    unsigned int insertsCount;
    float insertsTotal;
    unsigned int gradesCount;
    unsigned int gradesTotal;
    struct GradeNode* gradesList;
    struct IncomeNode* incomesList;
} Stud;

typedef struct
{
    char courseName[COURSE_NAME_MAX_LENGTH];
    unsigned int grade;
} Grade;
typedef struct
{
    float amount;
    char date[DATE_MAX_LENGTH];
} Income;

struct IncomeNode
{
    Income income;
    struct IncomeNode* next;
};

struct GradeNode
{
    Grade grade;
    struct GradeNode* next;
};

Stud newStudent(unsigned int id);
void print_list(void* list, void (*print_item)(void* item), void* (*get_next)(void* item));
void printGradeNode(void *gradeNode);
void printIncomeNode(void *incomeNode);
bool addStudent (Stud students[], int currentIndex, unsigned int id);
Stud* getStudent(Stud students[], int id, int currentIndex);
bool compareGradeNode (void *a1, void *a2);
bool compareIncomeNode (void *a1, void *a2);
void* getNextGradeNode(void* node);
void* getNextIncomeNode(void* node);
void setNextGradeNode(void* node, void* data);
void setNextIncomeNode(void* node, void* data);

void printStudent(Stud *stud);
void printAllStudents(Stud students[], int currentIndex);
bool compareByAvgGradeAscending(const Stud* a, const Stud* b);
bool compareByAvgGradeDescending(const Stud* a, const Stud* b);
bool compareByIDAscending(const Stud* a, const Stud* b);
bool compareByIDDescending(const Stud* a, const Stud* b);
void* createGradeNode(void* data);
void* createIncomeNode(void* data);
void addToList(void* (*createNode)(void* data), int (*compare)(void *a1, void *a2), void* (*getNext)(void*), void (*setNext)(void* node, void* data), void *data, void **list);

void sortArray(int (*compare)(const Stud* a, const Stud* b), Stud students[], int size);
void destructStudents(Stud students[], int);
void destructLinkedList(void* (*getNext)(void*), void* list);