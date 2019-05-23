#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, temp, t = 0, p, maxt = 0;
    cin >> n >> k;
    vector<int> cnt(110);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cnt[temp]++;
    }
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i]) t++;
        maxt = max(maxt, cnt[i]);
    }
    p = (int)ceil(maxt/(k + .0));

    cout << p*t*k - n << endl;
    return 0;
}

