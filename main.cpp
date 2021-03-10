#include "crypto/md5.h"


int main(void)
{
    std::string md5{md5_from_file("test_file.txt")};

    bool match = md5 == "100e0ac23e8e798f1ac649a2303f1076" ;

    return match;
}

