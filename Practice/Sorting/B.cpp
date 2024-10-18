#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& i, string& j) {
    return i + j > j + i;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for (auto& num: numbers) {
        temp.push_back(to_string(num));
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for (auto& i: temp) {
        answer += i;
    }
    
    return (answer[0] == '0' ? "0" : answer);
}
