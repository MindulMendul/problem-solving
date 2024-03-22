#include<iostream>

using namespace std;

static int pi[100000];

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

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int test_case, answer;
	int T; cin>>T;
    string book, word;
	for(test_case = 1; test_case <= T; ++test_case)
    {
        answer=0; cin>>book>>word;
        getPi(word);
        
        int begin=0, matched=0, wordLen=word.size();
        while(begin+wordLen<=book.size()){
            if(matched<wordLen && book[begin+matched]==word[matched]){
                matched++;
                if(matched==wordLen) answer++;
            } else {
            	if(matched==0) begin++;
                else {
                    begin+=matched-pi[matched-1];
                	matched=pi[matched-1];
                }
            }
        }
        
        cout<<'#'<<test_case<<' '<<answer<<endl;
	}
	return 0;
}