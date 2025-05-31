
#include <iostream>
#include <vector>
using namespace std;

class Buffer {
    int *data;
    size_t size;
    public:
    //Constructor
    Buffer(size_t sz):data(new int[sz]), size(sz) {
        cout<<"Buffer constructor"<<endl;
    }
    //Move constructor
    Buffer(Buffer&& other) noexcept: data(other.data), size(other.size){
        cout<<"Buffer move constructor"<<endl;
        other.data = nullptr;
        other.size=0;
    }
    //Copy constructor
    Buffer(const Buffer& other): data(new int[other.size]), size(other.size){
        cout<<"Buffer copy constructor"<<endl;
        data = other.data;
    }
    //Destructor
    ~Buffer() {
        cout<<"Buffer destructor"<<endl;
        delete[] data;}
};


class Person {
    string* name;
    public:
    //constructor
    Person(const string& n):name(new string(n)) {
        cout<<"Person Constructor"<<endl;
        cout<<"*name: "<<*name<<endl;
        cout<<"--------------"<<endl;
    }
    //Copy constructor
    Person(const Person& other): name(new string(*other.name)) {
        cout<<"Person Copy const :"<<*name<<endl;
        cout<<"*name: "<<*name<<endl;
        cout<<"*other.name: "<<*other.name<<endl;
        cout<<"--------------"<<endl;
    }
    //copy assignment
    Person& operator=(const Person& other){
        if (this != &other) {
            delete name;
            name = new string(*other.name);
            cout<<" Copy assignment"<<endl;
        }
        return *this;
    }
    //Move assignment
    Person& operator=(const Person&& other){
        if (this != &other) {
            delete name;
            name = other.name;
            *other.name = nullptr;
            cout<< "Move assignment"<<endl;
        }
        return *this;
    }
    //Move constructor
    Person(Person&& other) noexcept: name(other.name) {
        other.name = nullptr;
        cout<<"Person move const"<<endl;
        cout<<"*name: "<<*name<<endl;
        cout<<"*other.name: "<<*other.name<<endl;
        cout<<"--------------"<<endl;
    }
    //Destructor
    ~Person() {
        cout<<"destructor"<<endl;
        delete name;}
    void print() const {
        if (name)
            cout<<" Name: "<<*name<<endl;
        else
            cout<<" Name: [move-from]"<<endl;            
        cout<<"--------------"<<endl;
    }
    
    
};

int main() {
    // Buffer a(100);
    // cout<<"------1"<<endl;
    // Buffer b = move(a);
    // cout<<"------2"<<endl;
    
    // vector<Buffer> v;
    // cout<<"------1"<<endl;
    // // v.reserve(5);
    // cout<<"------2"<<endl;
    // v.push_back((Buffer(100)));
    
    // Person p("ABC");
    // Person p1 = p;
    
    // p.print();
    // p1.print();
    // {
    // Person p2 = move(p);
    // cout<<"------"<<endl;
    // }
    // p.print();
    // p2.print();
    
    vector<Person> v;
    v.push_back(Person("xyz"));
    // v[0].print();
    return 0;
}
