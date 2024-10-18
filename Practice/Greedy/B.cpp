#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = (int)name.size();
    int Min = n - 1;
    
    for (int i = 0; i < n; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int nxt = i + 1;
        while (nxt < n && name[nxt] == 'A') {
            nxt++;
        }
        
        Min = min(Min, min(2 * i + n - nxt, i + 2 * (n - nxt)));
    }
    answer += Min;
    
    return answer;
}
