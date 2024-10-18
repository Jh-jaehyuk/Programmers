#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> a = {1, 2, 3, 4, 5};
vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int n = (int)answers.size();
    
    int A[3] = {0, 0, 0};
    
    for (int i = 0; i < n; i++) {
        if (answers[i] == a[i % 5]) {
            A[0]++;
        }
        if (answers[i] == b[i % 8]) {
            A[1]++;
        }
        if (answers[i] == c[i % 10]) {
            A[2]++;
        }
    }
    
    int Max = *max_element(A, A + 3);
    for (int i = 0; i < 3; i++) {
        if (A[i] == Max) {
            answer.push_back(i + 1);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
