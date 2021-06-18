#ifndef SINGLETON_H
#define SINGLETON_H
#include <QDebug>

class Singleton
{
public:
    static Singleton *getInstance();
private:
    static Singleton *stobj;
    Singleton();
    ~Singleton(){}
    Singleton(const Singleton *){}
    Singleton(const Singleton &){}
    Singleton *operator==(const Singleton*){}
    Singleton &operator==(const Singleton&){}
};

#endif // SINGLETON_H
