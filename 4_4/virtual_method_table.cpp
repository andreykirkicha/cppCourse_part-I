#include <iostream>

using namespace std;

class X
{
    public:
        virtual void method() { cout << "value = " << value << endl; }

        int value;
 };
 
 int main()
 {
    //create an object (obj) of class X
    X *obj = new X();
    obj->value = 10;

    //get the virtual table pointer of object obj
    int *vptr =  *(int**)obj;
 
    // we shall call the function 'method()', but first the following assembly code
    // is required to make obj as 'this' pointer as we shall call
    // function 'method()' directly from the virtual table
    __asm
    {
        mov ecx, obj
    }
 
    // function 'method()' is the first entry of the virtual table, so it's vptr[0]
    ((void (*)())vptr[0])();
 
    // the above is the same as the following
    // obj->method();
 
    return 0;
 }