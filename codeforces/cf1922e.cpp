#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int X;
    cin >> X; 
    int curMax = 1; 

    string binrep = "";    
    while(X != 0){
        if(X%2==0){
            binrep += "0";
            X = X/2; 
        }
        else{
            binrep += "1";
            X = (X-1)/2; 
        }
    }
    reverse(binrep.begin(), binrep.end());

    vector<int> ans; 
    for(int i=1; i<binrep.size(); i++){
        if(binrep[i] == '1'){
            ans.push_back(curMax);
            ans.insert(ans.begin(), curMax+1); 
            curMax += 2; 
        }
        else{
            ans.push_back(curMax); 
            curMax++; 
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl; 
    
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    
    while (t--)
        solve();
 
    return 0;
}