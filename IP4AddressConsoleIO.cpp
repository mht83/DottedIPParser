//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include "IP4AddressConsoleIO.h"
#include <iostream>
#include <string>
#include <vector>

class IPv4 {
private:
    std::string dottedIp;
    int addressOctets[4] = { 0, 0, 0, 0 };

public:

    void splitDottedIp(const std::string& ip) {
        std::string octet = "";
        int index = 0;
        for (char ch : ip) {
            if (ch != '.') {
                octet += ch;
            }
            else {
                addressOctets[index] = std::stoi(octet);
                index++;
                octet = "";
            }
        }
        addressOctets[3] = std::stoi(octet); 
    }

    void readDottedIp() {
        std::string inputIp;
        std::cin >> inputIp;
        dottedIp = inputIp;

        splitDottedIp(dottedIp);
    }


    void displayAddress() {
        std::cout << "( ";
        for (int i = 0; i < 4; ++i) {
            std::cout << addressOctets[i];
            if (i < 3) std::cout << " , ";
        }
        std::cout << " )"<<std::endl;
    }
};

int main() {
    IPv4 ip;
    std::cout << "Please enter an IP address in dotted format: ";
    ip.readDottedIp();
    std::cout << "The IP address you entered is: ";
    ip.displayAddress();
    return 0;
}
