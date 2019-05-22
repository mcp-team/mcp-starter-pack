#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if ((n == 3 || n == 2) && a == 1 && b == 1) {
        printf("NO\n");
        return 0;
    }
    if (min(a,b) > 1) { printf("NO\n"); return 0; }
    vector<vi> A(n,vi(n,0));
    // construct the higher of the two
    int hi = max(a,b);
    for (int i = 0; i < n-hi; i++)
        for (int j = 0; j < n; j++)
            if (j == i+1) A[i][j] = A[j][i] = 1;
    // complement based on what the value of a is
    if (a == 1) {
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            A[i][j] = A[i][j] == 0 ? 1 : 0;
        for (int i = 0; i < n; i++) A[i][i] = 0;
    }
    // print the matrix
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            printf("%d", A[i][j]);
        printf("\n");
    }
    return 0;
}

