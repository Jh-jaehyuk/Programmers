#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;
vector<string> s;
vector<pair<int, int>> V;

bool cmp1(string& i, string& j) {
    return m[i] > m[j];
}

bool cmp2(pair<int, int>& i, pair<int, int>& j) {
    if (i.first != j.first) {
        return i.first > j.first;
    }
    return i.second < j.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = (int)genres.size();
    
    for (int i = 0; i < n; i++) {
        if (m.find(genres[i]) == m.end()) {
            m[genres[i]] = plays[i];
            s.push_back(genres[i]);
        }
        else {
            m[genres[i]] += plays[i];
        }
    }
    
    sort(s.begin(), s.end(), cmp1);
    for (int i = 0; i < n; i++) {
        V.push_back(make_pair(plays[i], i));
    }
    sort(V.begin(), V.end(), cmp2);
    
    for (auto& i: s) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (genres[V[j].second] == i) {
                answer.push_back(V[j].second);
                if (++cnt >= 2) {
                    break;
                }
            }
        }
    }
    
    return answer;
}
