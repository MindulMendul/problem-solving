#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>

struct Edge {
    int dest;
	unsigned int cost;
};

struct cmp{
	bool operator()(Edge a, Edge b){
        return a.cost>b.cost;
    }
};

using namespace std;

priority_queue<Edge, vector<Edge>, cmp> pq;

unsigned int getCost(int x1, int y1, int z1, int x2, int y2, int z2){
    return min({abs(x1-x2), abs(y1-y2), abs(z1-z2)});
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //initialize
    int N, i, j, answer=0;
    cin >> N;

    int point[N][3];
    bool visited[N];

    for(i=0; i<N; i++){
        visited[i]=false;
    }

    for(i=0; i<N; i++){
        cin>>point[i][0]>>point[i][1]>>point[i][2];
    }

    pq=priority_queue<Edge, vector<Edge>, cmp>();
    
    //calculate
    int cnt=0; i=0;
    Edge edge;
    visited[0]=true;

    while(cnt<N-1){
        
    }
    
    //print result
    cout<<answer<<endl;
	return 0;
}