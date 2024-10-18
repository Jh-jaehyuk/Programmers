#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = (int)numbers.size();
    
    q.push(make_pair(numbers[0], 0));
    q.push(make_pair(-numbers[0], 0));
    
    while (!q.empty()) {
        int now = q.front().first;
        int idx = q.front().second;
        q.pop();
        
        if (idx == n - 1) {
            if (now == target) {
                answer++;
            }
            continue;
        }
        
        for (int i: {numbers[idx + 1], -numbers[idx + 1]}) {
            int nxt = now + i;
            q.push(make_pair(nxt, idx + 1));
        }
    }
    
    return answer;
}
