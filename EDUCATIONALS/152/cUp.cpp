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

/*
  Q. What is common in sorting the substring from [l1, r1] and [l2, r2] of a string?
    ex: 00....0|101010|1......11
               ^      ^
        sorting whole array is same as sorting the given range, thus compressing the range 
    ==> ans = count total distince such ranges.
*/

void sol () {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  set<pair<int,int>> st;
  vi next1(n+1, n), prev0(n+1, -1);
  for(int i = n - 1; i >= 0; i--) {
    next1[i] = s[i] ==  '1' ? i : next1[i+1];
  }
  for(int i = 0; i < n; i++) {
    prev0[i+1] = s[i] == '0' ? i : prev0[i];
  }
  while(m--) {
    int l,r; cin >> l >> r;
    l--;
    l = next1[l];
    r = prev0[r];
    if(l > r) {
      l = r = -1;
    }
    st.emplace(l, r);
  }
  cout << st.size() << nline;
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