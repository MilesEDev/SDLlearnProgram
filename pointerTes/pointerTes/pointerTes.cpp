// pointerTes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bas.h"
#include "derived.h"

int main()
{
    
    bas* bastest = new bas();
    bastest->paramtest(new derived());
}
