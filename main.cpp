#include <iostream>
#include <string>

#include "crypto/md5.h"


class PacketHeader
{
  public:
    PacketHeader(int seq, int ack, int syn) :
        seq_(seq)
       ,syn_(ack)
       ,ack_(syn)
    {
    }	


 private:
    int seq_;
    int syn_;
    int ack_;
};


class Packet
{
  public:
    Packet(PacketHeader packetHeader, std::string filename)
		: packetHeader_(packetHeader)
		, filename_(filename)
	{		        
    	data_ = {md5_from_file(filename_)};
	}
	
	bool is_valid(std::string& hash) {
		return hash == data_;
	}


  private:
	PacketHeader packetHeader_;
	std::string filename_;
	std::string data_;
};



int main(void)
{
    PacketHeader header{1,2,3};
    Packet packet{header, "test_file.txt"};
	
	std::string md5 = "100e0ac23e8e798f1ac649a2303f1076";

	bool result = packet.is_valid(md5);

    std::cout << result << std::endl;
	if (result) {
		std::cout << "Yay!" << std::endl;
	}

    return 0;
}

