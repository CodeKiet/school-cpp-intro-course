/**
 * Student Name: Eitan Sternlicht
 * ID: 204070635
 * Exercise: 5
 */
#include <cassert>
#include <iostream>

#define DEFAULT_VALUE_IN_MATRIX 0
#define ARROWHEAD_MATTYPE "Arrowhead"
#define TOEPLITZ_MATTYPE "Toeplitz"
#define ANY_MATTYPE "any"
#define ERROR_NOT_AVAILABLE "NA"
#define ERROR_EXIT_CODE 1
using namespace std;
class Matrix {
private:
    double **_array;
    string _matType;
    int _rows;
    int _cols;

public:
Matrix::Matrix(int rows, int cols, string matType) {
    this->_rows = rows;
    this->_cols = cols;
    this->_matType = matType;
    _array = new double*[rows];
    assert(_array != nullptr);
    for (int i = 0; i < rows; ++i) {
        _array[i] = new double[cols];
        assert(_array[i] != nullptr);
        // create zero matrix
        for (int j = 0; j < cols; ++j)
            _array[i][j] = DEFAULT_VALUE_IN_MATRIX;
    }
}

/**
 * Mat[i, j] = data (checks that it doesn't violate rules of matType)
 * @param i
 * @param j
 * @param data
 */
void Matrix::setElement(int i, int j, double data) {
    if (   (i < _rows && j < _cols && i >= 0 && j >= 0)
        && (   (_matType == ARROWHEAD_MATTYPE && (i == 0 || j == 0 || i == j || data == 0))
            || (_matType == TOEPLITZ_MATTYPE && (   _array[i][j] == data
                                           || (i == 0 && j == _cols - 1)
                                           || (j == 0 && i == _rows - 1)))
            || (_matType == ANY_MATTYPE)))
                _array[i][j] = data;
    else
        cerr << ERROR_NOT_AVAILABLE << endl;
}
/**
 *
 * @param i row
 * @param j col
 * @return
 */
double Matrix::getElement(int i, int j) {
    if (i < _rows && i >= 0 && j < _cols && j >= 0)
        return _array[i][j];

    for (int k = 0; k < _rows; ++k)
        delete[] _array[k];
    delete[] _array;

    cerr << ERROR_NOT_AVAILABLE << endl;
    exit(ERROR_EXIT_CODE);
}
/**
 * adds two matrices together
 * result = this + other
 */
void Matrix::add(Matrix& other, Matrix& result) {
    if (_cols == other._cols && _cols == result._cols &&
        _rows == other._rows && _rows == result._rows) {
        for (int i = 0; i < _rows; ++i)
            for (int j = 0; j < _cols; ++j)
                result._array[i][j] = _array[i][j] + other._array[i][j];

        if (result.isMatInvalid()) {
            for (int i = 0; i < _rows; ++i)
                for (int j = 0; j < _cols; ++j)
                    result._array[i][j] -= (_array[i][j] + other._array[i][j]);
        }
    }

    else
        cerr << ERROR_NOT_AVAILABLE << endl;
}
/**
 * move all rows by shiftSize
 * @param shiftSize negative - shift up, positive - shift down
 */
void Matrix::rowShift(const int shiftSize) {
    const int positiveShiftSize = ((shiftSize % _rows) + _rows) % _rows;

    double **copy = new double*[_rows];
    assert(copy != nullptr);
    for (int i = 0; i < _rows; ++i)
        copy[i] = _array[i];

    for (int j = 0; j < _rows; ++j)
        _array[(j + positiveShiftSize) % _rows] = copy[j];
    delete[] copy;

    if (isMatInvalid()) // if matrix breaks rules after shift - reverse back
        rowShift(-shiftSize);
}
/**
 * move all cols by shiftSize
 * @param shiftSize negative - shift up, positive - shift down
 */
void Matrix::colShift(const int shiftSize) {
    const int positiveShiftSize = ((shiftSize % _cols) + _cols) % _cols;

    double **copy = new double*[_rows];
    assert(copy != nullptr);
    for (int i = 0; i < _rows; ++i) {
        copy[i] = new double[_cols];
        assert(copy[i] != nullptr);
        for (int j = 0; j < _cols; ++j)
            copy[i][j] = _array[i][j];
    }

    for (int j = 0; j < _cols; ++j)
        for (int i = 0; i < _rows; ++i)
            _array[i][(j + positiveShiftSize) % _cols] = copy[i][j];

    for (int i = 0; i < _rows; ++i)
        delete[] copy[i];
    delete[] copy;

    if (isMatInvalid()) // if matrix breaks rules after shift - reverse back
        colShift(-shiftSize);
}

bool Matrix::isA(string matType) {
    if (matType == ARROWHEAD_MATTYPE)
        return isArrowhead();
    if (matType == TOEPLITZ_MATTYPE)
        return isToeplitz();
    return matType == ANY_MATTYPE;
}
/**
 * simple print function represents matrix as comma seperated list
 */
void Matrix::print() {
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            cout << _array[i][j];
            if (j != _cols - 1)
                cout << ',';
        }
        cout << endl;
    }
}
Matrix::~Matrix() {
    for (int i = 0; i < _rows; ++i)
        delete[] _array[i];
    delete[] _array;
}
/**
 * private helper function to validate Toeplitz Matrix rules
 */
bool Matrix::isToeplitz() {
    for (int i = 0; i < _rows - 1; ++i)
        for (int j = 0; j < _cols - 1; ++j)
            if (_array[i][j] != _array[i + 1][j + 1])
                return false;
    return true;
}
/**
 * private helper function to validate Arrowhead Matrix rules
 */
bool Matrix::isArrowhead() {
    if (_rows != _cols) // must be square matrix
        return false;
    for (int i = 1; i < _rows; ++i)
        for (int j = 1; j < _cols; ++j)
            if (i != j && _array[i][j] != 0)
                return false;
    return true;
}
/**
 * private helper function to validate check if matrix has specific rules and if it voilates them
 */
bool Matrix::isMatInvalid() {
    return    (_matType == ARROWHEAD_MATTYPE && !isA(ARROWHEAD_MATTYPE))
              || (_matType == TOEPLITZ_MATTYPE && !isA(TOEPLITZ_MATTYPE));

}