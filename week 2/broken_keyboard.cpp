#include <iostream>
#include <list>

using namespace std;

int main(void) {
    while (1) {
        string text;
        cin >> text;
        list<char> para;
        list<char>::iterator ptr = para.begin();

        if (text == "") {
            break;
        }

        for (int i=0; i<text.size(); i++) {
            if (text[i] == '[') {
                ptr = para.begin();
            } else if (text[i] == ']') {
                ptr = para.end();
            } else {
                para.insert(ptr, text[i]);
            }
        }

        for (auto v : para) {
            cout << v;
        }

        cout << "\n" ;
    }

}