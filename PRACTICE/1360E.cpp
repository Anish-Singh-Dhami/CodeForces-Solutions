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
vector<string> mat;
int n;
void dfs(int a, int b) {
	// moving top:
	mat[a][b] = '0';
	if(a - 1 >= 0) {
		if(mat[a-1][b] == '1') dfs(a-1, b);
	}
	// moving left;
	if(b - 1 >= 0) {
		if(mat[a][b-1] == '1') dfs(a, b-1);
	}
}
void sol () {
	cin >> n;
	mat.clear();
	for(int i = 0;i < n; i++) {
		string temp; cin >> temp;
		mat.push_back(temp);
	}
	for(int i = n-1; i >= 0; i--) {
		if(mat[n-1][i] == '1') dfs(n-1, i);
		if(mat[i][n-1] == '1') dfs(i, n-1);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(mat[i][j] == '1') {
				pno();
				return;
			}
		}
	}
	pyes();
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