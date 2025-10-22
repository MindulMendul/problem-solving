#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define DIV 1'000'000'007

int N;
vector<long long int> gochu;
long long int bin[300'001];

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++) {
        long long int go; cin>>go;
        gochu.push_back(go);
    }
    sort(gochu.begin(), gochu.end());

    long long int ans=0;
    bin[0]=1;
    for(int i=1; i<=N; i++) bin[i]=(2*bin[i-1])%DIV;
    
    for (int i=0; i<N; i++) {
        long long diff=(bin[i]-bin[N-1-i]+DIV)%DIV;
        long long term=(gochu[i]*diff)%DIV;
        ans=(ans+term)%DIV;
    }
    if(ans<0) ans+=DIV;
    cout<<ans;
    return 0;
}