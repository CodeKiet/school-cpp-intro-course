/**
 * Student Name: Eitan Sternlicht
 * ID: 204070635
 * Exercise: 4
 */
#include <iostream>
#include <cassert>
#include "SMatrix.h"
using namespace std;

// MNode constructor
MNode::MNode(double data, int i, int j) {
    _data = data;
    _indexI = i;
    _indexJ = j;
    _nextRow = nullptr;
    _nextCol = nullptr;
}

// SMatrix constructor
SMatrix::SMatrix(int rows, int cols, string matType) : _elemNum(0){
    if (rows <= 0 || cols <= 0 || (matType != ARROWHEAD_MATTYPE && matType != TOEPLITZ_MATTYPE && matType != ANY_MATTYPE)) {
        cerr << "NA";
        _valid = false;
        return;
    }
    _valid = true;
    _rowSize = rows;
    _colSize = cols;
    _matType = matType;

    _rowHead = new MNode*[rows];
    assert(_rowHead != nullptr);
    _colHead = new MNode*[cols];
    assert(_colHead != nullptr);

    for (int i = 0; i < rows; i++)
        _rowHead[i] = nullptr;
    for (int i = 0; i < cols; i++)
        _colHead[i] = nullptr;
}
/**
 * copy ctor helper
 * @param other
 */
void SMatrix::copy(const SMatrix &other) {
    _valid = other._valid;
    _rowSize = other._rowSize;
    _colSize = other._colSize;
    _matType = other._matType;
    _elemNum = other._elemNum;
    _rowHead = new MNode*[other._rowSize];
    assert(_rowHead != nullptr);
    _colHead = new MNode*[other._colSize];
    assert(_colHead != nullptr);

    for (int i = 0; i < _rowSize; i++)
        _rowHead[i] = nullptr;
    for (int i = 0; i < _colSize; i++)
        _colHead[i] = nullptr;

    for (int i = 0; i < _rowSize; i++) {
        for (MNode* p = other._rowHead[i]; p != nullptr; p = p->_nextRow) {
            auto *p1 = new MNode(p->_data, p->_indexI, p->_indexJ);
            assert(p1 != nullptr);
            insertNode(p1);
        }
    }
}
/**
 * copy ctor
 * @param other
 */
SMatrix::SMatrix(const SMatrix &other) {
    copy(other);
}
/**
 * equals overloading
 * @param other
 * @return
 */
SMatrix& SMatrix::operator=(const SMatrix &other) {
    if (&other == this)
        return *this;
    copy(other);
    return *this;
}

// remove element with (i,j) index from row and column
// separate cases: first element in list or in the middle
void SMatrix::removeElement(int i, int j) {
    MNode *prev = nullptr;
    MNode *colPtr = _colHead[j];               // keep the column linked list
    MNode *rowPtr = _rowHead[i];               // keep the row linked lst

    if (_colHead[j]->_indexI == i)             // if element is the first in column
        _colHead[j] = _colHead[j]->_nextCol;

    else {                                       // if element is not the first in column
        while (colPtr->_indexI != i) {          // find prev element on the column
            prev = colPtr;
            colPtr = colPtr->_nextCol;
        }
        prev->_nextCol = colPtr->_nextCol;     // connect the prev with the next
    }

    if (_rowHead[i]->_indexJ == j) {            // if element is the first in row
        rowPtr = _rowHead[i];
        _rowHead[i] = _rowHead[i]->_nextRow;
    }

    else {                                     // if element is not the first in row
        while (rowPtr->_indexJ != j) {         // find prev element on the row
            prev = rowPtr;
            rowPtr = rowPtr->_nextRow;
        }
        prev->_nextRow = rowPtr->_nextRow;    // connect the prev with the next
    }
    delete rowPtr;                            // delete the element only once
}

//add new node to both row and column
// separate cases: list is empty or not empty
void SMatrix::insertNode(MNode* n) {
    MNode* p = _rowHead[n->_indexI];   // the i row
    if (p != nullptr) {                // there are elements in i row
        if (p->_indexJ > n->_indexJ) { // need to insert n at start, before existing elements
            n->_nextRow = p;
            _rowHead[n->_indexI] = n;
        }
        else {                         // need to inserst in the middle of the list or at end
            while (p->_nextRow && p->_nextRow->_indexJ < n->_indexJ)
                p = p->_nextRow;
            n->_nextRow = p->_nextRow;
            p->_nextRow = n;
        }
    }
    else                               // row is empty
        _rowHead[n->_indexI] = n;
    p = _colHead[n->_indexJ];          // the j column
    if (p != nullptr) {                 // there are elements in j col
        if (p->_indexI > n->_indexI) { // need to insert n at start, before existing elements
            n->_nextCol = p;
            _colHead[n->_indexJ] = n;
        }
        else {                         // need to inserst in the middle of the list or at end
            while (p->_nextCol && p->_nextCol->_indexI < n->_indexI)
                p = p->_nextCol;
            n->_nextCol = p->_nextCol;
            p->_nextCol = n;
        }
    }
    else                            // column is empty
        _colHead[n->_indexJ] = n;
}

// set value to exist element (i,j)
void SMatrix::setValue(int i, int j, double data) {
    MNode *ptr = _rowHead[i];

    while (ptr->_indexJ != j)          // find the element on the row
        ptr = ptr->_nextRow;
    ptr->_data = data;

}

// check if element (i,j) exists
bool SMatrix::IsExist(int i, int j) const{
    MNode *ptr = _rowHead[i];

    if (ptr == nullptr)
        return false;

    while (ptr && ptr->_indexJ < j)
        ptr = ptr->_nextRow;

    return ptr != nullptr && ptr->_indexJ == j;
}

// set the (i,j) element to be 'data'
void SMatrix::setElement(int i, int j, double data) {
    if (i<0 || i >= _rowSize || j<0 || j >= _colSize) {
        cerr << "NA";
        return;
    }

    bool found = IsExist(i, j);
    if (data == 0 && found) {
        _elemNum--;
        double d = getElement(i, j);
        removeElement(i, j);
        if (isMatInvalid()) {
            auto *n = new MNode(d, i, j);
            _elemNum++;
            insertNode(n);
            cerr << "NA";
            return;
        }
    }
    else if (data == 0 && !found)
        return;
    else if (data != 0 && found) {
        double d = getElement(i, j);
        setValue(i, j, data);
        if (isMatInvalid()) {
            setValue(i, j, d);
            cerr << "NA";
            return;
        }
    }
    else if (data != 0 && !found) {
        auto *n = new MNode(data, i, j);
        _elemNum++;
        insertNode(n);
        if (isMatInvalid()) {
            _elemNum--;
            removeElement(i, j);
            cerr << "NA";
            return;
        }
    }
}

// destroy this matrix.
SMatrix::~SMatrix() {
    if (_elemNum != 0) {
        //delete all nodes inside linked lists
        for (int i = 0; i < _rowSize; i++) {
            MNode* p = _rowHead[i], *p2;
            while (p) {
                p2 = p;
                p = p->_nextRow;
                delete p2;
            }
        }
    }
    if (_valid) {
        //delete array of linked lists
        delete[] _colHead;
        delete[] _rowHead;
    }
}
/**
 * @param mat to print
 */
ostream& operator<<(ostream& os, const SMatrix& mat) {
    for (int i = 0; i < mat._rowSize; i++) {
        for (int j = 0; j < mat._colSize; ++j) {
            double data = mat.getElement(i, j);
            os << data;
            if (j != mat._colSize - 1)
                os << ",";
        }
        os << endl;
    }
    return os;
}
/**
 * adds two matrices together
 * return (this + other)
 */
SMatrix SMatrix::operator+(const SMatrix &other) const {
    if (_rowSize != other._rowSize || _colSize != other._colSize || _matType != other._matType)
        exit(1);
    SMatrix result(_rowSize, _colSize, _matType);
    for (int i = 0; i < _rowSize; ++i) {
        for (int j = 0; j < _colSize; ++j) {
            result.setElement(i, j, getElement(i, j) + other.getElement(i, j));
        }
    }
    if (result.isMatInvalid())
        exit(1);
    return result;

}
/**
 *
 * @param i index
 * @param j index
 * @return element in matrix at (i, j) index
 */
double SMatrix::getElement(int i, int j) const {
    MNode *ptr = _rowHead[i];

    if (ptr == nullptr)
        return 0;

    while (ptr && ptr->_indexJ < j)
        ptr = ptr->_nextRow;

    if (ptr && ptr->_indexJ == j)
        return ptr->_data;
    return 0;
}
/**
 *
 * @param matType to test
 * @return true if matrix follows rules of mattype
 */
bool SMatrix::isA(string matType) const {
    if (matType == ARROWHEAD_MATTYPE)
        return isArrowhead();
    if (matType == TOEPLITZ_MATTYPE)
        return isToeplitz();
    return matType == ANY_MATTYPE;
}

/**
 *
 * @return true if matrix is an Toeplitz
 */
bool SMatrix::isToeplitz() const {
    for (int i = 0; i < _rowSize - 1; ++i)
        for (int j = 0; j < _colSize - 1; ++j)
            if (getElement(i, j) != getElement(i + 1, j + 1))
                return false;
    return true;
}
/**
 *
 * @return true if matrix is an Arrowhead
 */
bool SMatrix::isArrowhead() const {
//    if (_rowSize != _colSize) // must be square matrix
//        return false;
    for (int i = 1; i < _rowSize; ++i)
        for (int j = 1; j < _colSize; ++j)
            if (i != j && getElement(i, j) != 0)
                return false;
    return true;
}

bool SMatrix::isMatInvalid() const {
    return    (_matType == ARROWHEAD_MATTYPE && !isA(ARROWHEAD_MATTYPE))
              || (_matType == TOEPLITZ_MATTYPE && !isA(TOEPLITZ_MATTYPE));
}
/**
 * move all rows by shiftSize
 * @param shiftSize negative - shift up, positive - shift down
 */
void SMatrix::rowShift(const int shiftSize) {
    const int positiveShiftSize = ((shiftSize % _rowSize) + _rowSize) % _rowSize;

    SMatrix copy = *this;
    for (int i = 0; i < _rowSize; ++i)
        for (int j = 0; j < _colSize; ++j)
            setElement((i + positiveShiftSize) % _rowSize, j, copy.getElement(i, j));

    if (isMatInvalid()) // if matrix breaks rules after shift - reverse back
        rowShift(-shiftSize);
}
/**
 * move all cols by shiftSize
 * @param shiftSize negative - shift up, positive - shift down
 */
void SMatrix::colShift(const int shiftSize) {
    const int positiveShiftSize = ((shiftSize % _colSize) + _colSize) % _colSize;

    SMatrix copy = *this;
    for (int i = 0; i < _rowSize; ++i)
        for (int j = 0; j < _colSize; ++j)
            setElement(i, (j + positiveShiftSize) % _colSize, copy.getElement(i, j));

    if (isMatInvalid()) // if matrix breaks rules after shift - reverse back
        colShift(-shiftSize);
}
/**
 * prints size of this matrix in bytes
 */
void SMatrix::sizeInBytes() const {
    int sizeInBytes = sizeof(_rowHead[0])*_rowSize + sizeof(_colHead[0])*_colSize + sizeof(MNode) * _elemNum;
    cout << sizeInBytes;
}
/**
 * prints matrix based on rows index spec
 */
void SMatrix::printRowsIndexes() const {
    for (int i = 0; i < _rowSize; ++i) {
        cout << i << ": ";

        for (MNode *p = _rowHead[i]; p != nullptr; p = p->_nextRow)
            cout << "(" << p->_indexJ << "," << p->_data << ")" << "->";
        if (_rowHead[i] == nullptr)
            cout << "->";
        cout << endl;
    }
}
/**
 * prints matrix based on cols index spec
 */
void SMatrix::printColumnsIndexes() const {
    for (int i = 0; i < _colSize; ++i) {
        cout << i << ": ";

        for (MNode *p = _colHead[i]; p != nullptr; p = p->_nextCol)
            cout << "(" << p->_indexI << "," << p->_data << ")" << "->";
        if (_colHead[i] == nullptr)
            cout << "->";
        cout << endl;
    }
}




