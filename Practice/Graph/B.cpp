#include <string>
#include <vector>

using namespace std;

int A[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (auto& i: results) {
        A[i[0]][i[1]] = 1;
        A[i[1]][i[0]] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (!A[j][i]) {
                    continue;
                }
                
                if (A[j][i] == A[i][k]) {
                    A[j][k] = A[j][i];
                    A[k][j] = -A[j][i];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 1; j <= n; j++) {
            if (j == i) {
                continue;
            }
            
            if (!A[i][j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            answer++;
        }
    }
    
    return answer;
}
