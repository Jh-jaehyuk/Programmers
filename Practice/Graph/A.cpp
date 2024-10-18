#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
queue<int> q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    graph.resize(n + 1);
    visited.resize(n + 1);
    
    for (auto& i: edge) {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    
    visited[1] = 1;
    q.push(1);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int nxt: graph[now]) {
            if (!visited[nxt]) {
                visited[nxt] = visited[now] + 1;
                q.push(nxt);
            }
        }
    }
    
    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        if (max_val < visited[i]) {
            max_val = visited[i];
            answer = 1;
        }
        else if (max_val == visited[i]) {
            answer++;
        }
    }
    
    return answer;
}
