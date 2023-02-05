// https://mattlee.tistory.com/46
//https://velog.io/@suk13574/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98Java-%ED%94%84%EB%A6%BCPrim-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

#include<iostream>
#include<cmath>
#include<queue>

struct Edge {
    int dest;
	double cost;
};

struct cmp{
	bool operator()(Edge a, Edge b){
        return a.cost>b.cost;
    }
};

const double MAX_DIST=1000000000000000.0;

using namespace std;

static int point[1000][2];
static double dist[1000];
static bool visited[1000];

priority_queue<Edge, vector<Edge>, cmp> pq;

double getLength(int x1, int y1, int x2, int y2){
	return pow(x1-x2,2)+pow(y1-y2,2);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
     
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        //initialize
        int N, i, j;
        double answer=0, E;
        cin>>N;
        for(i=0; i<1000; i++){
            dist[i]=MAX_DIST;
            visited[i]=false;
        }
        for(i=0; i<N; i++){cin>>point[i][0];}
        for(i=0; i<N; i++){cin>>point[i][1];}
        pq=priority_queue<Edge, vector<Edge>, cmp>();
        
        //calculate
        int cnt=0, nextI=0; i=0;
        double tmpLen;
        Edge edge;
        visited[0]=true;
        while(cnt<N-1){
            for(j=0; j<N; j++){
                if(visited[j]) continue;
                edge.dest=j;
                edge.cost=getLength(point[i][0], point[i][1], point[j][0], point[j][1]);
                pq.push(edge);
            }
            
            edge=pq.top(); pq.pop();
            while(visited[edge.dest]){edge=pq.top(); pq.pop();}
            i=edge.dest; dist[i]=edge.cost;
            answer+=dist[i]; visited[i]=true;
            cnt++;
        }
        
        //print result
        cin>>E;
        cout<<'#'<<test_case<<' '<<round(E*answer)<<endl;
	}
	return 0;
}