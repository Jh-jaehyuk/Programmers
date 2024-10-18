#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> visited;
int ans = 0;

void DFS(int a, int n, int depth, vector<vector<int>>& dungeons) {
    if (a < 0) {
        ans = max(ans, depth - 1);
        return;
    }
    
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dungeons[i][0] <= a) {
            flag = 1;
            visited[i] = 1;
            DFS(a - dungeons[i][1], n, depth + 1, dungeons);
            visited[i] = 0;
        }
    }
    
    if (!flag) {
        ans = max(ans, depth);
        return;
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int n = (int)dungeons.size();
    visited.resize(n);
    
    DFS(k, n, 0, dungeons);
    
    return ans;
}
