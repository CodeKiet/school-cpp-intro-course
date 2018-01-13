#include <iostream>
#include "SMatrix.h"
using namespace std;




void checkConstructor();
void checkCopyConstructor();
void checkSetElement();
void checkGetElement();
void checkRowShift();
void checkColShift();
void checkIsA();
void checkSizeInBytes();
void checkPrintColumnsIndexes();
void checkPrintRowsIndexes();
void checkOperatorPlacement();
void checkOperatorPlus();

int main()
{

        std::cout.setf(std::ios::boolalpha);

        // construct a 'rows X cols' matrix.
        checkConstructor();

        // copy constructor
        checkCopyConstructor();

        // set the (i,j) element to be 'data'
        checkSetElement();

        //get element
//        checkGetElement();

        // rowShift
        checkRowShift();

        // colShift
        checkColShift();

        // isA matType
        checkIsA();

        //print the size of the matrix
        checkSizeInBytes();

        //print all matrix columns
        checkPrintColumnsIndexes();

        //print all matrix rows
        checkPrintRowsIndexes();

        //operator = for SMatrix
        checkOperatorPlacement();

        // operator + for SMatrix
        checkOperatorPlus();


    }


// construct a 'rows X cols' matrix.
    void checkConstructor() {
        cout << endl << " ===== constractur =======" << endl;
        SMatrix m1(2, 2, "any");
        cout << "m1:" << endl << m1 << endl;

        SMatrix m2(5, 4, "Toeplitz");
        cout << "m2:" << endl << m2 << endl;

        SMatrix m3(1, 3, "Arrowhead");
        cout << "m3:" << endl << m3 << endl;

        cout << "supposed to print NA: " << endl;
        SMatrix m4(10, 10, "fds");

        cout << "supposed to print NA: " << endl;
        SMatrix m5(-10, 10, "any");
    }

// copy constructor
    void checkCopyConstructor() {
        cout << endl << " ====== copy constractur =======" << endl;
        SMatrix m1(2, 2, "any");
        m1.setElement(0, 0, 4); m1.setElement(0, 1, 8);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2);
        cout << " matrix 'other': " << endl << m1 << endl;

        SMatrix m2(m1);
        cout << " matrix 'this' after copy, supposed to be the same: " << endl << m2 << endl;

    }

// set the (i,j) element to be 'data'
    void checkSetElement() {
        cout << endl << " ====== set Element =======" << endl;
        cout << "check matrix 'any': " << endl;
        SMatrix m1(3, 3, "any");
        m1.setElement(0, 0, 4); m1.setElement(0, 1, 8); m1.setElement(0, 2, 5);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2); m1.setElement(1, 2, 0);
        m1.setElement(2, 0, 5); m1.setElement(2, 1, 0); m1.setElement(2, 2, 9);
        cout << "The matrix 'any':" << endl << m1 << endl;

        cout << "check matrix 'Toeplitz': " << endl;
        SMatrix m2(3, 3, "Toeplitz");
        m2.setElement(0, 2, 4); m2.setElement(2, 0, 8);
        cout << "supposed to print NA: " << endl;
        m2.setElement(1, 0, 6);
        cout << "The matrix 'Toeplitz:" << endl << m2 << endl;

        cout << "check matrix 'Arrowhead': " << endl;
        SMatrix m3(3, 3, "Arrowhead");
        m3.setElement(0, 0, 4); m3.setElement(0, 2, 5);
        m3.setElement(1, 0, 6);	m3.setElement(1, 1, 2);
        m3.setElement(2, 0, 5); m3.setElement(2, 2, 9);
        cout << "supposed to print NA: " << endl;
        m3.setElement(1, 2, 6);
        cout << "supposed to print NA: " << endl;
        m3.setElement(1, 3, 0);
        cout << "The matrix 'Arrowhead:" << endl << m3 << endl;
    }


//get element
    void checkGetElement() {
        cout << endl << " ====== get Element =======" << endl;
        SMatrix m1(3, 3, "any");
        m1.setElement(0, 0, 4); m1.setElement(0, 1, 8); m1.setElement(0, 2, 5);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2); m1.setElement(1, 2, 0);
        m1.setElement(2, 0, 5); m1.setElement(2, 1, 0); m1.setElement(2, 2, 9);
        cout << "supposed to print 6: " << endl << m1.getElement(1, 0) << endl;
        cout << "supposed to print 9: " << endl << m1.getElement(2, 2) << endl;
        cout << "supposed to print 'NA' and to exit: " << endl;
        m1.getElement(-2, 2);
    }

// rowShift
    void checkRowShift() {
        cout << endl << " ===== shift row =======" << endl;
        SMatrix m1(5, 4, "any");
        m1.setElement(0, 2, 3); m1.setElement(0, 3, 3); m1.setElement(0, 1, 3);
        m1.setElement(1, 0, 5); m1.setElement(1, 2, 5); m1.setElement(1, 2, 5);
        m1.setElement(2, 0, 7); m1.setElement(2, 1, 7); m1.setElement(2, 3, 7);
        m1.setElement(3, 0, 9); m1.setElement(3, 1, 9); m1.setElement(3, 2, 9);
        cout << "the original Matrix" << endl << m1 << endl;

        cout << endl << "after 3 shift row Matrix (down):" << endl;
        m1.rowShift(3);
        cout << m1;

        cout << endl << "after more 6 shift row Matrix (down):" << endl;
        m1.rowShift(6);
        cout << m1;

        cout << endl << "after more 2 shift row Matrix (up):" << endl;
        m1.rowShift(-2);
        cout << m1;

        cout << "check matrix 'Toeplitz': " << endl;
        SMatrix m2(3, 3, "Toeplitz");
        m2.setElement(0, 2, 4); m2.setElement(2, 0, 8);
        cout << "the original Matrix:" << endl << m2 << endl;
        m2.rowShift(2);
        cout << "supposed not change:" << endl << m2 << endl;

        cout << "check matrix 'Arrowhead': " << endl;
        SMatrix m3(3, 3, "Arrowhead");
        m3.setElement(0, 0, 4); m3.setElement(0, 2, 5);
        m3.setElement(1, 0, 6);	m3.setElement(1, 1, 2);
        m3.setElement(2, 0, 5); m3.setElement(2, 2, 9);
        cout << "the original Matrix:" << endl << m3 << endl;
        m3.rowShift(-2);
        cout << "supposed not change:" << endl << m3 << endl;
    }

// colShift
    void checkColShift() {
        cout << endl << " ===== shift col =======" << endl;
        cout << "check matrix 'any': " << endl;
        SMatrix m1(5, 4, "any");
        m1.setElement(0, 0, 3); m1.setElement(0, 1, 4); m1.setElement(0, 2, 6);
        m1.setElement(1, 0, 3); m1.setElement(1, 1, 4); m1.setElement(1, 2, 6);
        m1.setElement(2, 0, 3); m1.setElement(3, 1, 4); m1.setElement(2, 2, 6);
        m1.setElement(3, 0, 3); m1.setElement(4, 1, 4); m1.setElement(4, 2, 6);
        cout << "the original Matrix:" << endl << m1 << endl;

        cout << endl << "after 3 shift col Matrix (right):" << endl;
        m1.colShift(3);
        cout << m1;

        cout << endl << "after more 6 shift col Matrix (right):" << endl;
        m1.colShift(6);
        cout << m1;

        cout << endl << "after more 2 shift col Matrix (left):" << endl;
        m1.colShift(-2);
        cout << m1 << endl;

        cout << "check matrix 'Toeplitz': " << endl;
        SMatrix m2(3, 3, "Toeplitz");
        m2.setElement(0, 2, 4); m2.setElement(2, 0, 8);
        cout << "the original Matrix:" << endl << m2 << endl;
        m2.colShift(2);
        cout << "supposed not change:" << endl << m2 << endl;

        cout << "check matrix 'Arrowhead': " << endl;
        SMatrix m3(3, 3, "Arrowhead");
        m3.setElement(0, 0, 4); m3.setElement(0, 2, 5);
        m3.setElement(1, 0, 6);	m3.setElement(1, 1, 2);
        m3.setElement(2, 0, 5); m3.setElement(2, 2, 9);
        cout << "the original Matrix:" << endl << m3 << endl;
        m3.colShift(-2);
        cout << "supposed not change:" << endl << m3 << endl;
    }

// isA matType
    void checkIsA() {
        cout << endl << " ===== is A =======" << endl;
        SMatrix m1(3, 3, "any");
        m1.setElement(0, 0, 4); m1.setElement(0, 1, 8); m1.setElement(0, 2, 5);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2); m1.setElement(1, 2, 0);
        m1.setElement(2, 0, 5); m1.setElement(2, 1, 0); m1.setElement(2, 2, 9);
        cout << m1 << endl;

        cout << "Arrowhead Matrix ? (supposed to be true): " << m1.isA("Arrowhead") << endl;
        cout << "'wukz' Matrix ? (supposed to be false): " << m1.isA("wukz") << endl;

        m1.setElement(0, 0, 9); m1.setElement(0, 1, 8); m1.setElement(0, 2, 0);
        m1.setElement(1, 0, 0);	m1.setElement(1, 1, 9); m1.setElement(1, 2, 8);
        m1.setElement(2, 0, 5); m1.setElement(2, 1, 0); m1.setElement(2, 2, 9);
        cout << endl << m1 << endl;
        cout << "Toeplitz Matrix ? (supposed to be true): " << m1.isA("Toeplitz") << endl;
        cout << "Arrowhead Matrix ? (supposed to be false): " << m1.isA("Arrowhead") << endl;
        cout << "any Matrix ? (supposed to be true): " << m1.isA("any") << endl;
    }

//print the size of the matrix
    void checkSizeInBytes() {
        cout << endl << " ====== size in bytes =======" << endl;
        SMatrix m1(2, 2, "any");
        m1.setElement(0, 0, 4); m1.setElement(0, 1, 8);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2);

        cout << "supposed to print 160: " << endl;
        m1.sizeInBytes();

        SMatrix m2(3, 3, "Toeplitz");
        m2.setElement(0, 2, 4); m2.setElement(2, 0, 8);
        cout << endl << "supposed to print 120: " << endl;
        m2.sizeInBytes();

        SMatrix m3(3, 3, "Arrowhead");
        m3.setElement(0, 0, 4); m3.setElement(0, 2, 5);
        m3.setElement(1, 0, 6);	m3.setElement(1, 1, 2);
        m3.setElement(2, 0, 5); m3.setElement(2, 2, 9);
        cout << endl << "supposed to print 216: " << endl;
        m3.sizeInBytes();

        SMatrix m4(5, 5, "any");
        cout << endl << "supposed to print 88: " << endl;
        m4.sizeInBytes();
    }

//print all matrix columns
    void checkPrintColumnsIndexes() {
        cout << endl << " ====== print columns indexes =======" << endl;
        SMatrix m1(5, 4, "any");
        m1.setElement(0, 0, 4); m1.setElement(4, 1, 8); m1.setElement(2, 2, 1);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2); m1.setElement(4, 2, 2);
        m1.setElement(2, 0, 5); m1.setElement(2, 1, 7); m1.setElement(2, 3, 9);
        cout << "the original Matrix:" << endl << m1 << endl;
        cout << "supposed to print  {0:(0,4)->(1,6)->(2,5)->}, {1:(1,2)->(2,7)->(4,8)->},{2:(2,1)->(4,2)->}, {3:(2,9)->}" << endl;
        m1.printColumnsIndexes();

        SMatrix m2(3, 3, "Toeplitz");
        m2.setElement(0, 2, 4); m2.setElement(2, 0, 8);
        cout << endl << "the original Matrix:" << endl << m2 << endl;
        cout << "supposed to print  {0:(2,8)->}, {1:},{2:(0,4)}" << endl;
        m2.printColumnsIndexes();

        SMatrix m3(4, 4, "Arrowhead");
        cout << endl << "the original Matrix:" << endl << m3 << endl;
        cout << "supposed to print {0:}, {1:},{2:}, {3:}" << endl;
        m3.printColumnsIndexes();
    }

//print all matrix rows
    void checkPrintRowsIndexes() {
        cout << endl << " ====== print rows indexes =======" << endl;
        SMatrix m1(5, 4, "any");
        m1.setElement(0, 0, 4); m1.setElement(4, 1, 8); m1.setElement(2, 2, 1);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2); m1.setElement(4, 2, 2);
        m1.setElement(2, 0, 5); m1.setElement(2, 1, 7); m1.setElement(2, 3, 9);
        cout << "the original Matrix:" << endl << m1 << endl;
        cout << "supposed to print  {0:(0,4)->}, {1:(0,6)->(1,2)->},{2:(0,5)->(1,7)->(2,1)->(3,9)->}, {3:}, {4:(1,8)->(2,2)->}" << endl;
        m1.printRowsIndexes();

        SMatrix m2(3, 3, "Toeplitz");
        m2.setElement(0, 2, 4); m2.setElement(2, 0, 8);
        cout << endl << "the original Matrix:" << endl << m2 << endl;
        cout << "supposed to print  {0:(2,4)->}, {1:},{2:(0,8)}" << endl;
        m2.printRowsIndexes();

        SMatrix m3(4, 4, "Arrowhead");
        cout << endl << "the original Matrix:" << endl << m3 << endl;
        cout << "supposed to print {0:}, {1:},{2:}, {3:}" << endl;
        m3.printRowsIndexes();
    }

//operator = for SMatrix
    void checkOperatorPlacement () {
        cout << endl << " ===== operator =  =======" << endl;
        SMatrix m1(5, 4, "any");
        m1.setElement(0, 0, 4); m1.setElement(4, 1, 8); m1.setElement(2, 2, 1);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2); m1.setElement(4, 2, 2);
        m1.setElement(2, 0, 5); m1.setElement(2, 1, 7); m1.setElement(2, 3, 9);
        cout << "m1:" << endl << m1 << endl;

        SMatrix m2(3, 3, "Toeplitz");
        m2.setElement(0, 2, 4); m2.setElement(2, 0, 8);
        cout << "m2:" << endl << m2 << endl;

        SMatrix m3(4, 4, "any");
        m3.setElement(0, 0, 4); m3.setElement(3, 1, 8); m3.setElement(2, 2, 1);
        m3.setElement(1, 0, 6);	m3.setElement(1, 1, 2);
        m3.setElement(2, 0, 5); m3.setElement(2, 1, 7); m3.setElement(2, 3, 9);
        cout << "m3:" << endl << m3 << endl;

        SMatrix m4(5, 5, "Arrowhead");

        m1 = m2;
        cout << "should be the same as the m2 matrix:" << endl << m1 << endl;

        m4 = m3 = m1;
        cout << "should be the same as the m2 matrix:" << endl << m4 << endl;
    }

// operator + for SMatrix
    void checkOperatorPlus () {
        cout << endl << " ===== operator + =======" << endl;
        SMatrix m1(3, 3, "any");
        m1.setElement(0, 0, 4); m1.setElement(2, 2, 1);
        m1.setElement(1, 0, 6);	m1.setElement(1, 1, 2);
        m1.setElement(2, 0, 5); m1.setElement(2, 1, 7);
        cout << m1;
        cout << "  +" << endl;
        SMatrix m2(3, 3, "any");
        m2.setElement(0, 1, 4); m2.setElement(2, 2, 3);
        m2.setElement(1, 0, 2);	m2.setElement(1, 1, 4);
        m2.setElement(2, 0, 0); m2.setElement(2, 1, 8);
        cout << m2;
        SMatrix m3(3, 3, "any");
        m3 = m2 + m1;
        cout << "  =" << endl << m3 << endl;

        cout << "supposed to print 240: " << endl;
        m3.sizeInBytes();

        SMatrix m5(3, 3, "Toeplitz");
        m5.setElement(0, 2, 4); m5.setElement(2, 0, 8);
        cout << endl << endl << m5;
        cout << "  +" << endl;
        SMatrix m6(3, 3, "Toeplitz");
        m6.setElement(0, 2, 12);
        cout << m6;
        SMatrix m7(3, 3, "Toeplitz");
        m7 = m6 + m5;
        cout << "  =" << endl << m7 << endl;

        cout << "supposed to print 120: " << endl;
        m7.sizeInBytes();

        SMatrix m4(3, 3, "Arrowhead");
        cout << "supposed to print 'NA' and to exit: " << endl;
        m3 = m4 + m1;


}