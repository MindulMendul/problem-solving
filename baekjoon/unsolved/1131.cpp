#include<iostream>
#include<cmath>

#define MAX 3188647

using namespace std;

static int dp[MAX];

int s(int N, int K){
    int n=N, pos[7], size=0;
    while(n>0){
        pos[size++]=n%10;
        n/=10;
    } 
    n=0;
    for(int i=0; i<size; i++){
        n+=pow(pos[i], K);
    }
    if(dp[N]>n) dp[N]=n;
    return n;
}

int main(){
    //initialize
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<MAX; i++){dp[i]=MAX;}
    int A, B, K, answer=0;
    cin>>A>>B>>K;
    
    //calculate
    int tmp=0;
    for(int i=A; i<=B; i++){
        tmp=s(i, K);
        while(tmp>i){
            if(dp[tmp]<MAX) tmp=dp[tmp];
            else tmp=s(tmp, K);
        }
        answer+=tmp;
    }
    
    //print result
    cout<<answer;
    return 0;
}