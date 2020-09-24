#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    fstream input("input_1.txt", ios::in);
    fstream output("output_1.txt", ios::out);
    int floor = 0;
    int position = 0;
    int position_basement = 0;
    int basement_counter = 0;
    char data;

    if(input.good() == false) {
        cout << "file doesn't exist";
        exit(0);
    }
    else {
        while(!input.eof()) {
            if(data == '(')  {
                floor += 1;
            }
            else if(data == ')') {
                floor -= 1;
            }
            if(floor == -1 && !basement_counter) {
                position_basement = position;
                basement_counter += 1;
            }
            position += 1;
            input >> data;
            output << data;
        }
        output << endl << "part one: " << floor;
        output << endl << "part two: " << position_basement << endl;
    }
    input.close();
    output.close();
}