#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cmath>
#include <map>

using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int N, Q, l, r, v;
    cin >> N >> Q;
    vector<ll> indices; 
    vector<vector<int> > lrv;
    vector<pair<int, int> > queries; 
    for(int i=0; i<N; i++){
        cin>>l>>r>>v; 
        l++; 
        r++; 
        lrv.push_back({l, r, v}); 
        indices.push_back(l);
        indices.push_back(r); 
    }
    for(int i=0; i<Q; i++){
        cin>>l>>r;
        indices.push_back(l); 
        indices.push_back(r); 
        queries.push_back(make_pair(l, r)); 
    }

    sort(indices.begin(), indices.end()); 
    indices.erase(unique(indices.begin(), indices.end()), indices.end()); 

    // for(int i=0; i<indices.size(); i++){
    //     cout << indices[i] << " "; 
    // }

    int k = indices.size(); 
    map<int, int> idx; 
    for(int i=0; i<k; i++){
        idx[indices[i]] = i; 
    }

    // for(auto const& x: idx){
    //     cout << x.first << " " << x.second << endl; 
    // }

    vector<ll> delta(k), a(k), psum(k); 
    for(int i=0; i<N; i++){
        l = lrv[i][0]; 
        r = lrv[i][1]; 
        v = lrv[i][2]; 
        delta[idx[l]] += v; 
        delta[idx[r]] -= v;
    }

    a[0] = delta[0]; 
    for(int i=1; i<k; i++){
        a[i] = a[i-1] + delta[i]; 
    }

    // for(int i=0; i<k; i++){
    //     cout << delta[i] << " "; 
    // }
    // cout << endl; 
    // for(int i=0; i<k; i++){
    //     cout << a[i] << " "; 
    // }
    // cout << endl; 

    psum[0] = a[0]; 
    for(int i=1; i<k; i++){
        psum[i] = psum[i-1] + a[i-1] * (indices[i] - indices[i-1] - 1) + a[i]; 
    }

    // for(int i=0; i<k; i++){
    //     cout << psum[i] << " "; 
    // }

    for(int i=0; i<Q; i++){
        l = queries[i].first; 
        r = queries[i].second; 
        cout << psum[idx[r]] - psum[idx[l]] << endl; 
    }

}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    solve(); 
 
    return 0;
}