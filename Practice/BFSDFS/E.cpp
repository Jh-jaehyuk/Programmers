#include <string>
#include <vector>
#include <queue>

using namespace std;

int board[102][102];
int visited[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            visited[i][j] = -1;
            board[i][j] = -1;
        }
    }
    
    for (auto& i: rectangle) {
        int x1 = i[0] * 2;
        int y1 = i[1] * 2;
        int x2 = i[2] * 2;
        int y2 = i[3] * 2;
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                if (x1 < x && x < x2 && y1 < y && y < y2) {
                    board[x][y] = 0;
                }
                else {
                    if (board[x][y]) {
                        board[x][y] = 1;
                    }
                }
            }
        }
    }
    
    q.push(make_pair(characterX * 2, characterY * 2));
    visited[characterX * 2][characterY * 2] = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx > 102 || ny > 102) {
                continue;
            }
            
            if (board[nx][ny] != 1) {
                continue;
            }
            
            if (visited[nx][ny] != -1) {
                continue;
            }
            
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    
    return visited[itemX * 2][itemY * 2] / 2;
}
