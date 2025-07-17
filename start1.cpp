#include <bits/stdc++.h>
using namespace std;

// Fast I/O functions (useful for large inputs/outputs)
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

// Shortcut for loops
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RREP(i, n) for (int i = n-1; i >= 0; --i)

// Common constants
#define INF INT_MAX
#define MOD 1000000007
#define PI 3.14159265358979323846

// Typedefs for common types
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// Other utilities (useful for sorting, etc.)
template <typename T>
void printVector(const vector<T>& vec) {
    for (auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    FAST_IO  // Enables fast input and output
   // std::ios::sync_with_stdio(false);
	//std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    cin >> n;  // Input value

    // Short form loop example using REP
    REP(i, n) {
        cout << "Loop " << i+1 << endl;
    }

    // Example of a loop with FOR
    FOR(i, 1, n) {
        cout << i << " ";
    }
    cout << endl;

    // Example of a reverse loop with RREP
    RREP(i, n) {
        cout << i+1 << " ";
    }
    cout << endl;

    return 0;
}
////////
#include <bits/stdc++.h>
#include <unordered_set>
/* 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
*/
using namespace std;
using namespace chrono;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef set<int> si;
typedef set<ll> sl;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef deque<int> dqi;
typedef deque<ll> dql;
typedef stack<int> sti;
typedef stack<ll> stl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define tc(t) while(t--)
#define FORd(i, a, b) for (ll i = (a)-1; i >= b; i--)
#define trav(a,x) for (auto& a : x)
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define popb pop_back
#define pushf push_front
#define popf pop_front
#define f first
#define tvi(v,n) vl v(n); FOR(i,0,n) cin >> v[i];
#define tgi(v,n,m) vvl v(n,vl(m)); FOR(i,0,n) {FOR(j,0,m){cin >> v[i][j];}}
#define tli(n,m) ll n,m; cin >> n >> m;
#define tsi(n) string n; cin >> n;
#define s second
#define lb lower_bound
#define ub upper_bound
#define srt(x) sort(all(x))
#define rsrt(x) sort(x.rbegin(), x.rend())
#define all(x) x.begin(), x.end()
#define ins insert
const char nl = '\n';
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
 
template <typename T>
void _print(T t) { cerr << t; }
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.sec); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
 
