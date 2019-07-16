#include <QCoreApplication>
#include <QDebug>

class ABC_1{
public:
    ABC_1(){
        qDebug()<<"constructor ABC"<<endl;
    }
    virtual void print_ABC(){
        qDebug()<<"print ABC"<<endl;
    }
};

class DEF_2:virtual public ABC_1{
public:
    DEF_2(){
        qDebug()<<"constructor DEF"<<endl;
    }
    void print_DEF(){
        qDebug()<<"print DEF"<<endl;
    }
};

class GHI_2:virtual public ABC_1{
public:
    GHI_2(){
        qDebug()<<"constructor GHI"<<endl;
    }
    void print_GHI(){
        qDebug()<<"print GHI"<<endl;
    }
};

class JKL_3: public DEF_2, GHI_2{
public:
    JKL_3(){
        qDebug()<<"constructor JKL_3"<<endl;
    }
    void print_JKL_3(){
        qDebug()<<"print JKL_3"<<endl;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    JKL_3 obj;
    obj.print_ABC();

    return a.exec();
}
