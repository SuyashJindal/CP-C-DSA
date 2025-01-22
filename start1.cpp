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
