#define COURSE_NAME_MAX_LENGTH 20
#define WORK_NAME_MAX_LENGTH 20



typedef struct
{
    unsigned int id;
    float averageOfGrades;
    float averageOfInserts;
    unsigned int gradeCount;
    unsigned int incomeCount;
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
    double amount;
    char workName[WORK_NAME_MAX_LENGTH];
} Income;

struct IncomeNode
{
    Income* income;
    struct IncomeNode* next;
    struct IncomeNode* prev;
};

struct GradeNode
{
    Grade grade;
    struct GradeNode* next;
    struct GradeNode* prev;
};
enum Ordering {
    GT,
    LT,
    EQ
};
enum SortDirection {
    Ascending,
    Descending
};
enum SortBy {
    ID,
    AverageOfGrades
};

void newIncome(int id, char* date, double amount);
void wantedStudent(int id);
void printArray();
// part B
void sortArray(enum Ordering (*compare)(const Stud a, const Stud b), enum SortBy sb, enum SortDirection sd);
int sortArray_(enum Ordering (*cmp)(const Stud s1, const Stud s2));
void addIncome(Stud stud, Income income);
struct Node* createNode(void *data);
void print_list(void* list, void (*print_item)(void* item), void* (*get_next)(void* item));
void printGradeNode(void *gradeNode);
void* getNextGradeNode(void* node);
void addGrade(void **gradesList, Grade data);