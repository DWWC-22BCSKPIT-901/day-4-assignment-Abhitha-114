#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;
    queue<int> sandwichQueue;

    
    for (int s : students) {
        studentQueue.push(s);
    }
    for (int s : sandwiches) {
        sandwichQueue.push(s);
    }

    int loopCount = 0; 

    while (!studentQueue.empty() && !sandwichQueue.empty()) {
        if (studentQueue.front() == sandwichQueue.front()) {
            
            studentQueue.pop();
            sandwichQueue.pop();
            loopCount = 0; 
        } else {
           
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
            loopCount++;
        }


        if (loopCount == studentQueue.size()) {
            break;
        }
    }


    return studentQueue.size();
}

int main() {
    vector<int> students1 = {1, 1, 0, 0};
    vector<int> sandwiches1 = {0, 1, 0, 1};
    cout << "Example 1 Output: " << countStudents(students1, sandwiches1) << endl;

    vector<int> students2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    cout << "Example 2 Output: " << countStudents(students2, sandwiches2) << endl;

    return 0;
}
