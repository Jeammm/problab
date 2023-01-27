#include <iostream>

using namespace std;
int N = 0;
int E = 0;
int S = 0;
int W = 0;
int moves = 0;
int back = 0;
int loss;
string program;

int get_fuel() {
    
}

int main(void) {
    
    cin >> program >> loss;
    for (int i=0; i<program.size(); i++) {
        switch (program[i]) {
            case 'N': N++; break;
            case 'E': E++; break;
            case 'S': S++; break;
            case 'W': W++; break;
        }
    }

    if (N > S)
    {
        moves += N;
        back += S;
    }
    else 
    {
        moves += S;
        back += N;
    }

    if (E > W)
    {
        moves += E;
        back += W;
    }
    else
    {
        moves += W;
        back += E;
    }

    if (back > loss)
    {
        back -= loss;
    }
    else 
    {
        back = loss-back;
    }

    cout << (moves-back)*2 << "\n";
}