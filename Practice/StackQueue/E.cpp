#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> b;
queue<int> t;
int s = 0;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    for (int i = 0; i < bridge_length; i++) {
        b.push(0);
    }
    
    for (auto& i: truck_weights) {
        t.push(i);
    }
    
    while (!b.empty()) {
        answer++;
        s -= b.front();
        b.pop();
        
        if (!t.empty()) {
            if (s + t.front() <= weight) {
                b.push(t.front());
                t.pop();
            }
            else {
                b.push(0);
            }
            s += b.back();
        }
    }
    
    return answer;
}
