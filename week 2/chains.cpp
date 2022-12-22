#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
vector<int> path;

typedef struct list {
    int data;
    struct list *next;
    struct list *prev;
} list_t;

list_t * append(list_t* list, int code) {
    list_t* line = (list_t*)malloc(sizeof(line));
    line->data = code;
    line->next = NULL;
    line->prev = NULL;
    if (list == NULL) {
        return line;
    } else {
        list_t* temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = line;
        line->prev = temp;
        return list;
    }
}

list_t * reverse_list(list_t* list) {
    list_t *reversed = NULL;
    while (list->next != NULL) {
        list = list->next;
    }
    while (list != NULL) {
        reversed = append(reversed, list->data);
        list = list->prev;
    }

    return reversed;
}

list_t * swap(list_t* a, list_t* b, int robot, int reverse) {
    for (int i=0; i<robot; i++) {
        a = a->next;
    }

    if (reverse == 1) {
        b = reverse_list(b);
    }
    list_t *temp = a->next;
    if (temp != NULL) {
        temp->prev = NULL;
    }
    b->prev = a;
    a->next = b;
    return temp;
}

int size(list_t* line) {
    int count = 0;
    while (line != NULL) {
        count++;
        line = line->next;
    }
    return count;
}

int front_list(list_t* line) {
    return line->data;
}

int back_list(list_t* line) {
    while (line->next != NULL) {
        line = line->next;
    }
    return line->data;
}

int print_list(list_t* list) {
    while (list != NULL) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << "\n";
    return 1;
}

int register_path(list_t* line, int robot) {
    for (int i=0; i<robot; i++) {
        line = line->next;
    }
    path.push_back(line->data);
    return 1;
}

int main(void) {
    int l, n;
    cin >> l >> n;
    list_t** storage = (list_t**)malloc(sizeof(storage) * l);
    int current = 1;
    for (int i=0; i<l; i++) {
        int length;
        cin >> length;
        list_t* line = NULL;
        for (int k=0; k<length; k++) {
            line = append(line, current);
            current++;
        }
        storage[i] = line;
    }

    int robot = 0;
    for (int i=0; i<n; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'F') {
            if (size(storage[0])-1 > robot) {
                robot++;
            }
        } else if (cmd == 'B') {
            if (robot != 0) {
                robot--;
            }
        } else if (cmd == 'C') {
            int x;
            cin >> x;
            int target = 0;
            int reverse = 0;
            for (int i=1; i<l; i++) {
                if (back_list(storage[i]) == x) {
                    reverse = 1;
                    target = i;
                    break;
                }
                if (front_list(storage[i]) == x) {
                    target = i;
                    break;
                }
            }
            storage[target] = swap(storage[0], storage[target], robot, reverse);
            if (size(storage[0])-1 > robot) {
                robot++;
            }
        }
        
        register_path(storage[0], robot);
    }
    for (auto ptr : path) {
        cout << ptr << "\n";
    }


}