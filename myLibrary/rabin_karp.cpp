#include <iostream>
#include <string>
#define MOD 2147483647
#define BASE 256

using namespace std;

long long h(string s){
    long long ans = 0;
    for(char c : s){
        ans = (ans * BASE + c) % MOD;
    }
    return ans;
}

int Rabin_Karp(string s, string p){
    int n = s.size();
    int m = p.size();
    long long hash_p = h(p);
    long long hash_s = h(s.substr(0,m));

    // top = 제일 자리의 진수값. (BASE ^ m - 1)
    long long top = 1;
    for (int i = 0; i < m - 1; ++i) {
        top = (top * BASE) % MOD;
    }
    for (int i = 0; i < n; ++i) {
        if (hash_p == hash_s) return 1;
        if (i + m < n){
            // 가장 앞에 있는 원소의 해쉬값 삭제
            hash_s = hash_s - (s[i] * top) % MOD;
            // 음수 방지
            hash_s = (hash_s + MOD) % MOD;
            // 다음 수 해쉬 값 더하기
            hash_s = ((hash_s * BASE) % MOD + s[i + m]) % MOD;
        }

    }

    return 0;
}

int main(){
    string s,p;
    cin >> s >> p;
    cout << Rabin_Karp(s,p) << "\n";
    return 0;
}