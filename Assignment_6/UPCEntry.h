#ifndef UPC_ENTRY
#define UPC_ENTRY
#include <string>
#include <iostream>
using namespace std;

struct UPCEntry
{
    long long upc = -1;
    string desc = "";
    UPCEntry();
    UPCEntry(string line);

    int hash1(int tableSize)
    {
        return upc % tableSize;
    }

    int hash2(int tableSize)
    {
        return abs(desc[0] + 27 * desc[1] + 729 * desc[2]) % tableSize;
    }

    bool operator==(const UPCEntry other); 

    friend ostream& operator<<(ostream& os, const UPCEntry& item) {
        os << "Description: " << item.desc; 
        return os;
    }
};

/* -----------------DEFAULT CONSTRUCTOR-------------------*/
UPCEntry::UPCEntry(){} 

/* -----------------COPY CONSTRUCTOR-------------------*/
UPCEntry::UPCEntry(string line) {
    int comma = line.find(',');
    string s1 = line.substr(0 , comma); 
    string s2 = line.substr(comma + 1, line.length()-1); 

    if(s2.back() == '\r')
        s2 = s2.substr(0, s2.length()-1);
        //cout << s1 << "," << s2 << endl; 
        upc = stoll(s1, 0); 
        desc = s2; 
}

/*----------------------------------------------ALL OPERATOR IMPLEMENTATIONS--------------------------------------------------- */
bool UPCEntry::operator==(const UPCEntry other) {
    if(desc == other.desc && upc == other.upc) {
            return true; 
    }
    return false;
}

#endif