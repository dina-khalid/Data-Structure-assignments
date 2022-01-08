////
//// Created by dinak on 11/19/2021.
////

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    for (int i =0;i<k;i++){
        if(n%10==0){
            n=n/10;
        }
        else{
            n--;
        }    }



    cout<<n;
    return 0;
}