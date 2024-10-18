#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& i, vector<int>& j) {
    return (i[1] != j[1] ? i[1] < j[1] : i[0] < j[0]);
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int n = (int)routes.size();
    sort(routes.begin(), routes.end(), cmp);
    
    int e = routes[0][1];
    for (int i = 1; i < n; i++) {
        if (routes[i][0] <= e) {
            continue;
        }
        else {
            answer++;
            e = routes[i][1];
        }
    }
    
    return answer;
}
