#include<iostream>

#define MAX 3188647

using namespace std;

static int dp[MAX];

int poww[6][10]={
    {1,2,3,4,5,6,7,8,9,0},
    {1,4,9,16,25,36,49,64,91,0},
    {1,8,27,64,125,216,343,512,729,0},
    {1,16,81,256,625,1296,2401,4096,6561,0},
    {1,32,243,1024,3125,7776,16807,32768,59049,0},
    {1,64,729,4096,15625,46656,117649,262144,531441,0}
};

int s(int N, int K){
    int n=N, pos[7], size=0;
    while(n>0){
        pos[size++]=n%10;
        n/=10;
    } 
    n=0;
    for(int i=0; i<size; i++) n+=poww[K-1][pos[i]];
    if(dp[N]>n) dp[N]=n;
    return n;
}

int main(){
    //initialize
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<MAX; i++) dp[i]=MAX;
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