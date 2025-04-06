#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&a,int i,int j,int& cnt,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0){
        return ;
    }
    vector<int>x={0,1,0,-1};
    vector<int>y={1,0,-1,0};
    cnt=cnt+1;
    a[i][j]=0;
    for(int k=0;k<4;k++){
        int new_x=i+x[k];
        int new_y=j+y[k];
        bfs(a,new_x,new_y,cnt,n,m);
    }
    return;
}
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    // for(auto x:a){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                int cnt=0;
                bfs(a,i,j,cnt,n,m);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());
    // for(auto x:ans){
    //     cout<<x<<" ";
    // }
    cout<<ans.size()<<" "<<ans[ans.size()-1];
    return 0;
}
