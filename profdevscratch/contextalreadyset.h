#pragma once
#include <iostream>
#include <exception>
#include <string>       
/**
 * .class no longer used may be used in future 
 */
class contextalreadyset:public std::exception 
{
public:
    std::string error();
};

