#include <iostream>

using namespace std;

class Base{
public:
    int val =0;
    Base(){        cout<<"Base()"<<endl;    }
    void setVal(int num){val = num;}

    Base& operator+ (const Base &src){
        cout<<"operator+"<<endl;
        cout<<"val: "<<val<<" src.val: "<<src.val<<endl;
        this->val = src.val + this->val;
        return *this;
    }

    /*
      Base operator+ (const Base &src){
        Base res;
        cout<<"operator+"<<endl;
        cout<<"val: "<<val<<" src.val: "<<src.val<<endl;
        res.val = src.val + this->val;
        return res;
    }
    */

/*
    Base(const Base &src){
        cout<<"COPY:  Base(const Base &src)"<<endl;
    }*/
};

int main()
{
    cout << "Operator Overloading" << endl;
    Base obj1;
    obj1.setVal(10);
    Base obj2;
    obj2.setVal(20);

    Base obj3 = obj1 + obj2;
    cout<<"obj3 :"<<obj3.val<<endl;


    Base obj4;
    obj4.setVal(40);

    Base *obj5 = nullptr;

    {
        obj5 = new Base;
        obj5->setVal(50);
    }

    Base obj6 = *obj5 + obj4;
    cout<<"obj6.val :"<<obj6.val<<endl;

    return 0;
}
