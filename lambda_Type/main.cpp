#include <iostream>

using namespace std;

/*
 * Call by value using capture list (All Function scope variables)
 * Accessing all the variables of function scope using capture list [=]
 * Default all the variable are const & can be modified using "mutable"
 * Syntax : [=]()mutable{}
 */
void lambda_callByVal_captureList_1()//[=]()mutable{}
{
    cout<<"-----------------[=]()mutable{}-----------------"<<endl;
    int a=0,b=0,c=0,d=0,e=0;
    cout<<"Before lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    auto l3 = [=]()mutable{
        ++a;++b;++c,++d,++e;
        cout<<"In lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    };
    l3();
    cout<<"After lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

/*
 * Call by value using capture list  (Specific variable)
 * Specific variables passed into lambda.
 * syntax : [a,b,c]()mutable{}
 */
//std::function<void()>
void lambda_callByVal_cpatureList_2()//[a,b,c]()mutable{}
{
    cout<<"-----------------[a,b,c]()mutable{}-----------------"<<endl;
    int a=0,b=0,c=0,d=0,e=0;
    cout<<"Before lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    auto l3 = [a,b,c]()mutable{
        ++a;++b;++c;
        cout<<"In lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<endl;
    };
    l3();
    cout<<"After lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

/*
 * Call by value using parameter list  (Specific variable)
 * Specific variables passed into lambda.
 * syntax : [](int x,int y,int z)mutable{}
 */
//std::function<void()>
void lambda_callByVal_parameterList()//[](int x,int y,int z){}
{
    cout<<"-----------------[](int x,int y,int z){}-----------------"<<endl;
    int a=0,b=0,c=0,d=0,e=0;
    cout<<"Before lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    auto l3 = [](int x,int y,int z){
        ++x;++y;++z;
        cout<<"In lambda# a:"<<x<<" #b :"<<y<<" #c :"<<z<<endl;
    };
    l3(a,b,c);
    cout<<"After lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

/*
 * Call by reference using capture list. (All variables)
 * All the variables within function scope can be accessed.
 * syntax : [&](){}
*/
void lambda_callByRef_captureList_1(){//[&]()mutable{}
    cout<<"-----------------[&]()mutable{}------------------"<<endl;
    int a=0,b=0,c=0,d=0,e=0;
    cout<<"Before lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    auto l3 = [&]()mutable{
        ++a;++b;++c,++d,++e;
        cout<<"In lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    };
    l3();
    cout<<"After lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    cout<<"-------------------------------------------------"<<endl;
}

/*
 * Call by reference using capture list. (Specific variables)
 * All the variables within function scope can be accessed.
 * syntax : [&a,&b,&c]()mutable{}
*/
void lambda_callByRef_captureList_2(){//[&a,&b,&c]()mutable{}
    cout<<"-----------------[&a,&b,&c]()mutable{}------------------"<<endl;
    int a=0,b=0,c=0,d=0,e=0;
    cout<<"Before lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    auto l3 = [&a,&b,&c]()mutable{
        ++a;++b;++c;
        cout<<"In lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<endl;
    };
    l3();
    cout<<"After lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    cout<<"------------------------------------------------------"<<endl;
}

/*
 * Call by reference using parameter list.
 * Specific variables can be sent by reference using parameter list.
 * syntax : [](){}
*/
void lambda_callByRef_parameterList(){//[](int *x,int *y,int *z){}
    cout<<"------------[](int *x,int *y,int *z){}--------------"<<endl;
    int a=0,b=0,c=0,d=0,e=0;
    cout<<"Before lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    auto foo= [](int *x,int *y,int *z){
        ++(*x);++(*y),++(*z);
        cout<<"In lambda# a:"<<*x<<" #b :"<<*y<<" #c :"<<*z<<endl;
    };
    foo(&a,&b,&c);
    cout<<"After lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    cout<<"------------------------------------------------------"<<endl;
}

/* Combination of call by reference and call by value using capture list
 * All the variables within function scope can be accessed,
 * But variable 'a' is pass by value.
 * syntax : [&,a]()mutable{}
*/

void lambda_call_ref_val(){
    cout<<"------------[&,a]()mutable{}--------------"<<endl;
    int a=0,b=0,c=0,d=0,e=0;
    cout<<"Before lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    auto foo = [&,a]()mutable{
        ++a;++b;++c,++d,++e;
        cout<<"In lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    };
    foo();
    cout<<"After lambda# a:"<<a<<" #b :"<<b<<" #c :"<<c<<"#d :"<<d<<" #e:"<<e<<endl;
    cout<<"------------------------------------------------------"<<endl;
}

int main(int argc, char *argv[])
{
    lambda_callByVal_captureList_1();
    lambda_callByVal_cpatureList_2();
    lambda_callByVal_parameterList();
    lambda_callByRef_captureList_1();
    lambda_callByRef_captureList_2();
    lambda_callByRef_parameterList();
    lambda_call_ref_val();
    return 0;

}
