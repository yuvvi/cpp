#include <iostream>
#include <memory>

using namespace std;

class XYZ;
class ABC{
std::shared_ptr<XYZ> obj_xyz;
std::weak_ptr<XYZ> obj_w_xyz;
public:
    ABC()    {cout<<"ABC Constructor"<<endl;}
    ~ABC()    {cout<<"~ABC Destructor"<<endl;}
    void setSharedPtr(std::shared_ptr<XYZ> &obj){ obj_xyz = obj;}
    void setWeakPtr(std::shared_ptr<XYZ> &obj){ obj_w_xyz = obj;}

};

class XYZ{
    std::shared_ptr<ABC> obj_abc;
    std::weak_ptr<ABC> obj_w_abc;
public:
    XYZ()    {cout<<"XYZ Constructor"<<endl;}
    ~XYZ()    {cout<<"~XYZ Destructor"<<endl;}
    void setSharedPtr(std::shared_ptr<ABC> &obj){ obj_abc = obj;}
    void setWeakPtr(std::shared_ptr<ABC> &obj){ obj_w_abc = obj;}

};

void function_cyclicDependency(){
    cout<<"--CYCLIC DEPENDENCY--"<<endl;
        std::shared_ptr<ABC> obj1 = std::make_shared<ABC>();
        std::shared_ptr<XYZ> obj2 = std::make_shared<XYZ>();

        obj1->setSharedPtr(obj2);
        obj2->setSharedPtr(obj1);
        /*ABC & XYZ instances are not deleted as there is cyclic dependency*/
}

void function_NO_cyclicDependency(){
    cout<<"--NO CYCLIC DEPENDENCY--"<<endl;
    std::shared_ptr<ABC> obj1 = std::make_shared<ABC>();
    std::shared_ptr<XYZ> obj2 = std::make_shared<XYZ>();

    obj1->setWeakPtr(obj2);
    obj2->setWeakPtr(obj1);
}

int main(int argc, char *argv[])
{

    function_cyclicDependency();
    function_NO_cyclicDependency();

    return 0;
}
