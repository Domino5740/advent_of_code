#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

string my_string;
int nice_string_counter = 0;
char letter, previous_letter, pre_previous_letter;
bool two_letters_cond, one_letter_cond;

int main(void) {
    std::fstream input("input_5.txt", std::ios::in);

    if(input.good() == false) {
        cout << "file doesn't exist";
        exit(0);
    }
    else {
        while(std::getline(input, my_string)) {
            two_letters_cond = 0;
            one_letter_cond = 0;
            //my_string = "qjhvhtzxzqqjkmpb";

            for(int i = 0; i < my_string.size(); i++) {
                letter = my_string[i];
                if(i > 0) {
                    previous_letter = my_string[i - 1];
                    if(!two_letters_cond) {
                        for(int j = i + 1; j < my_string.size() - 1; j++) {
                            if(my_string[j] == previous_letter && my_string[j + 1] == letter) two_letters_cond = 1;
                        }
                    }
                }
                else previous_letter = 0;
                if(i > 1) pre_previous_letter = my_string [i - 2];
                else pre_previous_letter = 128;

                if(pre_previous_letter == letter) one_letter_cond = 1;
               // cout << "letter: " << letter << "   vovels: " << vovels_counter << "    double: " << double_letter << "    forb: " << forbidden_strings_used << endl;
            }
            if(two_letters_cond & one_letter_cond) nice_string_counter += 1;
        }
        cout << "part two: " << nice_string_counter << endl;
    }
    input.close();
}