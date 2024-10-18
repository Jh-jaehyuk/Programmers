#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

set<string> S;
set<string> visited;
queue<pair<string, int>> q;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = (int)begin.size();
    
    for (auto& i: words) {
        S.insert(i);
    }
    
    q.push(make_pair(begin, 0));
    visited.insert(begin);
    
    while (!q.empty()) {
        string now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for (int i = 0; i < n; i++) {
            for (char j = 'a'; j <= 'z'; j++) {
                string temp = "";
                for (int k = 0; k < n; k++) {
                    if (k != i) {
                        temp += now[k];
                    }
                    else {
                        temp += j;
                    }
                    
                    if (S.find(temp) == S.end()) {
                        continue;
                    }
                    
                    if (visited.find(temp) != visited.end()) {
                        continue;
                    }
                    
                    visited.insert(temp);
                    if (temp == target) {
                        return cnt + 1;
                    }
                    q.push(make_pair(temp, cnt + 1));
                }
            }
        }
    }
    
    return answer;
}
