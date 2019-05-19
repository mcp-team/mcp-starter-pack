// Written by: le-michael

#include<bits/stdc++.h>
using namespace std;

const int HEIGHT = 100001;
const int WIDTH = 20;
int tree[HEIGHT][WIDTH];
unordered_map<int, int> lookup;

int search(int curr, int kth) {
    if (curr == 0 || kth == 0) return curr;
    if (tree[curr][0] == 0) return 0;
    int lsb = kth & -kth;
    int ind = lookup[lsb];
    return search(tree[curr][ind], kth^lsb);
}

void insert(int x, int y, int ind) {
    if (ind == WIDTH) return;
    tree[x][ind] = y;
    insert(x, tree[y][ind], ind+1);
}

int main() {
    int T, P, Q, x, y, k, task;
    scanf("%d", &T);
    for (int i=0; i<WIDTH; i++) lookup[1<<i] = i;
    while (T--) {
        scanf("%d", &P);
        for (int i=0; i<HEIGHT; i++) {tree[i][0] = 0;}
        while(P--) {
            scanf("%d%d", &x, &y);
            insert(x, y, 0);
        }
        scanf("%d", &Q);
        while(Q--) {
            scanf("%d", &task);
            switch(task) {
                case 0:
                    scanf("%d%d", &y, &x);
                    insert(x, y, 0);
                    break;
                case 1:
                    scanf("%d", &x);
                    tree[x][0] = 0;
                    break;
                case 2:
                    scanf("%d%d", &x, &k);
                    printf("%d\n", search(x, k));
                    break;
            }
        }
    }     
    return 0;
}
