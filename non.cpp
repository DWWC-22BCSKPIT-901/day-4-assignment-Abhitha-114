#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqueChar(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) return i;
    }
    return -1;
}

int main() {
    cout << firstUniqueChar("leetcode") << endl;       // Output: 0
    cout << firstUniqueChar("loveleetcode") << endl;  // Output: 2
    cout << firstUniqueChar("aabb") << endl;          // Output: -1
    return 0;
}
