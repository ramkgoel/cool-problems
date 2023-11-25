#include <iostream>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    int pref[105];
    pref[0] = 0; 
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + (s[i-1] == 'B');
        // cout << "pref" << i << " is " << pref[i] << " ";
    }
    // cout << endl;

    if(pref[n] == k){
        cout << 0 << endl;
        return; 
    }
    else if(pref[n] < k){
        // too few B's. add in the beginning
        for(int i=1; i<=n; i++){
            // make 1..i all B. so #B's = i + #B's in i+1..n <- pref[n] - pref[i]
            if(i + pref[n] - pref[i] == k){
                cout << 1 << endl;
                cout << i << " B" << endl;
                return; 
            }
        }
    }
    else{
        for(int i=1; i<=n; i++){
            // make 1..i all A. so #B's = #B's in i+1..n <- pref[n] - pref[i]
            if(pref[n] - pref[i] == k){
                cout << 1 << endl;
                cout << i << " A" << endl;
                return; 
            }
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    
    while (t--)
        solve();

 
    return 0;
}