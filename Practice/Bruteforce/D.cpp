#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> l(int x) {
    vector<pair<int, int>> temp = {};
    
    for (int i = 3; i <= sqrt(x); i++) {
        if (x % i == 0) {
            temp.push_back(make_pair(x / i , i));
        }
    }
    return temp;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<pair<int, int>> A = l(brown + yellow);
    int n = (int)A.size();
    
    for (int i = 0; i < n; i++) {
        int x = A[i].first;
        int y = A[i].second;
        
        int a = 2 * x + 2 * (y - 2);
        if (a == brown) {
            answer = {x, y};
            break;
        }
    }
    
    return answer;
}
