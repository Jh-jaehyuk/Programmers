#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> parent;

bool cmp(vector<int>& i, vector<int>& j) {
    if (i[2] != j[2]) {
        return i[2] < j[2];
    }
    else {
        if (i[0] != j[0]) {
            return i[0] < j[0];
        }
        return i[1] < j[1];
    }
}

int find(int x) {
    if (parent[x] == x) {
        return parent[x];
    }
    return parent[x] = find(parent[x]);
}

void munion(int a, int b) {
    int x = find(a);
    int y = find(b);
    
    if (x < y) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    graph.resize(n);
    parent.resize(n);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    sort(costs.begin(), costs.end(), cmp);
    int cnt = 0;
    
    for (auto& cost: costs) {
        if (find(cost[0]) != find(cost[1])) {
            munion(cost[0], cost[1]);
            cnt++;
            answer += cost[2];
            if (cnt == n - 1) {
                break;
            }
        }
    }

    return answer;
}
