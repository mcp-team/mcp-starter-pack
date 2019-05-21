import java.lang.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class Edgy_Trees{

    private static final Scanner scanner = new Scanner(System.in);
    private static ArrayList<Integer>[] g;
    private static int n, k, u, v, c;
    private static final int MOD = 1000000007;

    static long binpow(long a, long b) {
        a %= MOD;
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    public static void main(String[] args) {
        n = scanner.nextInt();
        k = scanner.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        UF uf = new UF(n);
        for (int i = 0; i < n-1; i++) {
            u = scanner.nextInt(); v = scanner.nextInt(); c = scanner.nextInt();
            u--; v--;
            if (c == 0) uf.union(u,v);
        }
        long ans = binpow(n,k);
        for (int i = 0; i < n; i++) {
            if (uf.isp(i)) ans = (ans + MOD - ((binpow(uf.getSize(i),k) % MOD))) % MOD;
        }
        System.out.println(ans);
    }
}

class UF {
    private int[] parent;
    private int[] sz;

    public UF(int size) {
        parent = new int[size];
        sz = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    public int find(int x) {
        return (parent[x] == x) ? x : (parent[x] = find(parent[x])); 
    }

    public boolean connected(int x, int y) {
        return this.find(x) == this.find(y);
    }

    public void union(int x, int y) {
        if (this.connected(x,y)) return;
        int px = find(x), py = find(y);
        if (sz[px] > sz[py]) {
            parent[py] = px; sz[px] += sz[py];
        }
        else {
            parent[px] = py; sz[py] += sz[px];
        }
    }

    // Specific to this question only
    public int getSize(int x) {
        return sz[x];
    }
    public boolean isp(int x) { return parent[x] == x; }
}
