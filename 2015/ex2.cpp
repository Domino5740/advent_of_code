#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
    fstream input("input_2.txt", ios::in);

    int square_feet;
    string present;
    int x1pos;
    int x2pos;
    string dimension;
    int length;
    int width;
    int height;
    int base;
    int wall1;
    int wall2;
    int smallest_side;
    int smallest_dim;
    int small_dim;
    int ribbon_feet;
    int bow;

    if(input.good() == false) {
        cout << "file doesn't exist";
        exit(0);
    }
    else {
        while(getline(input, present)) {
            x1pos = present.find('x');
            if(x1pos != string::npos) {
                x2pos = present.find('x', x1pos + 1);
                if(x2pos == string::npos) exit(0);
            }
            else exit(0);

            dimension = present.substr(0, x1pos);
            length = stoi(dimension);

            dimension = present.substr(x1pos + 1, x2pos);
            width = stoi(dimension);

            dimension = present.substr(x2pos + 1);
            height = stoi(dimension);
            
            base = length * width;
            wall1 = width * height;
            wall2 = length * height;
            
            if(base <= wall1) smallest_side = base;
            else smallest_side = wall1;
            if(wall2 <= smallest_side) smallest_side = wall2;
        
            square_feet += (2 * base) + (2 * wall1) + (2 * wall2) + smallest_side;

            if(length <= width) {
                smallest_dim = length;
                small_dim = width;
            }
            else {
                smallest_dim = width;
                small_dim = length;
            }
            if(height <= smallest_dim) {
                small_dim = smallest_dim;
                smallest_dim = height;
            }
            else if(height <= small_dim) small_dim = height;

            bow = length * width * height;
            ribbon_feet += (2 * small_dim) + (2 * smallest_dim) + bow;
            cout << smallest_dim << " x " << small_dim << endl;
        }
        cout << "part one: " << square_feet << endl;
        cout << "part two: " << ribbon_feet << endl;
    }
    input.close();
}