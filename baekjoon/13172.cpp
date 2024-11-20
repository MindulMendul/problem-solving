#include <iostream>
#include <regex>
#include <string>

#define MOD 1000000007

using namespace std;

typedef long long int lli;

lli divisor[10000][30];
lli si[10000];

int Euclidean(int a, int b){
    return (a%b==0)?b:Euclidean(b,a%b); // 유클리드 호제법
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M; cin>>M;
    lli Q=0;
    for(int ind=0; ind<M; ind++){
        // n, s를 기약분수로 만들어둠
        int a, b, min_ab; cin>>b>>a;
        min_ab=(a>b)?Euclidean(a, b):Euclidean(b, a);
        a=a/min_ab; b=b/min_ab;

        // divisor 빠르게 구하기 위해 쓰는 배열
        si[ind]=1;
        divisor[ind][0]=b;
        for(int i=1; i<30; i++){
            divisor[ind][i]=divisor[ind][i-1]*divisor[ind][i-1];
            divisor[ind][i]%=MOD;
        }

        // 지수 비트마스킹해서 b^(X-2) 구하는 중
        int divisor_s=MOD-2, divisor_i=0;
        while(divisor_s>0){
            if(divisor_s%2==1){
                si[ind]*=divisor[ind][divisor_i];
                si[ind]%=MOD;
            }
            divisor_s/=2;
            divisor_i++;
        }
        Q+=(a*si[ind])%MOD;
        Q%=MOD;
    }

    cout<<Q;
    
    return 0;
}
