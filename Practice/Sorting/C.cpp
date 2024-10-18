#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = (int)citations.size();
    
    sort(citations.begin(), citations.end());
    
    for (int i = n - 1; i + 1; i--) {
        if (citations[i] >= n - i) {
            answer = n - i;
        }
    }
    
    return answer;
}
