/**
 * Student Name: Eitan Sternlicht
 * ID: 204070635
 * Exercise: 4
 */

#include <string>
#include <iostream>
using namespace std;

#define DEFAULT_VALUE_IN_MATRIX 0
#define ARROWHEAD_MATTYPE "Arrowhead"
#define TOEPLITZ_MATTYPE "Toeplitz"
#define ANY_MATTYPE "any"
#define ERROR_NOT_AVAILABLE "NA"
#define ERROR_EXIT_CODE 1

#ifndef _SMATRIX
#define _SMATRIX
// A node of a sparse matrix.
class MNode {
public:
    double _data;
    int _indexI, _indexJ;
    MNode* _nextRow, *_nextCol;
    MNode(double data, int i, int j);
};


// A sparse matrix. a mathematical matrix object which is implemented
// in a way that saves memory if the matrix is sparse. The implementation
// consists of linked lists of elements which are not zero.
class SMatrix {
private:
    MNode** _rowHead, **_colHead; // _rowHead : array of head-pointers for the rows lists.
    int _rowSize, _colSize; // _rowSize - number of rows
    int _elemNum; // number of entries not containing zero
    string _matType;
    bool _valid; // was matrix constructed correctly

    void insertNode(MNode* n);
    void removeElement(int i, int j);
    void setValue(int i, int j, double data);
    bool IsExist(int i, int j) const;
    void copy(const SMatrix &other);
    bool isToeplitz() const;
    bool isArrowhead() const;
    bool isMatInvalid() const;
public:

    // construct a 'rows X cols' matrix.
    SMatrix(int rows, int cols, string matType);

    SMatrix(const SMatrix &other);

    // destroy this matrix.
    ~SMatrix();

    // set the (i,j) element to be 'data'
    void setElement(int i, int j, double data);

    // return the (i,j) element
    double getElement(int i, int j) const;

    // rowShift
    void rowShift(int shiftSize);

    // colShift
    void colShift(int shiftSize);

    // isA matType
    bool isA(string matType) const;

    // prints SMatrix size in bytes
    void sizeInBytes() const;

    // print columns as linked lists
    void printColumnsIndexes() const;

    // print rows as linked lists
    void printRowsIndexes() const;

    // operator = for SMatrix
    SMatrix& operator=(const SMatrix &other);

    // operator + for SMatrix
    SMatrix operator+(const SMatrix &other) const;

    // operator << friend function for SMatrix
    friend ostream& operator<<(ostream& os, const SMatrix& mat);
};


#endif // _SMATRIX_H
