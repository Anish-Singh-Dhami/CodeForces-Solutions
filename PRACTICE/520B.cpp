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

void sol () {
	int n, m; cin >> n >> m;
	int level = 0, currLevel = 1, nextLevel = 0;
	queue<int> q;
	q.push(n);
	set<int> st;
	st.insert(n);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		currLevel--;
		if(x == m) {
			cout << level << endl;
			return;
		}
		if(!st.count(2*x) && x <= 2*m) {
			q.push(2*x);
			st.insert(2*x);
			nextLevel++;
		}
		if(!st.count(x-1) && x > 0) {
			q.push(x-1);
			st.insert(x-1);
			nextLevel++;
		}
		if(currLevel == 0) {
			currLevel = nextLevel;
			nextLevel = 0;
			level++;
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