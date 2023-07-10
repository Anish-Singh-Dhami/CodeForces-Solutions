/*  
    Talent and begin good at something thing is one part and other (probably more important) part
    is having confidence and conviction that you have the ability to do that thing. 
    And then puting in the time, effort & pracitce and not giving up when things get difficult.
*/

// source :  https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C


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
public:
	vector<int> parent, rank, exp;
	DSU(int v) {
		parent.resize(v);
		rank.resize(v);
		exp.resize(v);
		for(int i = 0; i < v; i++) {
			parent[i] = i;
			rank[i] = exp[i] = 0;
		}
	}
	pair<int,int> find(int x) {
		if(x == parent[x]) return {x, exp[x]};

		auto p = find(parent[x]);
		
		int leader = p.first;
		parent[x] = leader;

		int ex = exp[x];
		ex = p.second - exp[leader] + exp[x];
		exp[x] = ex;

		return {leader , exp[x] + exp[leader]};
	}

	void merge(int a, int b) {
		a = find(a).first;
		b = find(b).first;
		if(a == b) return;
		if(rank[a] == rank[b]) rank[a]++;
		if(rank[a] < rank[b]) swap(a, b);
		parent[b] = a;
		exp[b] = exp[b] - exp[a]; 

	}
	
	void add(int a, int c) {
		a = find(a).first;
		exp[a] += c;
	}
};

/*
		INPUT :					OUTPUT : 
		3 6 				
	add 1 100
	join 1 3
	add 1 50
	get 1 						150
	get 2 						0
	get 3 						50

*/


void sol () {
	int n, m;
	cin >> n >> m;
	DSU dsu(n+1);
	while(m--) {
		string s; cin >> s;
		int a, b;
		if(s == "add") {
			cin >> a >> b;
			dsu.add(a, b);
		} else if(s == "join") {
			cin >> a >> b;
			dsu.merge(a, b);
		} else {
			cin >> a;
			cout << dsu.find(a).second << endl;
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
  // RepSolution();
  sol();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}