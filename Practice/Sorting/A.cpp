#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& A, int& x) {
    sort(A.begin(), A.end());
    return A[x - 1];
}


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto& com: commands) {
        int s = com[0];
        int e = com[1];
        int x = com[2];
        
        vector<int> temp = {};
        for (int i = s - 1; i < e; i++) {
            temp.push_back(array[i]);
        }
        
        answer.push_back(solve(temp, x));
    }
    
    return answer;
}
