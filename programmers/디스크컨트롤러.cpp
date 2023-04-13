#include <string>
#include <queue>
#include <vector>
//#include <iostream>
#include <algorithm>

using namespace std;

bool sortCmp (pair<int, int> a, pair<int, int> b) {
    return a.first<b.first;    
}

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.second==b.second) return a.first>b.first;    
        else return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    vector<pair<int, int>> v;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    int sum=0, i=0, size=jobs.size();
    while(i<size){
        v.push_back(make_pair(jobs[i][0], jobs[i][1]));
        i++;
    } i=0;
    sort(v.begin(), v.end(), sortCmp);
    
    int time=v[i].first;
    while(i<size || pq.size()>0){
        //cout<<v[i].first<<" "<<time<<endl;
        while(i<size && v[i].first<=time){
            pq.push(v[i++]);
        }
        if(pq.size()==0) time=v[i].first;
        else {
            pair<int, int> p=pq.top(); pq.pop();
            //cout<<p.first<<"/"<<p.second<<" time:"<<time<<" "<<p.second+(time-p.first)<<endl;
            sum+=p.second+(time-p.first);
            time+=p.second;
        }
    }
    return sum/size;
}