#include "testcopy.h"

TestCopy::TestCopy()
{
    qDebug()<<Q_FUNC_INFO;
    cout<<"TestCopy constrcutor";
    abc = new int(10);
}

TestCopy::~TestCopy()
{
    qDebug()<<Q_FUNC_INFO;
    cout<<"TestCopy Destrcutor";
    delete abc;
}

//TestCopy::TestCopy(make_unique<TestCopy> copy){

//}

TestCopy::TestCopy(const TestCopy &copy)
{
    qDebug()<<Q_FUNC_INFO;
    cout<<"TestCopy CopyConstructor";
    abc = new int(*copy.abc);
}

TestCopy::TestCopy(const TestCopy *copy)
{
    qDebug()<<Q_FUNC_INFO;
    cout<<"TestCopy CopyConstructor";
    abc = new int(*copy->abc);

}

TestCopy::TestCopy(const TestCopy &&copy)
{
    qDebug()<<Q_FUNC_INFO;
    abc = new int(*copy.abc);
}

TestCopy& TestCopy:: operator=(TestCopy &&copy){
    qDebug()<<Q_FUNC_INFO;
    *this->abc = *copy.abc;
    return *this;
}

TestCopy&  TestCopy:: operator=(TestCopy &copy){
    qDebug()<<Q_FUNC_INFO;
//    TestCopy c1;
    *this->abc = *copy.abc;
    return *this;
}


void TestCopy::setVal(int val)
{
    qDebug()<<Q_FUNC_INFO;
    *abc = val;
}
