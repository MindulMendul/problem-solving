#include <string>
#include<stdio.h>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);

    int N; scanf("%d", &N);
    for(int i=0; i<N; i++){
        int score, tmp;
        score=0;
        tmp=0;
        char s[81]={0};
        scanf("%s", s);
        for(int j=0; j<80; j++){
            if(s[j]=='O') score+=++tmp;
            else tmp=0;
        }
        printf("%d\n",score);
    }

    return 0;
}
