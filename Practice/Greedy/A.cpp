#include <string>
#include <vector>

using namespace std;

vector<int> V(32, 1);

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for (auto& i: reserve) {
        V[i]++;
    }
    
    for (auto& i: lost) {
        V[i]--;
    }
    
    V[0] = 0;
    V[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        if (!V[i]) {
            if (V[i - 1] > 1) {
                V[i - 1]--;
                V[i]++;
            }
            else if (V[i + 1] > 1) {
                V[i + 1]--;
                V[i]++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (V[i]) {
            answer++;
        }
    }
    
    return answer;
}
