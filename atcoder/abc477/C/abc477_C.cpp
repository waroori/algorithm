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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int Q; string S,T;
    cin>>Q>>S>>T;
    vector<int> idx;
    bool validity = true;
    if(S.length() < T.length()) validity=false;
    if(validity)
    for(int i=0;i<S.length()-T.length()+1;i++){
        int k=0;
        for(int j=0;j<T.length();j++){
            
            if(S[i+j]==T[j]) k++;
            if(k==T.length())idx.push_back(i);
        }
    }
  
    int x,y;
    bool ans=false;
    for(int i=0;i<Q;i++){
        if(S.length()<T.length()){cout<<"No"<<'\n'; continue;}
        cin>>x>>y;
        x--; 
        ans =false;
        int f=lower_bound(idx.begin(),idx.end(),x)-idx.begin();
        if(idx.size())
        for(int j=f;j<f+1;j++){
            if(idx[j]>=x && idx[j]+T.length()<=y) {ans=true; break;}
        }
        if(ans) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    return 0;
}