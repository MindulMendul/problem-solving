#include <string>
#include <vector>

using namespace std;

static int binary[100];

int makeBinary(long long num){
    int res=0;
    while(num>0){
        binary[res++]=(num%2);
        num/=2;
    }
    
    int i=1;
    while(i<res){
        i+=1;
        i*=2;
        i-=1;
    }
    
    return i;
}

int check(int s, int e){
    if(s==e) return binary[s];
    
    int mid=(s+e)/2;
    
    int left=check(s, mid-1);
    int right=check(mid+1, e);
    
    if(left==-1) return -1;
    if(right==-1) return -1;
    if(binary[mid]==1) return 1;
    if(left==1 || right==1) return -1;
    return 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(int i=0; i<numbers.size(); i++){
        for(int i=0; i<100; i++){
            binary[i]=0;
        }
        int len=makeBinary(numbers[i]);
        
        if(check(0, len-1)>-1) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}