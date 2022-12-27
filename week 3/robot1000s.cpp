#include <iostream>
#include <array>

using namespace std;
array<int, 4> moves;

int main(void) {
    string program, loss;
    cin >> program >> loss;
    for (int i=0; i<program.size(); i++) {
        switch (program[i]) {
            case 'N': moves[0]++; break;
            case 'E': moves[1]++; break;
            case 'S': moves[0]--; break;
            case 'W': moves[1]--; break;
        }
    }

    int max=0;
}