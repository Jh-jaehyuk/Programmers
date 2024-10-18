#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> max_pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
vector<int> V;

vector<string> split(string& s) {
    string com = "";
    string x = "";
    
    int flag = 0;
    for (auto& i: s) {
        if (i == ' ') {
            flag = 1;
            continue;
        }
        
        if (!flag) {
            com += i;
        }
        else {
            x += i;
        }
    }
    
    return {com, x};
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int n = (int)operations.size();
    V.resize(n);
    
    for (int i = 0; i < n; i++) {
        string op = operations[i];
        vector<string> temp = split(op);
        string com = temp[0];
        int num = stoi(temp[1]);
        
        if (com == "I") {
            min_pq.push(make_pair(num, i));
            max_pq.push(make_pair(num, i));
            V[i] = 1;
        }
        else {
            if (num == 1) {
                while (!max_pq.empty() && !V[max_pq.top().second]) {
                    max_pq.pop();
                }
                if (!max_pq.empty()) {
                    V[max_pq.top().second] = 0;
                    max_pq.pop();
                }
            }
            else {
                while (!min_pq.empty() && !V[min_pq.top().second]) {
                    min_pq.pop();
                }
                if (!min_pq.empty()) {
                    V[min_pq.top().second] = 0;
                    min_pq.pop();
                }
            }
        }
    }
    
    while (!min_pq.empty() && !V[min_pq.top().second]) {
        min_pq.pop();
    }
    while (!max_pq.empty() && !V[max_pq.top().second]) {
        max_pq.pop();
    }
    
    if (max_pq.empty() && min_pq.empty()) {
        return {0, 0};
    }
    else {
        return {max_pq.top().first, min_pq.top().first};
    }
}
