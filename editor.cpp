#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;
    string s = "";
    int q;
    cin >> q;
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // append
            string w;
            cin >> w;
            history.push(s);
            s += w;
        } else if (type == 2) { // delete
            int k;
            cin >> k;
            history.push(s);
            s.erase(s.size() - k);
        } else if (type == 3) { // print
            int k;
            cin >> k;
            cout << s[k - 1] << endl;
        } else if (type == 4) { // undo
            s = history.top();
            history.pop();
        }
    }
    return 0;
}
