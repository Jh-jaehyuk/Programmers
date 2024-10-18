#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<char> s;

string solution(string number, int k) {
    string answer = "";
    
    for (auto& i: number) {
        while (!s.empty() && s.top() < i && k) {
            k--;
            s.pop();
        }
        s.push(i);
    }
    
    while (k) {
        k--;
        s.pop();
    }
    
    vector<char> V = {};
    while (!s.empty()) {
        V.push_back(s.top());
        s.pop();
    }
    int n = (int)V.size();
    for (int i = n - 1; i + 1; i--) {
        answer += V[i];
    }
    
    return answer;
}
