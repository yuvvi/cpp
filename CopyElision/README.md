# COPY ELISION
### Mandatory elision of copy/move operations
#### the compilers are required to omit the copy and move construction of class objects, even if the copy/move constructor and the destructor have observable side-effects. The objects are constructed directly into the storage where they would otherwise be copied/moved to. 
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
int main()
{
    MyClass ob = "copy class object";
    return 0;
}
```
## 1. Without Copy Elision


## 2. With Copy Elision

