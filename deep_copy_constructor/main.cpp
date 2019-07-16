#include <QCoreApplication>
#include <QDebug>

class Data{
private:
    int *a, *b;
public:
    Data(int x,int y){
        qDebug()<<"Data #x: "<<x<<" y: "<<y<<endl;
        a = new int;
        b = new int;
        *a = x;
        *b = y;
    }
    void display(){
        qDebug()<<"display #a: "<<*a<<" b: "<<*b<<endl;
    }
    Data(Data &copyObj){
        qDebug()<<"Copy constructor"<<endl;
        a = new int;
        b = new int;
        *a = *(copyObj.a);
        *b = *(copyObj.b);
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Data obj(1,2);
    obj.display();
    Data obj2 = obj;
    obj2.display();


    return a.exec();
}
