#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph.resize(n);
    visited.resize(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (computers[i][j]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            queue<int> q = {};
            visited[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                
                for (int nxt: graph[now]) {
                    if (!visited[nxt]) {
                        visited[nxt] = 1;
                        q.push(nxt);
                    }
                }
            }
        }
    }
    
    return answer;
}
