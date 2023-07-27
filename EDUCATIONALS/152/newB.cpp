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

/*******************************************DEBUGGER****************************************************/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; print(x); cerr << nline;
#else
#define debug(x)
#endif
 
void print(ll t) {cerr << t;}
void print(int t) {cerr << t;}
void print(string t) {cerr << t;}
void print(char t) {cerr << t;}
void print(ld t) {cerr << t;}
void print(double t) {cerr << t;}
void print(ull t) {cerr << t;}
 
template <typename T, typename V> void print(pair <T, V> p);
template <typename T> void print(vector <T> v);
template <typename T> void print(set <T> v);
template <typename T> void print(unordered_set <T> v);
template <typename T, typename V> void print(map <T, V> v);
template <typename T, typename V> void print(unordered_map <T, V> v);
template <typename T> void print(multiset <T> v);
template <typename T, typename V> void print(pair <T, V> p) {cerr << "{ "; print(p.ff); cerr << ","; print(p.ss); cerr << " }";}
template <typename T> void print(vector <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <typename T> void print(set <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <typename T> void print(unordered_set <T> v) {cerr << "[ "; for (auto i : v) {print(i); cerr << " ";} cerr << "]";}
template <typename T> void print(multiset <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V> void print(map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr << nline << '\t'; print(i.ff); cerr << " : ";print(i.ss);} cerr << nline << "]";}
template <typename T, typename V> void print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr << nline << '\t'; print(i.ff); cerr << " : ";print(i.ss);} cerr << nline << "]";}
/**********************************************************************************************************/


void sol () {
  int n, k; cin >> n >> k;
  vpii arr(n); 
  for(int i = 0; i < n; i++) {
  	int x; cin >> x;
  	x -= (x + k - 1) / k * k;
  	arr[i] = {x, i+1};
  }
  sort(all(arr), [&](pii a, pii b) {
  	if(a.ff == b.ff) {
  		return a.ss < b.ss;
  	}
  	return a.ff > b.ff;
  });
  // debug(arr)
  for(int i = 0; i < n; i++) {
  	cout << arr[i].ss << " ";
  }
  cout << nline;
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