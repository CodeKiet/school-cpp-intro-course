#define COURSE_NAME_MAX_LENGTH 20
#define WORK_NAME_MAX_LENGTH 20

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
    char workName[WORK_NAME_MAX_LENGTH];
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

void newIncome(int id, char* date, double amount);

// part B

void print_list(void* list, void (*print_item)(void* item), void* (*get_next)(void* item));
void printGradeNode(void *gradeNode);

int addStudent (Stud students[], int currentIndex, unsigned int id);
Stud* getStudent(Stud students[], int id, int currentIndex);
int compareGradeNode (void *a1, void *a2);
int compareIncomeNode (void *a1, void *a2);
void* getNextGradeNode(void* node);
void* getNextIncomeNode(void* node);
void setNextGradeNode(void* node, void* data);
void setNextIncomeNode(void* node, void* data);

void printStudent(Stud *stud);
void printAllStudents(Stud students[], int currentIndex);
int compareByAvgGradeAscending(const Stud* a, const Stud* b);
int compareByAvgGradeDescending(const Stud* a, const Stud* b);
int compareByIDAscending(const Stud* a, const Stud* b);
int compareByIDDescending(const Stud* a, const Stud* b);
//void addGrade(void **gradesList, void* data);
//void addIncome(void **incomeList, void* data);
void* createGradeNode(void* data);
void* createIncomeNode(void* data);
//void addToList(void (*addFunc)(void **, void*), void *data, void **list);
void addToList(void* (*createNode)(void* data), int (*compare)(void *a1, void *a2), void* (*getNext)(void*), void (*setNext)(void* node, void* data), void *data, void **list);

void sortArray(int (*compare)(const Stud* a, const Stud* b), Stud students[], int size);
void sortArray_(int (*compare)(const Stud* a, const Stud* b), Stud students[], int l, int r);
void merge(int (*compare)(const Stud* a, const Stud* b), Stud a[],int i1,int j1,int i2,int j2);
void destructStudents(Stud students[], int);
void destructLinkedList(void* (*getNext)(void*), void* list);