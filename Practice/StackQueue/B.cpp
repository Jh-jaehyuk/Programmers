#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = (int)progresses.size();
    
    int day = 0;
    for (int i = 0; i < n; i++) {
        int now_task = (100 - (progresses[i] + day * speeds[i]));
        day += (now_task % speeds[i] ? now_task / speeds[i] + 1 : now_task / speeds[i]);
        
        int cnt = 0;
        
        int j = i;
        for (j; j < n; j++) {
            if (progresses[j] + day * speeds[j] >= 100) {
                cnt++;
            }
            else {
                break;
            }
        }
        i = j - 1;
        answer.push_back(cnt);
    }
    
    return answer;
}
