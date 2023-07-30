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

void prefSum(vpii &ans, int n) {
  for(int i = 1; i < n; i++) {
    ans.pb({i, i-1});
  }
}

void suffSum(vpii &ans, int n) {
  for(int i = n-2; i >= 0; i--) {
    ans.pb({i, i+1});
  }
}

void sol () {
  int n;cin >> n;
  vi arr(n);
  for(auto &it: arr) cin >> it;
  
  int mxPos = max_element(all(arr)) - arr.begin();
  int mnPos = min_element(all(arr)) - arr.begin();
  int mx = arr[mxPos];
  int mn = arr[mnPos];

  if(is_sorted(all(arr))) {
    cout << 0 << "\n";
    return;
  }

  int cntPos = 0, cntNeg = 0;
  for(int i = 0;i < n; i++) {
    if(arr[i] > 0) cntPos++;
    if(arr[i] < 0) cntNeg++;
  }

  vpii ans;

  if(cntNeg == 0) {
    prefSum(ans, n);
  } else if(cntPos == 0) {
    suffSum(ans, n);
  } else {
    int x1 = 0, y1 = 0;
    
    while(mx < abs(mn)) {
      mx+=mx;
      x1++;
    }
    
    mx = arr[mxPos];
    mn = arr[mnPos];
    
    while(abs(mn) < mx) {
      mn += mn;
      y1++;
    }

    mx = arr[mxPos];
    mn = arr[mnPos];

    if(x1 + cntNeg < y1 + cntPos) {
      // make all pos
      while(mx < abs(mn)) {
        mx += mx;
        ans.pb({mxPos, mxPos});
      }

      for(int i = 0; i < n; i++) {
        if(arr[i] < 0) ans.pb({i, mxPos});
      }

      prefSum(ans, n);
    } else {
      // make all neg
      while(abs(mn) < mx) {
        mn += mn;
        ans.pb({mnPos, mnPos});
      }

      for(int i = 0;i < n; i++) {
        if(arr[i] > 0) ans.pb({i, mnPos});
      }

      suffSum(ans, n);
    }
  }

  cout << ans.size() << "\n";
  for(auto &it : ans) {
    cout << it.ff + 1 << " " << it.ss + 1<< "\n";
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