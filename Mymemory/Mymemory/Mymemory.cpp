// Mymemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
int main()
{
    void* ptr;
   
    int myvar =20;
    
    ptr = &myvar;
    
    int* intptr = (int*)ptr;
    
    std::string myString = std::to_string(*intptr);

    std::cout << myString;
    
        
  





   

    
    
    


    

    


    


}
