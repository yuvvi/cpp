#include <QCoreApplication>
#include "linkedlist.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Linkedlist obj;
//    obj.addFirst(12);
//    obj.addFirst(16);
//    obj.addFirst(6);
//    obj.addFirst(3);
//    obj.addFirst(19);
//    obj.addFirst(21);

    obj.addLast(1);
    obj.addLast(2);
    obj.addLast(3);
    obj.addLast(4);
    obj.addLast(5);
    obj.addLast(6);
    obj.addLast(7);
    obj.addLast(8);
    obj.addLast(9);
    obj.addLast(10);
//    obj.addLast(11);

    obj.display();
//    qDebug()<<"------------------------------------------------";
//    obj.searchElementLL(11);
//    qDebug()<<"------------------------------------------------";
//    obj.searchElementLL(5);
//    qDebug()<<"------------------------------------------------";
//    obj.searchElementLL(1);
//    qDebug()<<"------------------------------------------------";
//    obj.searchElementLL(10);
//    qDebug()<<"------------------------------------------------";
//    obj.deleteMiddleElement();
//    obj.display();
//    obj.deleteLast_fast();


//    obj.reverseList();
    obj.reverseLL();
        obj.display();
    return a.exec();
}
