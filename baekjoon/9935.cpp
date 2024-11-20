#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, C4; cin>>s>>C4;
    string tmp="";

    int len_s=s.length();
    int len_c4=C4.length();
    for(int i=0; i<len_s; i++){
        tmp+=s[i];
        bool flag=true;
        for(int j=len_c4-1; j>=0; j--){
            if(C4[j]!=tmp[tmp.size()+j-len_c4]) { flag=false; break; }
        }

        if(flag){
            tmp.erase(tmp.end() - len_c4, tmp.end());
        }
    }

	if(tmp.size()==0) cout<<"FRULA";
    else cout<<tmp;
    
    return 0;
}
