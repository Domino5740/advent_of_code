#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

int main(void) {

    std::fstream input("input_6.txt", std::ios::in);
    string instruction = "toggle 0,0 through 999,999";
    std::regex instructions_regex {"(turn on|turn off|toggle)\\s(\\d*),(\\d*)\\sthrough\\s(\\d*),(\\d*)"};
    string command;
    int x_start_cord, y_start_cord;
    int x_end_cord, y_end_cord;
    int total_brightness = 0;

    vector<vector<int>> lights_grid(1000, vector<int> (1000, 0));

    if(!input.good()) {
        cout << "error" << endl;
    }
    else {
        while(getline(input, instruction)) {
            std::smatch instructions;
            if(std::regex_search(instruction, instructions, instructions_regex)) {
                command = instructions.str(1);
                x_start_cord = stoi(instructions.str(2));
                y_start_cord = stoi(instructions.str(3));
                x_end_cord   = stoi(instructions.str(4));
                y_end_cord   = stoi(instructions.str(5));

                for (int i = x_start_cord; i <= x_end_cord; i++) {
                    for(int j = y_start_cord; j <= y_end_cord; j++) {
                        if(command == "turn on")        lights_grid[i][j] += 1;
                        else if(command == "turn off")  lights_grid[i][j] = (!lights_grid[i][j]) ? 0 : lights_grid[i][j] - 1;
                        else if(command == "toggle")    lights_grid[i][j] += 2;
                    }
                }
            }
        }
        
        for (int i = 0; i < lights_grid.size(); i++) {
            for(int j = 0; j < lights_grid[i].size(); j++) {
                total_brightness += lights_grid[i][j];
            }
        }

        cout << "part two: " << total_brightness << endl;
    }
    input.close();
}