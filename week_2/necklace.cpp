#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct list {
    int data;
    struct list *next;
} list_t;

list_t * append(list_t *old_list, int number) {
    list_t* new_list = (list_t*)malloc(sizeof(new_list));
    (*new_list).data = number;
    (*new_list).next = NULL;

    if (old_list == NULL) {
        return new_list;
    } else {
        (*old_list).next = new_list;
        return old_list;
    }
}

list_t * splice(list_t* x, list_t* y) {
    list_t* temp = x;
    while (temp->next != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
    temp->next = y->next;
    y->next = x;
    return y;
}

int print_list(list_t **necklace) {
    list_t *the_necklace = *necklace;
    cout << (the_necklace->data+1) << " ";
    the_necklace = the_necklace->next;
    while (the_necklace != NULL) {
        cout << (the_necklace->data+1) << " ";
        the_necklace = the_necklace->next;
    }
    return 1;
}

int main(void) {
    int n;
    cin >> n;
    list_t** necklace = (list_t**)malloc(sizeof(necklace) * n); 
    
    for (int i=0; i<n; i++) {
        list_t* new_list = (list_t*)malloc(sizeof(new_list));
        new_list = NULL;
        new_list = append(new_list, i);
        necklace[i] = new_list;
    }

    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        necklace[y] = splice(necklace[x], necklace[y]);
    }

    for (int i=0; i<n; i++) {
        print_list(&(necklace[i]));
        cout << "\n";
    }

}