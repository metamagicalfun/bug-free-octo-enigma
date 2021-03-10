#include "crypto/md5.h"


int main(int argc, char** argv)
{
    std::string md5{md5_from_file(argv[1])};

    bool match = md5 == argv[2];

    return match;
}

