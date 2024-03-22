#include <string>
#include <vector>

using namespace std;

static int inEdge[1000009];
static int outEdge[1000009];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    int _max=0;
    for(int i=0; i<edges.size(); i++){
        outEdge[i]=0;
        inEdge[i]=0;
    }
    
    for(int i=0; i<edges.size(); i++){
        outEdge[edges[i][0]]++;
        inEdge[edges[i][1]]++;
        if(_max<edges[i][0])_max=edges[i][0];
        if(_max<edges[i][1])_max=edges[i][1];
    }
    
    for(int i=1; i<=_max; i++){
        if(outEdge[i]>1 && inEdge[i]==0){
            answer.push_back(i);
        }
    }
    
    int stick=0, eight=0;
    for(int i=1; i<=_max; i++){
        if(outEdge[i]==0 && inEdge[i]){stick++;}
        if(inEdge[i]>1 && outEdge[i]>1){eight++;}
    }
    
    answer.push_back(outEdge[answer[0]]-stick-eight);
    answer.push_back(stick);
    answer.push_back(eight);
    
    return answer;
}