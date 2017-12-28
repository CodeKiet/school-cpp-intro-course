# Exercise #1 Read Me


ex2
=====
### Program Overview:
    This program stores and lets the user manage a database of students (max 30 atm).
    Each student has a unique ID
    a list of grades for courses he/she is taking
    a list of income statements.
    Internally, the program will keep an average of both income and grades live.
    The program provides a simple command line API to interact with the database allowing for
    functionality such as adding students, grades, incomes, sorting and printing the database.


### Input:
	ns <id>
	    creates a new student with id
        id = unsigned integer

	ng <id> <course_name> <grade>
	    creates a new grade for a student
	    id = unsigned int
	    course_name = string (max 20 chars)
	    grade = unsigned int 0 - 100

	ni <id> <date> <income>
	    creates a new income for a student
	    id = unsigned integer
	    date = string (max 20 chars)
	    income = float

	ws <id>
	    prints a wanted student
	    id = unsigned integer

	pa
	    prints entire database of students

	sa <i, g> <a, d>
	    sorts database by params
	    e.g. sa gd (sorts students array by student grade average in descending order - highest avg first)

	end
	    ends program



### Source code:
```
ex2.c  // main() and destruct database function only
list.c // all functions related to database management (stored as an array in memory)
list.h
```

### Functions:
```
main(void) // main api for routing interactions with the database
destructStudents(Stud students[], int size) // frees memory of students array

//list functions
Stud newStudent(unsigned int id) // helper function for creating an empty student by ID
void print_list(void* list, void (*print_item)(void* item), void* (*get_next)(void* item)); generic function to print any list
void printGradeNode(void *gradeNode); // prints a GradeNode
void printIncomeNode(void *incomeNode); // prints an IncomeNode
bool addStudent (Stud students[], int currentIndex, unsigned int id); // adds a student to database, returns false if failed (student already exists or full)
Stud* getStudent(Stud students[], int id, int currentIndex); // returns requested student from array by ID (NULL if not found)
int compareGradeNode (void *a1, void *a2); compares two grades, return a1 > a2
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
void* createGradeNode(void* data);
void* createIncomeNode(void* data);
// function that generically adds data to a list
void addToList(void* (*createNode)(void* data), int (*compare)(void *a1, void *a2), void* (*getNext)(void*), void (*setNext)(void* node, void* data), void *data, void **list);
void sortArray(int (*compare)(const Stud* a, const Stud* b), Stud students[], int size); // simple sort
void destructStudents(Stud students[], int); // free mem of all allocated lists
void destructLinkedList(void* (*getNext)(void*), void* list); // Generically free any list
```
