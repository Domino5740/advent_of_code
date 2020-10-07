#include <iostream>
#include "md5.h"
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

string secret_code = "ckczppom";
string md5_input;
int counter = 0;
string counter_string;
string md5_hash;

int main(void) {
    md5_hash = md5(secret_code);
    while(!((md5_hash[0] == '0') & (md5_hash[1] == '0') & (md5_hash[2] == '0') & (md5_hash[3] == '0') & (md5_hash[4] == '0') & (md5_hash[5] == '0'))) {
        counter_string = std::to_string(counter);
        md5_input = secret_code + counter_string;
        counter++;
        md5_hash = md5(md5_input);
        //cout << md5_input << "  " << md5_hash << endl;
    }
    cout << "the answer is: " << md5_input << "   " << md5_hash << endl;
}