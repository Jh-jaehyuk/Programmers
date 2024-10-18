#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = (int)jobs.size();
    int now = 0;
    
    sort(jobs.begin(), jobs.end());
    reverse(jobs.begin(), jobs.end());
    vector<int> ans = {};
    
    while ((int)ans.size() != n) {
        while (!jobs.empty() and now >= jobs.back()[0]) {
            vector<int> temp = jobs.back();
            jobs.pop_back();
            pq.push(make_pair(temp[1], temp[0]));
        }
        
        if (!jobs.empty() && pq.empty()) {
            vector<int> temp = jobs.back();
            jobs.pop_back();
            now = temp[0];
            pq.push(make_pair(temp[1], temp[0]));
        }
        
        pair<int, int> temp = pq.top();
        pq.pop();
        now += temp.first;
        ans.push_back(now - temp.second);
    }
    
    for (auto& i: ans) {
        answer += i;
    }
    
    return answer / n;
}
