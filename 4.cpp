#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int maxSi(vector<int>& A) {
    int n = A.size();
    stack<int> st;
    int maxSi = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() > A[i]) {
            int M1 = st.top();
            st.pop();
            int M2 = st.empty() ? A[i] : max(st.top(), A[i]);
            maxSi = max(maxSi, (((M1 & M2) ^ (M1 | M2)) * (M1 ^ M2)));
        }
        st.push(A[i]);
    }

    while (st.size() > 1) {
        int M1 = st.top();
        st.pop();
        int M2 = st.top();
        maxSi = max(maxSi, (((M1 & M2) ^ (M1 | M2)) * (M1 ^ M2)));
    }

    return maxSi;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cout << maxSi(A) << endl;
    return 0;
}
