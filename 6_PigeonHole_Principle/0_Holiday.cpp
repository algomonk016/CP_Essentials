/*
Holiday Accomodation: https://www.spoj.com/problems/HOLI/

Provided: 
  - non cyclic weighted graph
  - find maximum possible distance travelled

Approach:
  for this, we need to find maximum participation of each edge
  we can calculate it by dividing the graph in two halfs,
  1st half -> 3 nodes
  2nd half -> 5 nodes
  weight of the edge -> 3

  contribution of the edge -> 2*min(1st node, 2nd node)*weight
  twice, coz, x left se right jaaenge and vice versa
*/ 

#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define br "\n"

// returns the size of tree from current node
int dfs(int u, int parent, vector<pair<int, int>> adj[], int &ans, int N){
  int currentTreeSize = 1;

  for(auto &p: adj[u]){
    auto [v, wt] = p;
    // skip parent, to handle loop
    if(v == parent){
      continue;
    }

    int childrenTreeSize = dfs(v, u, adj, ans, N);
    int edgeContribution = 2*min(childrenTreeSize, N-childrenTreeSize)*wt;
    ans += edgeContribution;
    currentTreeSize += childrenTreeSize;
  }

  return currentTreeSize;
}

void solve(int t){
  vector<pair<int, int>> adj[100005];

  int n;
  cin>>n;

  int u, v, w;
  for(int i=1; i<n; i++){
    cin>>u>>v>>w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int ans = 0;

  dfs(1, -1, adj, ans, n);

  cout<<"Case #"<<t<<": "<<ans<<br;
}

signed main() {
  IOS;

  int t;
  cin>>t;

  for(int i=1; i<=t; i++){
    solve(i);
  }

  return 0;
}

