#include <QCoreApplication>
#include <memory>
#include "testcopy.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    unique_ptr<TestCopy> t1 = make_unique<TestCopy>();
//    unique_ptr<TestCopy> t2 = make_unique<TestCopy>(move(t1));

//    TestCopy *t1 = new TestCopy;
//    TestCopy *t2 = new TestCopy(t1);

//    TestCopy t3;
//    TestCopy t4 = t3;

//    auto testObj = [](){
//        TestCopy t6;
//        return t6;
//    };

//    TestCopy t5 = testObj();

    TestCopy t7,t8;
    t7.setVal(11);
    qDebug()<<"t7 :"<<*t7.abc;

    t8 = t7;
    qDebug()<<"t8 :"<<*t8.abc;


    return a.exec();
}
