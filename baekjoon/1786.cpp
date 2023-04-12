#include <iostream>
#include <queue>

using namespace std;

static int pi[1000000];

void getPi(string word){
    int begin=1, matched=0, len=word.size();
    for(int i=0; i<len; i++){pi[i]=0;}
    while(begin+matched<len) {
        if(word[begin+matched]==word[matched]){
            matched++;
            pi[begin+matched-1]=matched;
        } else {
        	if(matched==0) begin++;
            else {
            	begin += matched-pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string book, word;
    getline(cin, book);
    getline(cin, word);
    getPi(word);
    
    queue<int> index;
    int begin=0, matched=0, wordLen=word.size();
    while(begin+wordLen<=book.size()){
        if(matched<wordLen && book[begin+matched]==word[matched]){
            matched++;
            if(matched==wordLen){
                index.push(begin);
            }
        } else {
        	if(matched==0) begin++;
            else {
                begin+=matched-pi[matched-1];
            	matched=pi[matched-1];
            }
        }
    }
    int ans=index.size();
    cout<<ans<<endl;

    for(int i=0; i<ans; i++){
        cout<<index.front()+1<<" ";
        index.pop();
    }

    return 0;
}
