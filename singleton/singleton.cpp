#include "singleton.h"
Singleton *Singleton::stobj = nullptr;

Singleton::Singleton()
{
    qDebug()<<Q_FUNC_INFO;
}
Singleton *Singleton::getInstance(){
    qDebug()<<Q_FUNC_INFO;
    if(stobj == nullptr){
        qDebug()<<Q_FUNC_INFO<<" Obj created";
        stobj = new Singleton;
    }
    return stobj;
}
