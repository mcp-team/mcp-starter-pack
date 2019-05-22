#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi A;

bool bin_search(vi &A, int val) {
    int mid = A.size()/2, hi = A.size()-1, lo = 0;
    while (A[mid] != val) {
        if (A[mid] > val) {
            hi = mid-1; mid = (lo+hi)/2;
        }
        else {
            lo = mid+1; mid = (lo+hi)/2;
        }
        if (hi < lo) return false;
    }
    return true;
}

int main () {
    int n, k, temp;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        A.push_back(temp);
    }
    
    sort(A.begin(), A.end());
    long long count = 0;
    for (int x : A) {
        count += bin_search(A, x+k);
        count += bin_search(A, x-k);
    }
    printf("%lld", count/2);
    return 0;
}
