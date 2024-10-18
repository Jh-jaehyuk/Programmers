#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    int min_val = 1e9;
    for (auto& i: times) {
        min_val = min(min_val, i);
    }
    
    answer = 1LL * min_val * n;
    long long left = 0;
    long long right = answer;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        long long cnt = 0;
        for (int i: times) {
            cnt += mid / (1LL * i);
        }
        if (cnt >= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return answer;
}
