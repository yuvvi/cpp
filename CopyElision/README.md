# COPY ELISION
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

