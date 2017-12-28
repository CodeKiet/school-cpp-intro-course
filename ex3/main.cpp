#include <iostream>
#include "matrix.h"

int main() {
    Matrix m1(3, 3, "any");
    m1.setElement(2, 2, 1);
    m1.setElement(0, 2, 1);
    m1.setElement(2, 0, 1);
    m1.print();

    Matrix m2(3, 3, "Arrowhead");

    m1.add(m1, m2);

    m2.print();

    m2.setElement(4, 5, 7);


    return 0;
}