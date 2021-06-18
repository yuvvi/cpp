# COPY ELISION
### Mandatory elision of copy/move operations
#### (C++11) The compilers are required to omit the copy and move construction of class objects, even if the copy/move constructor and the destructor have observable side-effects. The objects are constructed directly into the storage where they would otherwise be copied/moved to. 
```
class MyClass {
   public:
     MyClass(const char* str = "\0") {  //default constructor
         cout << "Constructor called" << endl;
      }
      MyClass(const MyClass &my_cls) { //copy constructor
         cout << "Copy constructor called" << endl;
      }
};

MyClass getInstance(){
   MyClass mobj;
   return mobj;
}

int main()
{
    MyClass obj1 = "copy class object"; // CASE 1
    MyClass obj2 =  getInstance(); //CASE 2
    return 0;
}
```
## 1. Without Copy Elision
_$g++ -fno-elide-constructors main.cpp_
>MyClass obj1 = "copy class object";

## 2. With Copy Elision

