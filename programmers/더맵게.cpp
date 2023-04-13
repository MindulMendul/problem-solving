#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

int pop(vector<int>& scoville){
    int result=scoville.front();
    pop_heap(scoville.begin(), scoville.end(), greater());
    scoville.pop_back();
    return result;
}

void push(vector<int>& scoville, int value) {
    scoville.push_back(value);
    push_heap(scoville.begin(), scoville.end(), greater());
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    make_heap(scoville.begin(), scoville.end(), greater());
    
    int a=-1, b=-1;
    while((a+b*2<K || scoville.front()<K) && scoville.size()>1){
        a=pop(scoville);
        b=pop(scoville);

        push(scoville, a+b*2);
        answer++;
    }
    
    if(scoville.size()==1){
        if(scoville.front()>=K) return answer;
        return -1;
    }
    else return answer;
}