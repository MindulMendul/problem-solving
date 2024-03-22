#include<iostream>
#include<string>
#include<queue>

using namespace std;

static char field[300][300];
static bool visited[300][300];
static int N;
static int dr[8]={1, 1, 0, -1, -1, -1, 0, 1};
static int dc[8]={0, -1, -1, -1, 0, 1, 1, 1};

bool checkSafe(int x, int y){
	int i, dx, dy;
    for(i=0; i<8; i++){
    	dx=x+dr[i]; dy=y+dc[i];
        if(dx>=0 && dy>=0 && dx<N && dy<N){
        	if(field[dx][dy]=='*') return false;
        }
    }
    return true;
}

int bfs(){
    int result=0, x, y, dx, dy;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
			if(!visited[i][j] && field[i][j]=='.' && checkSafe(i, j)){
                result++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    x=q.front().first;
                    y=q.front().second;
                    visited[x][y]=true;
                    q.pop();
                    
                    for(int k=0; k<8; k++){
                        dx=x+dr[k]; dy=y+dc[k];
                        if(dx>=0 && dy>=0 && dx<N && dy<N){
                            if(!visited[dx][dy] && field[dx][dy]=='.'){
                            	visited[dx][dy]=true;
                                if(checkSafe(dx, dy)) q.push(make_pair(dx, dy));
                            }
                        }
                    }
                }
        	}
        }
    }
    
    return result;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int test_case, T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        //initialize
        cin>>N;
        for(int i=0; i<N; i++){
            string str; cin>>str;
            for(int j=0; j<N; j++){
                field[i][j]=str[j];
                visited[i][j]=false;
            }
        }
        
        //calculate
        int answer=bfs();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                answer+=(!visited[i][j] && field[i][j]=='.');
            }
        }
        
        //print result
        cout<<'#'<<test_case<<' '<<answer<<endl;
	}
	return 0;
}