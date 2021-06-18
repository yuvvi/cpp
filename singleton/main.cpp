#include <iostream>
#include "singleton.h"
using namespace std;

int main()
{
    cout << "Singleton" << endl;
    Singleton *obj = Singleton::getInstance();

    return 0;
}
