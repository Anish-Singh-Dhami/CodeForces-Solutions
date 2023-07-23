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
void multiply(ll F[2][2], ll M[2][2]) {
    ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(ll F[2][2], ll n) {
    if ( n == 0 || n == 1)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

ll fib(ll n) {
    ll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}




// NOTE: Make sure to update x, y (x *= c/gcd(a, b), y *= c/gcd(a,b)) after all opertion.
ll extendEuclid(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll x1, y1;
  ll g = extendEuclid(b, a%b, x1, y1);
  x = y1;
  y = x1 - a / b * y1;
  return g;
}

void sol () {
  ll n, k; cin >> n >> k;
  if(k >= 28) {
  	cout << 0 << nline;
  	return;
  }
  ll a, b;
  b = fib(k-1);
  if(k == 1) a = 0;
  else a = fib(k-2);
  // cerr << a << " " << b << endl;
  ll x, y;
  ll g = extendEuclid(a, b, x, y);
  if(n % g) {
  	cout << 0 << nline;
  	return;
  }
  x *= n / g;
  y *= n / g;
  // cerr << x << " " << y << "\n";
  ll j = floor(1.0 * g * (y - x) / (a + b));
  // cerr << j << endl;
  ll cnt = 0;
  ll _x, _y;
  _x = x + j * (b / g);
  _y = y - j * (a / g);
  // cerr << _x << " " << _y << nline;
  while(_x >= 0 && _y >= 0) {
  	// cout << _x << " " << _y << endl;
  	cnt++;
  	j--;
  	_x = x + j * (b / g);
	_y = y - j * (a / g);
  }
  cout << cnt << nline;
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