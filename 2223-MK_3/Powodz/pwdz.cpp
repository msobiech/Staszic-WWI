#include <vector>
#include <stdio.h>
using namespace std;

const int MAXN = 1e3;
const int MAXINF = 1e3;
int waterLevel[MAXN*MAXN+1];
int height[MAXN*MAXN+1];
int dx[4] = {1,0,-1,0 };
int dy[4] = {0,1,0,-1 };
bool belongs[MAXN*MAXN+1];
//vector<int> Graph[MAXN*MAXM];
int M[2][MAXINF+1];// 1 - ostatni kwadrat w bajtocji o wysokosci h
//0 - ostatni z kwadratów lezacych na wysokosci h, które sasiaduja z kwadratami, na których woda opadła ponizej poziomu h
int Mprev[2][MAXN*MAXN+1];// 1 - ostatni kwadrat w bajtocji o wysokosci h
//0 - poprzedni z kwadratów lezacych na wysokosci h, które sasiaduja z kwadratami, na których woda opadła ponizej poziomu h
bool isInt(char c){
    if(c>='0' && c<='9')return true;
    return false;
}

int readInt(){
    char c;
    int x = 0;
    int mult = 1;
    while(!isInt(c = getchar_unlocked()) && c!='-'){
    }
    do{
        if(c=='-'){
            mult=-1;
        }
        else{
            x=x*10+int(c-'0');
        }

    }while(isInt(c = getchar_unlocked()) || c=='-');
    return x*mult;
}
/*
void connect(int id, int n, int m){
    //connecting to the left
    //cout << id << ": \n";

    if((id-1)%m!=0){
        //cout << "lacze w lewo\n";
        Graph[id].push_back(id-1);
    }
    //connecting to the up
    if((id-m)>0){
        //cout << "lacze do gory\n";
        Graph[id].push_back(id-m);
    }
    //connecting to the right
    if((id%m)!=0){
        //cout << "lacze w prawo\n";
        Graph[id].push_back(id+1);
    }
    //connecting to the down
    if(id+m<=n*m){
       //cout << "lacze do dolu\n";
       Graph[id].push_back(id+m);
    }
}*/
int main(){
    int n,m;
    //cin >> n >> m;
    n = readInt();
    m = readInt();
    int w = n*m;
    //cout << n << " " << m << endl;
    //int id = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int id = i*m+j;
            height[id] = readInt();
            //cin >> height[id];
            belongs[id] = (height[id]>0);
            //int x = readInt();
            //cout << x << endl;
            //height[id] = x;
            //waterLevel[id] = inf;
            height[id] = max(height[id],-height[id]);
            //cout << inf << endl;

            //connect(id,n,m);
        }
    }
    //cout << inf << endl;
    int inf = 0;
    for(int i = 0;i<w;i++){ inf=max(inf,height[i]+1);}
    for(int i = 0;i<w;i++){
        waterLevel[i]=inf;
    }
    for(int i = 1;i<=inf;i++){
        M[0][i]= -1;
        M[1][i] = -1;
    }
    for(int i = 0;i<w;i++){
        if(belongs[i]){
            Mprev[1][i]=M[1][height[i]];
            M[1][height[i]]=i;
        }
    }
    //for(int i = 1;i<=inf;i++){
    //   cout << M[1][i] << " ";
    //}
    //cout << endl;
    //return 0;
    int ans = 0;
    //cout << "przeglad\n";
    for(int curh = 1;curh<=inf;curh++){
        //cout << curh << endl;
        // while(M[1][curh].size()>0){
        //     cout << M[1][curh].top() << " ";
        //     M[1][curh].pop();
        // }
        //cout << endl;

        while(M[0][curh]>=0 || M[1][curh]>=0){
            int l = 0;
            if(M[0][curh]<0){
                l = 1;
            }
            //cout << l << " ";
            int x = M[l][curh];
            //cout << x << endl;
            M[l][curh]=Mprev[l][x];
            // cout << "rownanie\n";
            if(l==0 || waterLevel[x]==inf){
                if(l==1){
                    ans++;
                    waterLevel[x]=height[x];
                }
                int i0 = x%m;
                int j0 = x/m;
                for(int d = 0;d<4;d++){
                    int i1 = i0+dx[d];
                    int j1 = j0+dy[d];
                    if (i1>=0 && i1<m && j1>=0 && j1<n){
                        int y = j1*m+i1;
                        if(waterLevel[y] == inf){
                            waterLevel[y] = max(height[y],waterLevel[x]);
                            Mprev[0][y]=M[0][waterLevel[y]];
                            M[0][waterLevel[y]]=y;
                            //cout << "water level " << waterLevel[y] << " " << y << endl;
                        }
                    }
                }
            }
            //cout << Msiz << " " << Lsiz << endl;
        }
    }
    printf("%d\n",ans);
    return 0;

}