#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<pair<int, int>> s;
vector<int> answer;

vector<int> solution(vector<int> prices) {
    int n = (int)prices.size();
    answer.resize(n);
    
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push(make_pair(prices[i], i));
            continue;
        }
        
        while (!s.empty() && s.top().first > prices[i]) {
            answer[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push(make_pair(prices[i], i));
    }
    
    while (!s.empty()) {
        answer[s.top().second] = n - 1 - s.top().second;
        s.pop();
    }
    
    return answer;
}
