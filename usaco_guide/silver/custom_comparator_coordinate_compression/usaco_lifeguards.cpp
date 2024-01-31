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
    int N,a,b; 
    cin >> N; 
    vector<pair<int,int> > shifts; 
    vector<int> indices; 
    for(int i=0; i<N; i++){
        cin>>a>>b;
        shifts.push_back(make_pair(a,b)); 
        indices.push_back(a); 
        indices.push_back(b); 
    }
    sort(indices.begin(), indices.end()); 
    int k = indices.size(); 
    map<int, int> idx; 
    for(int i=0; i<k; i++){
        idx[indices[i]] = i; 
    }

    // cout << endl; 
    // for(const auto &pair : idx){
    //     cout << pair.first << " " << pair.second << endl; 
    // }


    vector<int> delta(k), numGuards(k), numVul(k), prefixVul(k); 
    int initialCover = 0; 
    for(int i=0; i<N; i++){
        a = shifts[i].first; 
        b = shifts[i].second; 
        delta[idx[a]]++;
        delta[idx[b]]--; 
        // cout << a << " " << b << " " << idx[a] << " " << idx[b] << endl; 
    }
    numGuards[0] = delta[0]; 
    for(int i=1; i<k; i++){
        numGuards[i] = numGuards[i-1] + delta[i];
    }
    for(int i=0; i<k-1; i++){
        numVul[i] = (numGuards[i] == 1) ? indices[i+1] - indices[i] : 0; 
    }
    for(int i=1; i<k; i++){
        prefixVul[i] = prefixVul[i-1] + numVul[i-1]; 
    }
    for(int i=0; i<k-1; i++){
        if(numGuards[i]>0){
            initialCover += (indices[i+1] - indices[i]); 
        }
    }

    int minVul = 1000000000; 
    for(int i=0; i<N; i++){
        a = shifts[i].first; 
        b = shifts[i].second; 
        minVul = min(minVul, prefixVul[idx[b]] - prefixVul[idx[a]]); 
    }

    cout << initialCover - minVul << endl; 


    // cout << initialCover << endl; 
    // for(int i=0; i<k; i++){
    //     cout << delta[i] << " ";
    // }
    // cout << endl; 
    // for(int i=0; i<k; i++){
    //     cout << numGuards[i] << " ";
    // }
    // cout << endl; 
    // for(int i=0; i<k; i++){
    //     cout << numVul[i] << " ";
    // }
    // cout << endl; 
    // for(int i=0; i<k; i++){
    //     cout << prefixVul[i] << " ";
    // }



    
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
 
    solve(); 
 
    return 0;
}