#include <iostream>
// #include <vector>
#include <cstdlib>

using namespace std;
// vector<int> path;
int path[100001];
int path_index = 0;

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

void reverse_list(list_t *&list) {
  list_t *temp = NULL;
  list_t *current = list;

  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if (temp != NULL) {
    list = temp->prev;
  }
}

list_t * swap(list_t* a, list_t* b, list_t* robot, int reverse) {
    if (reverse == 1) {
        reverse_list(b);
    }
    // cout << "robot: " << robot->data << "\n";
    list_t *temp = robot->next;
    if (temp != NULL) {
        temp->prev = NULL;
    }

    b->prev = robot;
    robot->next = b;
    return temp;
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

int register_path(list_t* robot) {
    path[path_index] = robot->data;
    // path.push_back(robot->data);
    path_index++;
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

    list_t *robot = storage[0];
    for (int i=0; i<n; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'F') {
            if (robot->next != NULL) {
                robot = robot->next;
            }
        } else if (cmd == 'B') {
            if (robot->prev != NULL) {
                robot = robot->prev;
            }
        } else if (cmd == 'C') {
            int x;
            cin >> x;
            int target = 0;
            int reverse = 0;
            for (int i=1; i<l; i++) {
                if (front_list(storage[i]) == x) {
                    target = i;
                    break;
                }
            }
            if (target == 0) {
                for (int i=1; i<l; i++) {
                    if (back_list(storage[i]) == x) {
                        reverse = 1;
                        target = i;
                        break;
                    }
                }
            }

            storage[target] = swap(storage[0], storage[target], robot, reverse);
            if (robot->next != NULL) {
                robot = robot->next;
            }
        }
        
        register_path(robot);
 
        // cout << "line";
        // print_list(storage[0]);
    // }
    // for (auto ptr : path) {
    //     cout << ptr << "\n";
    }
    for (int i=0; i<path_index; i++) {
        cout << path[i] << "\n";
    }
}