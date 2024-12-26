#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            if ((c == ')' && st.top() != '(') ||
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '[')) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << (isBalanced(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
