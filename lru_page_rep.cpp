#include <bits/stdc++.h>
using namespace std;

void solve() {
    //  lru
    int n;
    cin >> n;
    int capacity;
    cin >> capacity;

    vector<int> pages(n);
    for (int i = 0; i < n; ++i) cin >> pages[i];
    vector<int> t;
    int pageFault = 0;
    for (int i = 0; i < n; ++i) {
        auto it = find(begin(t), end(t), pages[i]);
        if (it == t.end()) {
            if (t.size() == capacity) {
                t.erase(t.begin());
            }
            pageFault++;
            t.push_back(pages[i]);

        } else {
            t.erase(it);
            t.push_back(pages[i]);
        }
    }

    cout << "No of page faults are: " << pageFault << endl;
}

int32_t main() {

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}

// 15
// 3
// 7 0 1 2 0 3 0 4 2 3 0 3 1 2 0
// Page Faults: 12