#define _GLIBCXX_FILESYSTEM
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    int now = 1;
    while(now*2 <= n) now *= 2;
    cout << now << '\n';
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    for(int kase = 1; kase <= tc; kase++) {
        //cout << "Case " << kase << ": ";
        solve();
    }
    return 0;
}