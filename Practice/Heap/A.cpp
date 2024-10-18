#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for (auto& i: scoville) {
        pq.push(i);
    }
    
    while (!pq.empty()) {
        int x = pq.top();
        
        if (x >= K || (int)pq.size() == 1) {
            break;
        }
        
        pq.pop();
        int y = pq.top();
        pq.pop();
        
        pq.push(x + 2 * y);
        answer++;
    }
    
    return (pq.top() >= K ? answer: -1);
}
