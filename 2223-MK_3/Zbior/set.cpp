#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using os_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    os_set<int> S;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a==1){
            S.insert(b);
        }
        else if(a==2){
            S.erase(b);
        }
        else{
            cout << *S.find_by_order(b-1) << endl;
        }
        //printSet(S);
    }
}