//
//*pointer-> a's value
//pointer -> a's address
//&pointer->pointer's address

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a = 1;
    int b = 2;
    int* b_pointer;
    
    cout<< "a==============" << endl;
    cout<< a << endl;
    
    cout<< &a << endl;
    printf("&a: %p",(void*)&a);
    cout<< endl;
    
    //printf("&b: (void*)&b");
    //printf("&a_pointer: (void*)&a_pointer");
    
    cout<< "b==============" << endl;
    cout<< b << endl;
    cout<< &b << endl;
    cout<< endl;
    
    cout<< "b_pointer==============" << endl;
    
    cout<< b_pointer << endl;
    cout<< &b_pointer << endl;
    
    
    return 0;
}
