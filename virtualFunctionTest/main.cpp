#include <iostream>

using namespace std;

class Base{
public:
    virtual void function(int a =10){
        cout<<"Base::function a:"<<a<<endl;
    }
};

class Derived:public Base{
public:
    void function(int a=20){
        cout<<"Derived::function a:"<<a<<endl;
    }
};

int main()
{
    cout << "Virtual Function Test" << endl;
    Base *obj = new Derived;
    obj->function();
    obj->function(30);
    return 0;
}
