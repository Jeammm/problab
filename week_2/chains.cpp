#include <iostream>
#define MAX_N 100010

using namespace std;

int l, n;
int dna[MAX_N];
int parent[MAX_N];
int child[MAX_N];
int count = 0;
int current = 0;

void cut(int target)
{
    parent[child[current]] = -1;  // cut child

    if (child[target] == -1) // reverse
    {
        child[target] = current;
        
        int it = target;
        while (parent[it] != -1)
        {
            int temp_parent = parent[it];
            parent[it] = child[it];
            child[it] = temp_parent;
            it = child[it];
        }
        int temp_parent = parent[it];
        parent[it] = child[it];
        child[it] = temp_parent;
        it = child[it];
    }
    else // not reverse
    {
        parent[target] = current;
    }
    child[current] = target;
    current = child[current];

}

void get_input()
{
    
    cin >> l >> n;
    for (int i = 0; i < l; i++)
    {
        int line;
        cin >> line;

        for (int j = 0; j < line; j++)
        {   
            dna[count] = count + 1;

            if (line == 1)
            {
                parent[count] = -1;
                child[count] = -1;
            }
            else if (j == 0)
            {
                parent[count] = -1;
                child[count] = count + 1;
            }
            else if (j == line - 1)
            {
                parent[count] = count - 1;
                child[count] = -1;
            }
            else
            {
                parent[count] = count - 1;
                child[count] = count + 1;
            }

            count++;
        }
    }
}

void move()
{
    for (int i = 0; i < n; i++)
    {
        char cmd;
        int target;
        cin >> cmd;
        switch (cmd)
        {
        case 'F':
            if (child[current] != -1)
            {
                current = child[current];
            }
            break;
        case 'B':
            if (parent[current] != -1)
            {
                current = parent[current];
            }
            break;
        case 'C':
            cin >> target; target--;
            cut(target);
            break;
        }
        cout << dna[current] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    get_input();
    move();
}