#include <iostream>
#include <array>
#include <cmath>

using namespace std;
array<int, 4> moves = {0, 0, 0, 0};

int get_fuel(array<int, 4> &program) {
    
}

int main(void) {
    string program, loss;
    cin >> program >> loss;
    for (int i=0; i<program.size(); i++) {
        switch (program[i]) {
            case 'N': moves[0]++; break;
            case 'E': moves[1]++; break;
            case 'S': moves[2]++; break;
            case 'W': moves[3]++; break;
        }
    }

    int max=0;

}