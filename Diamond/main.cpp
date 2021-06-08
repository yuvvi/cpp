#include <iostream>

using namespace std;

class A{
public:
    A(){cout<<"A constructor"<<endl;}
    void function(){cout<<"Function A"<<endl;}
};

class B:virtual public A{
public:
    B(){cout<<"B constructor"<<endl;}
};

class C:virtual public A{
public:
    C(){cout<<"C constructor"<<endl;}
};

class D:public B,public C{
public:
    D(){cout<<"D constructor"<<endl;}
};


int main()
{
    cout << "Diamond" << endl;

    D obj;
    obj.function();
    return 0;
}
