#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int a = 0;
    for (auto& i: s) {
        if (i == '(') {
            a++;
        }
        else {
            a--;
        }
        
        if (a < 0) {
            return false;
        }
    }

    return (a ? false : true);
}
