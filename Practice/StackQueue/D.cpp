#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

deque<pair<int, int>> deq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = (int)priorities.size();
    
    for (int i = 0; i < n; i++) {
        deq.push_back(make_pair(priorities[i], i));
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int p = priorities[i];
        while (deq.front().first != p) {
            deq.push_back(deq.front());
            deq.pop_front();
        }
        cnt++;
        if (deq.front().second == location) {
            answer = cnt;
            break;
        }
        deq.pop_front();
    }
    
    return answer;
}
