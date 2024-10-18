#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a, b;

int solution(vector<vector<int>> sizes) {
    vector<int> Min;
    vector<int> Max;
    
    for (auto& i: sizes) {
        if (i[0] < i[1]) {
            a = i[0];
            b = i[1];
        }
        else {
            a = i[1];
            b = i[0];
        }
        
        Min.push_back(a);
        Max.push_back(b);
    }
    
    a = *max_element(Min.begin(), Min.end());
    b = *max_element(Max.begin(), Max.end());

    return a * b;
}
