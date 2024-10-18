#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
int board[101][101];
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for (auto& i: puddles) {
        board[i[1] - 1][i[0] - 1] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        if (board[i][0]) {
            break;
        }
        dp[i][0] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        if (board[0][i]) {
            break;
        }
        dp[0][i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j]) {
                continue;
            }
            dp[i][j] = ((dp[i - 1][j] % MOD) + (dp[i][j - 1] % MOD)) % MOD;
        }
    }
    
    return dp[n - 1][m - 1];
}
