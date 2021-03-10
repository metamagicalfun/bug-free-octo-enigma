
#include <iostream>
#include "crypto/md5.h"


int main(void) 
{
    std::cout << md5_from_file("main.cpp") << std::endl;
    return 0;
}

