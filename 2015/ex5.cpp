#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

string my_string;
int nice_string_counter = 0;
int vovels_counter = 0;
char letter, previous_letter;
bool forbidden_strings_used;
bool double_letter;

int main(void) {
    std::fstream input("input_5.txt", std::ios::in);

    if(input.good() == false) {
        cout << "file doesn't exist";
        exit(0);
    }
    else {
        while(std::getline(input, my_string)) {
            vovels_counter = 0;
            double_letter = 0;
            forbidden_strings_used = 0;
            //my_string = "ugknbfddgicrmopn";
            cout << my_string << endl;

            for(int i = 0; i < my_string.size(); i++) {
                letter = my_string[i];
                if(i > 0) previous_letter = my_string[i - 1];
                else previous_letter = 0;
                if((letter == 'a') || (letter == 'e') || (letter == 'i') | (letter == 'o') || (letter == 'u')) vovels_counter += 1;
                if(previous_letter == letter) double_letter = 1;
                if((previous_letter == 'a' && letter == 'b') || (previous_letter == 'c' && letter == 'd') || (previous_letter == 'p' && letter == 'q') || (previous_letter == 'x' && letter == 'y')) forbidden_strings_used = 1;
               // cout << "letter: " << letter << "   vovels: " << vovels_counter << "    double: " << double_letter << "    forb: " << forbidden_strings_used << endl;
            }
            if(vovels_counter >= 3 && double_letter && !forbidden_strings_used) nice_string_counter += 1;
        }
        cout << "part one: " << nice_string_counter << endl;
        //cout << "part one: " << nice_string_counter << endl;
        //cout << "part two: " << ribbon_feet << endl;
    }
    input.close();
}