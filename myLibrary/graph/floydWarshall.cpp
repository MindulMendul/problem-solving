#include <iostream>

#define MAX 1050000000

using namespace std;

int cost[101][101];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    // cost init
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cost[i][j]=(i==j)?0:MAX;
        }
    }

    for(int i=0; i<M; i++){
        int s, e, c;
        cin>>s>>e>>c;
        if(c<cost[s][e]) cost[s][e]=c;
    }

    //calculate
    for(int mid=1; mid<=N; mid++){
        for(int s=1; s<=N; s++){
            for(int e=1; e<=N; e++){
                int mid_cost=cost[s][mid]+cost[mid][e];
                if(mid_cost<cost[s][e]){
                    cost[s][e]=mid_cost;
                }
            }
        }
    }

    for(int s=1; s<=N; s++){
        for(int e=1; e<=N; e++){
            if(cost[s][e]==MAX)cout<<0<<' ';
            else cout<<cost[s][e]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
