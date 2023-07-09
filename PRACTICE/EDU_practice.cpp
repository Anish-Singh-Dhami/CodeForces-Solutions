/*  
    Talent and begin good at something thing is one part and other (probably more important) part
    is having confidence and conviction that you have the ability to do that thing. 
    And then puting in the time, effort & pracitce and not giving up when things get difficult.
*/
#include <bits/stdc++.h>
using namespace std;
 
#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline '\n'
#define mod 1000000007
#define inf 1e18
#define ff first
#define PI 3.141592653589793238462
#define ss second
#define pii pair<int, int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ppb pop_back
#define rep(i, init, n) for (int i = init; i < (int)n; i++)
#define MOD 998244353

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using u64 = uint64_t;
using u128 = __uint128_t;
 
void pyes() {cout << "YES" << nline;}
void pno() {cout << "NO" << nline;}
void noans() {cout << "-1" << nline;} 
void allUpper(string &s) {
  transform(s.cbegin(), s.cend(), s.begin(), [](auto &c){
    return toupper(c);
  });
} 

class DSU {
  public :
  vector<int> parent;
  vector<int> weight;
  vector<int> rank;
  DSU(int v) {
    parent.resize(v);
    weight.resize(v);
    rank.resize(v);
    for(int i = 0; i < v; i++) {
      parent[i] = i;
      weight[i] = rank[i] = 0;
    }
  }
  pair<int,int> find(int a) {
    if(a == parent[a]) {
      return {a, weight[a]};
    }
    pair<int,int> inter = find(parent[a]);
    parent[a] = inter.first;
    weight[a] = inter.second + weight[a];
    return {parent[a], weight[a]};
  }
  void merge(int a, int b, int c) {
    pair<int,int> x, y;
    x = find(a);
    y = find(b);
    if(x.first == y.first) {
      if(x.second - y.second != c) {
        cout << "inconsistent solution" << endl;
      } else cout << "consistent solution" << endl;
      return;
    }
    if(rank[x.first] == rank[y.first]) rank[x.first]++;
    if(rank[x.first] > rank[y.first]) {
      //        p(a)  <----   p(b)
      parent[y.first] = x.first;
      weight[y.first] = x.second - y.second - c; 
    } else {
      //        p(a)  ---->   p(b)
      parent[x.first] = y.first;
      weight[x.first] = y.second - x.second + c;
    }
  }
};


void sol () {
  int n, q; cin >> n >> q;
  DSU dsu(n+1);
  for(int i = 0; i < q; i++) {
    int a, b, c, t;
    cin >> t;
    if(t == 1) {
      cin >> a >> b >> c; 
      dsu.merge(a, b, c);
    } else {
      cin >> a >> b;
      pair<int,int> x, y;
      x = dsu.find(a);
      y = dsu.find(b);
      if(x.first != y.first) {
        cout << "Not Possible!" << endl;
      } else {
        // a --> b = [a --> p(a)] - [b --> p(b)]
        cout << x.second - y.second << endl;
      }
    }
  }

}
 
void RepSolution() {
  int t; cin >> t;
  while(t--) {
    sol();
  }
}
 
int main(){
  fastIO();
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt", "w", stderr);
  #endif
  RepSolution();
  // sol();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}