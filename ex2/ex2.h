#define COURSE_NAME_MAX_LENGTH 20
#define WORK_NAME_MAX_LENGTH 20


typedef struct
{
    int id;
    float averageOfGrades;
    float averageOfInserts;
    struct GradeNode* gradesList;
    struct IncomeNode* incomesList;

} Stud;

struct Grade
{
    char courseName[COURSE_NAME_MAX_LENGTH];
    unsigned int grade;
};

struct GradeNode
{
    struct Grade data;
    struct GradeNode* next;
};

struct Income
{
    double amount;
    char workName[WORK_NAME_MAX_LENGTH];
};

struct IncomeNode
{
    struct Income data;
    struct IncomeNode* next;
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
