+#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    long t=1;
    fast;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        string s = to_string(n);
        if(n%25==0){
            cout<<0<<endl;
            continue;
        }


        vector<string>v={"25","50","00","75"};
        vector<ll> ans;
        for (ll i=0;i<4;i++){
            ll pos1=-1,pos2=-1;
            for(ll j=s.size();j>=0;j--){
                if (s[j]==v[i][1]){
                    pos2=j;
                    break;
                }
            }

            for (ll j=pos2-1;j>=0;j--){
                if(s[j]==v[i][0]){
                    pos1=j;
                    break;
                }
            }
            if (pos1!=-1 && pos2!=-1 && pos2>pos1){
                //n-1-p2+p2+p1-1
                ll temp=s.size()-pos1-2;
                ans.push_back(temp);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans[0]<<endl;

    }}