#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int visited[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = (int)maps.size();
    int m = (int)maps[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = -1;
        }
    }
    
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            
            if (!maps[nx][ny]) {
                continue;
            }
            
            if (visited[nx][ny] != -1) {
                continue;
            }
            
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    
    return visited[n - 1][m - 1];
}
