#include <string>
#include <vector>
#include <iostream>

using namespace std;

static int a[100000];

vector<int> solution(vector<string> operations) {
    int s=0, e=0;
    for(string str:operations){
        if(str.front()=='I'){
            int tmp=stoi(str.substr(2));
            a[e]=tmp;
            int i=e;
            while(s<i && a[i]<a[i-1]){
                int j=a[i];
                a[i]=a[i-1];
                a[i-1]=j;
            } e++;
            
        } else {
            if(s<e){
                if(str.at(2)=='1'){
                    e--;
                } else {
                    s++;
                }
            }
        }
    }
    if(s<e) return {a[e-1], a[s]};
    return {0,0};
}