#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin>>N>>K;
    vector<pair<int, int>> knapsack;
    for(int i=0; i<N; i++){
        int W, V; cin>>W>>V;
        knapsack.push_back(make_pair(W,V));
    }

    for(int i=0; i<N; i++){
        dp[i][0]=0;
    }

    for(int w=0; w<=K; w++){
        dp[0][w]=(w>=knapsack[0].first)?knapsack[0].second:0;
    }

    for(int i=1; i<N; i++){
        for(int w=1; w<=K; w++){
            
            if(knapsack[i].first>w){
                dp[i][w]=dp[i-1][w];
            } else {
                dp[i][w]=max(dp[i-1][w], knapsack[i].second+dp[i-1][w-knapsack[i].first]);
            }
        }
    }
    
    cout<<dp[N-1][K];
    return 0;
}
