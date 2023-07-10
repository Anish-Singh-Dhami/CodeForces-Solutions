/*  
    Talent and begin good at something thing is one part and other (probably more important) part
    is having confidence and conviction that you have the ability to do that thing. 
    And then puting in the time, effort & pracitce and not giving up when things get difficult.
*/

// source : https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

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
	vector<int> parent, rank;
	DSU(int v) {
		parent.resize(v);
		iota(parent.begin(), parent.end(), 0);
		rank.resize(v, 0);
	}
	int find(int a) {
		return parent[a] = (a == parent[a] ? a : find(parent[a]));
	}
	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;
		if(rank[a] == rank[b]) rank[a]++;
		if(rank[a] < rank[b]) swap(a, b);
		parent[b] = a;
	}
};

/*
		INPUT : 					OUTPUT :
		
		3 3 7 						YES
		1 2 						YES
		2 3 						NO
		3 1 						No
		ask 3 3
		cut 1 2
		ask 1 2
		cut 1 3
		ask 2 1
		cut 2 3
		ask 3 1
		
*/


void sol () {
	int n,m,k; cin >> n >> m >> k;
	int u, v;
	string s;

	while(m--) cin >> u >> v;
	DSU dsu(n+1);
	vector<pair<string,pair<int,int>>> query;
	for(int i = 0; i < k; i++) {
		cin >> s >> u >> v;
		query.push_back({s, {u, v}});
	}
	reverse(all(query));
	vector<string> ans;
	for(auto &it : query) {
		int u,v;
		u = it.ss.ff, v = it.ss.ss;
		if(it.first == "cut") {
			dsu.merge(u , v);
		} else {
			if(dsu.find(u) == dsu.find(v)) {
				ans.pb("YES");
			} else {
				ans.pb("NO");
			}
		}
	}
	reverse(all(ans));
	for(auto&it : ans) {
		cout << it << nline;
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
  // RepSolution();
  sol();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}