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

int moves(int a, int b) {
  int cnt = 0;
  while(a != 0) {
    if(b == 0) return cnt + 1;
    // tie(a, b) = make_tuple(b, abs(a%(2*b) - b));
    
    a %= 2*b;
    a = abs(a-b); // i.e. |a % 2b - b|
    swap(a, b); // ==> a = b, b = |a % 2b - b|
    cnt++;
  }
  return cnt;
}

void sol () {
  int n; cin >> n; 
  vi arr(n), brr(n);

  for(auto &it : arr) cin >> it;
  for(auto &ti : brr) cin >> ti;

  int prev = -1;
  for(int i = 0; i < n; i++) {
    if(arr[i] == 0 && brr[i] == 0) continue; 
    int a, b;
    a = arr[i], b = brr[i];
    int cnt = moves(a, b);
    cnt %= 3;
    
    if(prev == -1) prev = cnt;
    if(prev != cnt) {
      pno();
      return;
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
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}