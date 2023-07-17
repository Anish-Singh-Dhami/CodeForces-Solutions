
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
int n,k;
vector<int> arr;
map<int,vector<int>> mp;
void sol () {
	cin >> n >> k;
	arr.clear();
	arr.resize(n+1);
	mp.clear();
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		if(!mp.count(arr[i])) {
			mp[arr[i]].push_back(0);
		}
		mp[arr[i]].push_back(i);
	}

	int mn = n;
	for(auto &it : mp) {
		mp[it.first].push_back(n+1);
		vector<int> diff;
		for(int i = 1; i < (int)mp[it.first].size(); i++) {
			diff.push_back(mp[it.first][i] - mp[it.first][i-1] - 1);
		}
		sort(diff.begin(), diff.end(), greater<int>());
		int mx = diff[0] / 2;
		if(diff.size() > 1) {
			mx = max(mx, diff[1]);
		} 
		mn = min(mn, mx);
	}
	cout << mn << nline;			
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
  // sol();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}