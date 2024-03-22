static void swap(int* a, int* b){
	int tmp=*a;
    *a=*b;
    *b=tmp;
}

struct Feed {
    int uID;
    int like;
    int tStamp;
};

static Feed feed[100000];
static bool following[1000][1000];
static int size;

void init(int N)
{
    size=0;
    for(int i=0; i<1000; i++){
    	for(int j=0; j<1000; j++){
        	following[i][j]=(i==j);
        }
    }
    for(int i=0; i<100000; i++){
    	feed[i]={-1, 0, 0};
    }
}

void follow(int uID1, int uID2, int timestamp)
{
    // ignore timestamp
    following[uID1][uID2]=true;
}

void makePost(int uID, int pID, int timestamp)
{
    feed[pID].uID=uID;
    feed[pID].like=0;
    feed[pID].tStamp=timestamp;
    size++;
}

void like(int pID, int timestamp)
{
    // ignore timestamp
    feed[pID].like++;
}

void getFeed(int uID, int timestamp, int pIDList[])
{
    //insertion sorting
    for(int i=0; i<10; i++){
    	pIDList[i]=0;
    }
    for(int i=size; i>=0; i--){
		if(following[uID][feed[i].uID]){
            if(pIDList[9]==0) {
                pIDList[9]=i;
            } else {
                if(timestamp-feed[i].tStamp<=1000){
                    if(feed[pIDList[9]].like==feed[i].like) {  if(feed[pIDList[9]].tStamp<feed[i].tStamp) pIDList[9]=i; }
                    else if(feed[pIDList[9]].like<feed[i].like) pIDList[9]=i;
                } else {
                    if(feed[pIDList[9]].tStamp<feed[i].tStamp) pIDList[9]=i;
                    else if(timestamp-feed[i].tStamp>1000) break;
                }
            }
            
            for(int j=8; j>=0; j--){
                if(pIDList[j]==0) {
                    swap(&pIDList[j], &pIDList[j+1]);
            	} else {
                    if(timestamp-feed[pIDList[j+1]].tStamp<=1000){
                        if(feed[pIDList[j]].like==feed[pIDList[j+1]].like) {if(feed[pIDList[j]].tStamp<feed[pIDList[j+1]].tStamp) swap(&pIDList[j], &pIDList[j+1]);}
                        else if(feed[pIDList[j]].like<feed[pIDList[j+1]].like) swap(&pIDList[j], &pIDList[j+1]);
                    } else {
                        if(feed[pIDList[j]].tStamp<feed[pIDList[j+1]].tStamp){
                            swap(&pIDList[j], &pIDList[j+1]);
                        }
                    }
                }
            }
        }
    }
}