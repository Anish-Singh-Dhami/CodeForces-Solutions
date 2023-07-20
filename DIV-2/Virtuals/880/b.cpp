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
  ll n,k,g; cin >> n >> k >> g;
  /*
	if(x % g >= g + 1 / 2) ==> x will become next multiple of g (i.e. round up) => will Spend/Loss coins.
	else : => x will become previous multiple of g (i.e. round down) => will Save coins.
  
	if( x == (g - 1) / 2) ==> will always become the previous multiple of g. 
	cause,  (handle both odd and even cases!)
	          even			odd
		let : a = 2n  		b = 2n - 1
		a/2 = n 			b = n - (1/2) 
		n >= ceil(2n/2)     n - (1/2) < ceil((2n - 1) / 2)
	
		(a - 1) / 2 => (2n - 1) / 2 => n - 1/2 ==>  (a - 1) / 2 < ceil(a / 2)
		(b - 1) / 2 => (2n - 2) / 2 => n - 1 	=> 	(b - 1) / 2 < ceil(b / 2)
	thus, 
		(g - 1) / 2 < ceil(g / 2) ==> will save money / coins. 
		Save = (n - 1) * (g - 1) / 2;
 	Remaining coins for last person :
 		last = k * g - save
 		r = last % g
 		if(r >= ceil(g / 2)) => save -= (g - r)
 		else => save += r

 	Q: what if the save value exceeds the total coins (i.e. k * g)?
 		=> will consider whole k*g coins , cause will have saved all of them 
 		by give value <= (g-1) / 2 to atmost n - 1 person, and nothing to remaining.
  */
  ll save = min((n - 1) * ((g-1) / 2), k * g);
  ll last = k * g - save;
  ll r = last % g;
  if(r >= (g + 1) / 2) save -= (g-r);
  else save += r;
  cout << save << nline;
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