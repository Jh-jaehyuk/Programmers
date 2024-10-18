#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for (int i = 0; i < n - 1; i++) {
        vector<vector<int>> graph;
        vector<int> visited;
        graph.resize(n + 1, {});
        visited.resize(n + 1 , 0);
        
        for (int j = 0; j < n - 1; j++) {
            if (j == i) {
                continue;
            }
            
            graph[wires[j][0]].push_back(wires[j][1]);
            graph[wires[j][1]].push_back(wires[j][0]);
        }
        
        for (int j = 1; j <= n; i++) {
            int a = 1;
            
            if (!visited[j]) {
                queue<int> q = {};
                q.push(j);
                visited[j] = 1;
                
                while (!q.empty()) {
                    int now = q.front();
                    q.pop();
                    
                    for (auto& nxt: graph[now]) {
                        if (!visited[nxt]) {
                            visited[nxt] = 1;
                            q.push(nxt);
                            a++;
                        }
                    }
                }
                answer = min(answer, abs(a - (n - a)));
                break;
            }
        }
    }
    
    return answer;
}
