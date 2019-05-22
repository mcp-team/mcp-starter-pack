#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi A;

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    A.assign(n,0);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    int lights = 0;
    int p1 = 0, p2;
    while (p1 < n) {
        bool flag = false;
        for (p2 = min(n-1,p1+r-1); p2 >= p1-r+1; p2--) 
            if (A[p2] == 1) { flag = true; break; }
        // printf("%d\n", p2);
        if (!flag) { printf("-1\n"); return 0; }
        p1 = p2 + r;
        lights++;
    }
    printf("%d\n", lights);
    return 0;
}

