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

bool isGood(ll mid, vi& arr, ll c) {
	u128 temp = 0;
	for(auto &it : arr) {
		u128 x = (u128) it + mid + mid;
		x *= x;
		temp += x;
		if(temp > c) return false;
	}
	if(temp <= c) return true;
	return false;
}

void sol () {
  ll n, c; cin >> n >> c;
  ll l = 0; // true invariant
  ll r = c;
  
  vi arr(n);
  
  for(auto &it : arr) {
  	cin >> it;
  	// r -= 1ll*(it*it);
  }
  r = c;
  while(r - l > 1) {
  	ll mid = l + (r - l) / 2;
  	if(isGood(mid, arr, c)) {
  		l = mid;
  	} else {
  		r = mid;
  	}
  }
  cout << l << nline;
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
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}