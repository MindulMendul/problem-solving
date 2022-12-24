#include <stdio.h>

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s = "";
        getline(cin, s);
        s += ' ';
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << s[i];
            }
            else st.push(s[i]);
        }
    }
}
