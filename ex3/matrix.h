/**
 * Student Name: Eitan Sternlicht
 * ID: 204070635
 * Exercise: 3
 */
#ifndef _MATRIX_H
#define _MATRIX_H

#include <string>
using namespace std;

#define DEFAULT_VALUE_IN_MATRIX 0
#define ARROWHEAD_MATTYPE "Arrowhead"
#define TOEPLITZ_MATTYPE "Toeplitz"
#define ANY_MATTYPE "any"
#define ERROR_NOT_AVAILABLE "NA"
#define ERROR_EXIT_CODE 1

class Matrix {
private:
    double **_array;
    string _matType;
    int _rows;
    int _cols;
    bool isToeplitz();
    bool isArrowhead();
    bool isMatInvalid();

public:
    Matrix(int rows, int cols, string matType);
    void setElement(int i, int j, double data);
    double getElement(int i, int j);
    void add(Matrix& other, Matrix& result);
    void rowShift(const int shiftSize);
    void colShift(const int shiftSize);
    bool isA(string matType);
    void print();

    ~Matrix();
};
#endif //_MATRIX_H
