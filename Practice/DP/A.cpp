#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<set<int>> V;

int solution(int N, int number) {
    V.resize(9);
    
    for (int i = 1; i < 9; i++) {
        string temp = "";
        string si = to_string(N);
        for (int j = 0; j < i; j++) {
            temp += si;
        }
        V[i].insert(stoi(temp));
        for (int j = 0; j <= i / 2; j++) {
            for (auto iter1 = V[j].begin(); iter1 != V[j].end(); iter1++) {
                for (auto iter2 = V[i - j].begin(); iter2 != V[i - j].end(); iter2++) {
                    V[i].insert(*iter1 + *iter2);
                    V[i].insert(*iter1 - *iter2);
                    V[i].insert(*iter2 - *iter1);
                    V[i].insert(*iter1 * *iter2);
                    if (*iter2) {
                        V[i].insert(*iter1 / *iter2);
                    }
                    if (*iter1) {
                        V[i].insert(*iter2 / *iter1);
                    }
                }
            }
        }
        if (V[i].find(number) != V[i].end()) {
            return i;
        }
    }
    
    return -1;
}
