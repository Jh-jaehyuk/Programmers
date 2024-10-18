#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> C = {'A', 'E', 'I', 'O', 'U'};
vector<string> V;
char temp[5];

void DFS(int depth, int x) {
    if (depth == x) {
        string a = "";
        for (int j = 0; j < x; j++) {
            a += temp[j];
        }
        V.push_back(a);
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        temp[depth] = C[i];
        DFS(depth + 1, x);
    }
}

int solution(string word) {
    int answer = 0;
    
    for (int i = 1; i <= 5; i++) {
        DFS(0, i);
    }
    
    sort(V.begin(), V.end());
    int n = (int)V.size();
    
    for (int i = 0; i < n; i++) {
        if (V[i] == word) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}
