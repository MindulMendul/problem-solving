#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    string strA = to_string(a);
	string strB = to_string(b);
        
	return strA + strB > strB + strA;
}

static int num[1000];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, tmp;
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>num[i];
    }
    
    sort(num, num+N, compare);

    if(num[0]==0){
        cout<<0;
        return 0;
    }
    
    for(int i=0; i<N; i++){
        cout<<num[i];
    }
    return 0;
}