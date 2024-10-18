#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

set<int> S;

int is_prime(int x) {
    if (!x || x == 1) {
        return 0;
    }
    
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

void DFS(vector<char>& v, int depth, int n, int r) {
    if (depth == r) {
        string temp = "";
        for (int i = 0; i < r; i++) {
            temp += v[i];
        }
        S.insert(stoi(temp));
        return;
    }
    
    for (int i = depth; i < n; i++) {
        int x = v[i];
        v[i] = v[depth];
        v[depth] = x;
        DFS(v, depth + 1, n, r);
        v[depth] = v[i];
        v[i] = x;
    }
}

int solution(string numbers) {
    int answer = 0;
    int n = (int)numbers.size();
    
    vector<char> v = {};
    for (auto& i: numbers) {
        v.push_back(i);
    }
    
    for (int i = 1; i <= n; i++) {
        DFS(v, 0, n, i);
    }
    
    for (auto iter=S.begin(); iter != S.end(); iter++) {
        int temp = *iter;

        if (is_prime(temp)) {
            answer++;
        }
    }
    
    return answer;
}
