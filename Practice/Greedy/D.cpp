#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> deq;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    for (auto& i: people) {
        deq.push_back(i);
    }
    
    while (!deq.empty()) {
        if ((int)deq.size() >= 2) {
            if (deq.front() + deq.back() <= limit) {
                answer++;
                deq.pop_front();
                deq.pop_back();
            }
            else {
                while (!deq.empty() && deq.front() + deq.back() > limit) {
                    answer++;
                    deq.pop_back();
                }
            }
        }
        else {
            deq.pop_front();
            answer++;
        }
    }
    
    return answer;
}
