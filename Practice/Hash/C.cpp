#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> m;
    
    for (auto& i: phone_book) {
        m[i] = 1;
    }
    
    for (auto& i: phone_book) {
        string temp = "";
        for (auto& j: i) {
            temp += j;
            
            if (m.find(temp) != m.end() && temp != i) {
                return false;
            }
        }
    }
    
    return true;
}
