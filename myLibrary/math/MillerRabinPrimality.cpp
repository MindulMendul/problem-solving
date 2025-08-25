#include <iostream>

using namespace std;

using ull = unsigned long long;

static ull base[3] = {2, 7, 61};

// x^y % m
ull powmod(ull x, ull y, ull m) {
    ull a=x%m, d=y;
    ull r=1ULL;
    while (d > 0) {
        if (d%2==1) r=(r*a) % m;
        a=(a*a) % m;
        d/=2;
    }
    return r;
}

inline bool millerRabin(ull n, ull a){
    ull d=n-1;
    while (d%2==0) {
        if (powmod(a, d, n) == n-1)
            return true;
        d/=2;
    }
    ull tmp = powmod(a, d, n);
    return tmp == n-1 || tmp == 1;
}

bool isPrime(ull n){
    if(n<=1) return false;
    if (n <= 1000ULL) {
        for (ull i=2; i*i<=n; i++) if (n%i==0) return false;
        return true;
    }
    for(ull a:base) if(!millerRabin(n, a)) return false;
    return true;
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, answer=0;
    ull s;
    cin >> N;
    for(int i=0; i<N; i++){
        cin>>s;
        if(isPrime(2*s+1)) answer++;
    }
    cout << answer;
    return 0;
}
