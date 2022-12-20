#include <bits/stdc++.h>
using namespace std;

// first come first serve
void solve() {
    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    int a;
    int pageFault = 0;
    vector<int> t, pages(n);
    for (auto &it : pages) cin >> it;
    for (int i = 0; i < n; ++i) {
        auto it = find(t.begin(), t.end(), pages[i]);
        if (it == t.end()) {
            pageFault++;
            if (t.size() == capacity) {
                t.erase(t.begin());
            }
            t.push_back(pages[i]);
        }
    }
    cout << "Page Faults: " << pageFault << endl;
}

int32_t main() {
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}

// 15
// 3
// 7 0 1 2 0 3 0 4 2 3 0 3 1 2 0
// Page Faults: 12