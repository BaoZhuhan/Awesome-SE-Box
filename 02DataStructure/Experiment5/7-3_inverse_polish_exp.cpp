#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;

    string exp;

    getline( cin, exp );

    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == ' ') continue;
        else if (exp[i] >= '0' and exp[i] <= '9') {
            int n = exp[i] - '0';
            s.push( n );
        } else {
            int a1 = s.top();
            s.pop();
            int a2 = s.top();
            s.pop();

            if (exp[i] == '+') {
                s.push( a1 + a2 );
            } else if (exp[i] == '-') {
                s.push( a2 - a1 );
            } else if (exp[i] == '*') {
                s.push( a1 * a2 );
            } else if (exp[i] == '/') {
                s.push( a2 / a1 );
            }
        }
        //test : cout << s.top() << endl;
    }

    cout << s.top();
}