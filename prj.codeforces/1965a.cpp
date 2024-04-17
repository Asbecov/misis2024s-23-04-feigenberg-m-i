
#include<bits/stdc++.h>

const int N = 1e6+7;

int a[100];

void solve() {
    int k,q;
    std::cin >> k >> q;
    for(int i = 0; i < k; i++)
        std::cin >> a[i];
    for(int i = 0; i < q; i++){
        int n;
        std::cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            v[i] = i+1;
        while(1){
            int j = 0;
            vector<int> tmp;
            for(int i = 0; i < v.size() and j < k; i++){
                if(i+1 == a[j]){
                    j++;
                }
                else tmp.push_back(v[i]);
            }
            v = tmp;
            if(j == 0) break;
        }
        std::cout << v.size() << ' ';
    }
    std::cout << '\n';
    return;
}

int main() {
    int count;
    std::cin >> count;
    for(int idx{0}; idx <= count; idx++) {
        solve();
    }
    return 0;
}