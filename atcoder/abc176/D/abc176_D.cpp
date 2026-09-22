#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <utility>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
typedef long long ll;
using namespace std;
const int INF =1e9+7;
const ll MOD = 998244353;

queue<pair<int,int>> q; //점프한 곳에서 bfs좌표들 저장
queue<pair<int,int>> j; //점프한 곳
queue<pair<int,int>> b; //bfs용 큐
string mapp[1000];
int dist[1000][1000];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int jx[20] = {-2,-1,0,1,2,-2,-1,1,2,-2,2,-2,-1,1,2,-2,-1,0,1,2};
int jy[20] = {-2,-2,-2,-2,-2,-1,-1,-1,-1,0,0,1,1,1,1,2,2,2,2,2};
int H,W;

void bfs(int dis){
    while(!j.empty()){
        int fx = j.front().first;
        int fy = j.front().second;
        dist[fx][fy]=dis;
        j.pop();
        b.push({fx,fy});
        q.push({fx,fy});

        while(!b.empty()){
            int x = b.front().first;
            int y = b.front().second;
            b.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<H && nx>=0 && ny<W && ny>=0){
                    if(mapp[nx][ny]=='#') continue;
                    if(dist[nx][ny]==-1){
                        q.push({nx,ny});
                        b.push({nx,ny});
                        dist[nx][ny]=dis;
                    }
                }
            }
        }
    }
}

void jump(int dis){
    while(!q.empty()){
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for(int i=0;i<20;i++){
            int nx = fx+jx[i];
            int ny = fy+jy[i];

            if(nx<H && nx>=0 && ny<W && ny>=0){
                if(mapp[nx][ny]=='#') continue;
                if(dist[nx][ny]==-1){
                    j.push({nx,ny});
                    dist[nx][ny]=dis+1;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin>>H>>W;
    int ch,dh,cw,dw;
    cin>>ch>>cw>>dh>>dw;
    ch--; dh--; cw--; dw--;

    fill_n(dist[0],1000000,-1);

    for(int i=0;i<H;i++) cin>>mapp[i];
    int cnt=0;
    j.push({ch,cw});

    while(!j.empty()){
        bfs(cnt);
        jump(cnt);
        if(dist[dh][dw]!=-1) break;
        cnt++;
    }
    cout<<dist[dh][dw];

    return 0;
}
