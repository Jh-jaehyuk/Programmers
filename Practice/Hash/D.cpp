#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int n = (int)clothes.size();
    for (int i = 0; i < n; i++) {
        if (m.find(clothes[i][1]) != m.end()) {
            m[clothes[i][1]]++;
        }
        else {
            m[clothes[i][1]] = 1;
        }
    }
    
    for (auto& [key, value]: m) {
        answer *= (value + 1);
    }
    
    return answer - 1;
}
