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
ll fact(ll);
ll C(ll, ll);

ll C(ll n, ll r) {
	ll res = fact(n) / fact(r);
	res /= fact(n - r);
	return res;
}

ll fact(ll n) {
	ll res = 1;
	for(int i = 1; i <= n; i++) res *= i;
	return res;
}

void sol () {
	ll n; cin >> n;
	ll ans = 1;
	// n C (n/2) # ways to choose n/2 elements out of n elements
	// will have consider elements twices as at any instance G1, G2 having n/2 elements each, 
	// after few such combinations the element choosen for G1, and remaining n/2 element for G2 will become same of that instance 
	ans = C(n , n/2);
	ans /= 2;

	ll x = fact(n/2 - 1);
	ans = ans * x * x;
	cout << ans << nline;
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