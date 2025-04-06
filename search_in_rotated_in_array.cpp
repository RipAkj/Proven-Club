#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	int n,k;
	cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    int left=0,right=n-1;
    int ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid] == k){
            ans=mid;
            break;
        }
        if(a[left] <= a[mid]){
            if(a[left] <= k and k<a[mid]){
                right = mid-1;
            }
            else left = mid+1;
        }
        else{
            if(a[mid] < k and k<=a[right]){
                left = mid+1;
            }
            else right = mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
