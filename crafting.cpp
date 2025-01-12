#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long total_excess = 0, total_deficit = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                total_excess += a[i] - b[i];
            } else {
                total_deficit += b[i] - a[i];
            }
        }

        if (total_excess >= total_deficit) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
