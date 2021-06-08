#ifndef TESTCOPY_H
#define TESTCOPY_H

#include <iostream>
#include <QDebug>
using namespace std;

class TestCopy
{
public:
    int *abc;
    TestCopy();
    ~TestCopy();
    TestCopy(const TestCopy &copy);
    TestCopy(const TestCopy *copy);

    TestCopy(const TestCopy &&copy);

    TestCopy& operator=(TestCopy &copy);
    TestCopy& operator=(TestCopy &&copy);

    void setVal(int val);
};

#endif // TESTCOPY_H
