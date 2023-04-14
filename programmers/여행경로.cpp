#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
vector<pair<string, string>> v;
vector<bool> visited;

struct cmp {
    bool operator()(vector<string> a, vector<string> b){
        if(a[0]==b[0]) return a[1]<b[1];
        else if(a[0]=="ICN") return true;
        else if(b[0]=="ICN") return false;
        return a[0]<b[0];
    }
};

bool dfs(int i, int cnt){
    if(visited[i]) return false;
    visited[i]=true;
    answer.push_back(v[i].second);
    
    if(cnt==v.size()-1) return true;
    
    for(int j=0; j<v.size(); j++){
        if(v[j].first==v[i].second){
            if(dfs(j, cnt+1)) return true;
        }
    }
    
    answer.pop_back();
    visited[i]=false;
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp());
    for(vector<string> t:tickets){
        v.push_back(make_pair(t[0], t[1]));
        visited.push_back(false);
    }
    
    int i=0;
    answer.push_back("ICN");
    while(answer.size()==1){
        dfs(i++, 0);
    }
    
    return answer;
}