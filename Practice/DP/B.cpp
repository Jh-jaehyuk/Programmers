#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = (int)triangle.size();
    dp.resize(n);
    
    for (int i = 0; i < n; i++) {
        dp[i].resize(i + 1);
        dp[i] = triangle[i];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) {
                dp[i][j] = dp[i - 1][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            
            dp[i][j] += triangle[i][j];
        }
    }
    
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}
