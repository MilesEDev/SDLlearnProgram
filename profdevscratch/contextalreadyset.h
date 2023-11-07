#pragma once
#include <iostream>
#include <exception>
#include <string>       
class contextalreadyset:public std::exception 
{
public:
    std::string error();
  


};

