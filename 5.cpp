#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int poisonousPlants(vector<int>& p) {
    int n = p.size();
    vector<int> days(n, 0); 
    stack<int> st;
    int maxDays = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && p[st.top()] >= p[i]) {
            st.pop(); 
        }
        if (!st.empty()) {
            days[i] = days[st.top()] + 1; 
        }
        st.push(i);
        maxDays = max(maxDays, days[i]);
    }

    return maxDays;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    cout << poisonousPlants(p) << endl;
    return 0;
}
