// Notice the use of longs in this solution. It's because the final cost is too large
// for 32-bit integers in some inputs!

import java.lang.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {
    
    private static final Scanner scanner = new Scanner(System.in);
    private static ArrayList<Integer>[] g;
    private static boolean[] visited;
    private static long roads, libs;

    private static void dfs(Integer node) {
        visited[node] = true;
        for (Integer next : g[node])
            if (!visited[next]) {
                roads++;
                dfs(next);
            }
    }

    public static void main(String[] args) throws IOException {
        int q = scanner.nextInt();
        while (q-- > 0) {
            int n = scanner.nextInt(); int m = scanner.nextInt();
            long clib = scanner.nextLong(); long croad = scanner.nextLong();
            roads = 0; libs = 0;
            visited = new boolean[n];
            g = new ArrayList[n];
            for (int i = 0; i < n; i++) g[i] = new ArrayList<Integer>();

            for (int i = 0; i < m; i++) {
                Integer u = scanner.nextInt(); Integer v = scanner.nextInt();
                u--; v--;
                g[u].add(v); g[v].add(u);
            }

            if (clib <= croad) {
                System.out.println(n * clib);
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;
                dfs(i);
                libs++;
            }

            System.out.println(croad*roads + clib*libs);
        }
    }
}
