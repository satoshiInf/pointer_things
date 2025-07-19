//
//  main.cpp
//  pointer_p62
//
//  Created by Satoshi on 7/19/25.
//

#include <iostream>
#include <iostream>

int main()
{
    int x =1;
    int y =2;
    
    std::cout<< "(" << x <<"," << y <<")" << std::endl;
    
    std::cout<< "(" << &x <<"," << &y <<")" << std::endl;
    
    int* ptrX = &x;
    int* ptrY = &y;
    
    
    
    // 定義後は　ptrX は指した先のxのアドレスを指す。
    std::cout<< "(" << ptrX  <<"," << ptrY  <<")" << std::endl;
    // 定義後は　*ptrX はptrX は指した先の値を示す。
    std::cout<< "(" << *ptrX  <<"," << *ptrY  <<")" << std::endl;
    
    
    // 定義後は　＆ptrX はptrX自身のアドレスを表す
    std::cout<< "(" << &ptrX  <<"," << &ptrY  <<")" << std::endl;
  
    
    return 0;
}
