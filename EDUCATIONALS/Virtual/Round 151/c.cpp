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

string s;
int m;
vector<int> arr;
vector<int> l, r;
bool isValid(ll temp) {
	for(int i = m - 1; i >= 0; i--) {
		int x = temp % 10;
		if(x >= l[i] && x <= r[i]){
			continue;
		} else {
			return false;
		}
		temp /= 10;
	}
	return true;
}

void sol () {
	cin >> s;
	cin >> m;
	arr.clear();
	l.clear();
	r.clear();
	for(int i = 0;i < 2; i++) {
		string temp; cin >> temp;
		for(auto &it : temp) {
			if(i == 0) l.push_back(it-'0');
			else r.push_back(it - '0');
		}
	}
	ll temp = 0;
	for(auto &it : s) {
		arr.push_back(it - '0');
	}
	for(int i = 0; i < m; i++) {
		temp = temp * 10 + arr[i];
	}
	set<ll> st;
	if(isValid(temp)) {
		st.insert(temp);
		cerr << temp << endl;
	}
	int n = arr.size();
	for(int i = m; i < n; i++) {
		temp = temp - pow(10, m - 1) * arr[i - m];
		temp *= 10;
		temp += arr[i];
		if(isValid(temp)){
			st.insert(temp);
			cerr << temp << nline;
		}
	}
	int mx = 0;
	for(int i = 0; i < m; i++) {
		mx += (r[i] - l[i] + 1);
	}
	if(mx > st.size()) {
		pyes();
	} else {
		pno();
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
  // sol();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}