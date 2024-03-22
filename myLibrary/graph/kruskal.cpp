#include<iostream>
#include<algorithm>

using namespace std;

struct Road {
	int src;
    int dest;
    int cost;
};

static int parent[50000];
static Road road[200000];

bool comp(Road a, Road b){ return a.cost<b.cost; }
int findParent(int c){return (c==parent[c])?c:findParent(parent[c]);}

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        //initialize
        int N, M, i; cin>>N>>M;
        for(i=0; i<N; i++){parent[i]=i;}
        for(i=0; i<M; i++){
            int s,e,c; cin>>s>>e>>c;
            road[i].src=s-1;
            road[i].dest=e-1;
            road[i].cost=c;
        }
        sort(road, road+M, comp);
        
        //find MST
        long long int answer=0;
        int cnt=0;
        for(i=0; i<M; i++){
            int rSrc=road[i].src, rDest=road[i].dest, rCost=road[i].cost;
            int pSrc=findParent(rSrc), pDest=findParent(rDest);
            
            if(pSrc!=pDest){
                if(pSrc<pDest) parent[pDest]=pSrc;
                else parent[pSrc]=pDest;
                answer+=rCost; cnt++;
            }
            
            if(cnt==N-1) break;
       }
        
        cout<<'#'<<test_case<<' '<<answer<<endl;
	}
	return 0;
}