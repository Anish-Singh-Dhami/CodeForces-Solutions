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
  int n; cin >> n;
  vll arr(n, 0), diff(n, 0);
  for(int i = 1; i < n; i++)  cin >> arr[i];

  set<ll> missing;
  for(int i = 1; i <= n; i++) missing.insert(i);
  
  diff[1] = arr[1];
  assert((int)missing.size() == n);
  if(missing.count(arr[1])) missing.erase(arr[1]);

  for(int i = 2; i < n; i++) {
    diff[i] = arr[i] - arr[i-1];
    if(missing.count(diff[i])) missing.erase(diff[i]);
  }

  ll nSum = 1ll* n * (n + 1) / 2;
  if(arr.back() > nSum) {
    pno();
    return;
  } 
  else if (arr.back() == nSum) {
    if(missing.size() == 2) {
      ll m1 = *missing.begin();
      ll m2 = *missing.rbegin();
      for(int i = 1; i < n; i++) {
        if(diff[i] == m1+m2) {
          pyes();
          return;
        }
      }
      pno();
    } else {
      pno();
    }
  }
  else {
    if(missing.size() == 1) {
      pyes();
    } else {
      pno();
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
  RepSolution();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}