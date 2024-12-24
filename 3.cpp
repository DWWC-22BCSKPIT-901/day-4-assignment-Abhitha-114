#include <iostream>
#include <stack>
#include <string>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0); 
    for (char c : s) {
        if (c == '(') {
            st.push(0); 
        } else {
            int top = st.top();
            st.pop();
            int score = st.top();
            st.pop();
            st.push(score + max(2 * top, 1)); 
        }
    }

    return st.top(); 
}

int main() {
    string s1 = "()";
    string s2 = "(())";
    string s3 = "()()";

    cout << "Example 1 Output: " << scoreOfParentheses(s1) << endl;
    cout << "Example 2 Output: " << scoreOfParentheses(s2) << endl;
    cout << "Example 3 Output: " << scoreOfParentheses(s3) << endl;

    return 0;
}
