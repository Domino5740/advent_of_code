#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class house{
    public:
        int x_cord = 0;
        int y_cord = 0;
};

vector<house> houses, robo_houses;

int main(void) {

    fstream input("input_3.txt", ios::in);
    fstream output("output_3.txt", ios::out);
    int house_counter = 1;
    int present_counter = 0;
    int robo_present_counter = 0;
    bool robo_santa_moving = 0;
    char data;
    int house_found = 0;
    house first_house;

    if(input.good() == false) {
        cout << "file doesn't exist";
        exit(0);
    }
    else {
        houses.push_back(first_house);
        robo_houses.push_back(first_house);
        while(!input.eof()) {
            input >> data;
            house_found = 0;
            if(!robo_santa_moving) {
                present_counter++;
                houses.push_back(houses[present_counter - 1]);
                if(data == '>') houses[present_counter].x_cord += 1;
                else if(data == '<') houses[present_counter].x_cord -= 1;
                else if(data == '^') houses[present_counter].y_cord += 1;
                else if(data == 'v') houses[present_counter].y_cord -= 1;

                for(int i = 0; i != (present_counter - 1); i++) {
                    if((houses[i].x_cord == houses[present_counter].x_cord) && (houses[i].y_cord == houses[present_counter].y_cord)) house_found = 1;
                }

                for(int i = 0; i != robo_present_counter; i++) {
                    if((robo_houses[i].x_cord == houses[present_counter].x_cord) && (robo_houses[i].y_cord == houses[present_counter].y_cord)) house_found = 1;
                }
            }
            else if(robo_santa_moving) {
                robo_present_counter++;
                robo_houses.push_back(robo_houses[robo_present_counter - 1]);
                if(data == '>') robo_houses[robo_present_counter].x_cord += 1;
                else if(data == '<') robo_houses[robo_present_counter].x_cord -= 1;
                else if(data == '^') robo_houses[robo_present_counter].y_cord += 1;
                else if(data == 'v') robo_houses[robo_present_counter].y_cord -= 1;

                for(int i = 0; i != (robo_present_counter - 1); i++) {
                    if((robo_houses[i].x_cord == robo_houses[robo_present_counter].x_cord) && (robo_houses[i].y_cord == robo_houses[robo_present_counter].y_cord)) house_found = 1;
                }

                for(int i = 0; i != present_counter; i++) {
                    if((houses[i].x_cord == robo_houses[robo_present_counter].x_cord) && (houses[i].y_cord == robo_houses[robo_present_counter].y_cord)) house_found = 1;
                }
            }

            output << data;
            robo_santa_moving = !robo_santa_moving;
            if(!house_found) house_counter += 1;
        }
        cout << "part two: " << house_counter << endl;
    }
    input.close();
    output.close();
}