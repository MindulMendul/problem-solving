#include<iostream>

#define MAX 4000000

using namespace std;

static bool visited[MAX];
static int dp[MAX];
int A, B, K;

int poww[6][10] = {
    {0,1,2,3,4,5,6,7,8,9},
    {0,1,4,9,16,25,36,49,64,81},
    {0,1,8,27,64,125,216,343,512,729},
    {0,1,16,81,256,625,1296,2401,4096,6561},
    {0,1,32,243,1024,3125,7776,16807,32768,59049},
    {0,1,64,729,4096,15625,46656,117649,262144,531441}
};

int s(int N){
    int n=N, pos[7], size=0;
    while(n>0){
        pos[size++]=n%10;
        n/=10;
    } 
    n=0;
    for(int i=0; i<size; i++) n+=poww[K-1][pos[i]];
    return n;
}

int min_cycle;
void get_min_cycle(int root, int i){
    if(min_cycle>i) min_cycle=i;
    if(root!=i) get_min_cycle(root, s(i));
}

void set_min_cycle(int root, int i){
    dp[i]=min_cycle;
    if(root!=i) set_min_cycle(root, s(i));
}

void cycle(int root, int i){
    if(root==i) return;
    min_cycle=MAX;
    get_min_cycle(root, i);
    set_min_cycle(root, i);
}

void dfs(int i){
    if(dp[i]<MAX) return;
    if(visited[i]) {
      cycle(i, s(i));
      return;
    }
    visited[i]=true;
    dfs(s(i));
    if(dp[s(i)]<dp[i]) dp[i]=dp[s(i)];
    if(dp[i]>i) dp[i]=i;
}

int main(){
    //initialize
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<MAX; i++) dp[i]=MAX;
    long long int answer=0;
    cin>>A>>B>>K;

    for(int i=0; i<MAX; i++) visited[i]=false;
    for(int i=1; i<=1000000; i++) {
      if(dp[i]<MAX) continue;
      dfs(i);
    }

    //calculate
    for(int i=A; i<=B; i++) answer+=dp[i];
    cout<<answer;
    return 0;
}