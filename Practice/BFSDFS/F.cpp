#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>

using namespace std;

map<string, vector<string>> graph;
stack<string> s;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    for (auto& i: tickets) {
        if (graph.find(i[0]) == graph.end()) {
            graph[i[0]] = {i[1]};
        }
        else {
            graph[i[0]].push_back(i[1]);
        }
    }
    
    for (auto& [key, value]: graph) {
        sort(value.begin(), value.end(), greater<string>());
    }
    
    s.push("ICN");
    
    while (!s.empty()) {
        string now = s.top();
        s.pop();
        
        if (graph.find(now) == graph.end() || graph[now].empty()) {
            answer.push_back(now);
        }
        else {
            s.push(now);
            s.push(graph[now].back());
            graph[now].pop_back();
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
