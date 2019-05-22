import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);
    private static HashSet<Integer>[] g; 
    private static int dist[];
    private static int n, m, u, v, s;
    public static void main(String[] args) throws IOException {
        int tc = scanner.nextInt();
        while (tc-- > 0) {
            n = scanner.nextInt(); m = scanner.nextInt();
            g = new HashSet[n];
            for (int i = 0; i < n; i++) g[i] = new HashSet<Integer>();
            dist = new int[n];
            for (int i = 0; i < m; i++) {
                u = scanner.nextInt(); v = scanner.nextInt();
                u--; v--;
                g[u].add(v); g[v].add(u);
            }
            s = scanner.nextInt(); s--;

            Queue<Integer[]> q = new LinkedList<Integer[]>();
            HashSet<Integer> unvisited = new HashSet<Integer>();
            for (int i = 0; i < n; i++) if (i != s) unvisited.add(i);

            Integer[] start = {s,1};
            q.add(start);
            while (unvisited.size() > 0) {
                Integer[] node = q.remove();
                Integer[] arrUnvisited = new Integer[unvisited.size()];
                unvisited.toArray(arrUnvisited);
                for (Integer i : arrUnvisited) {
                    if (!g[node[0]].contains(i)) {
                        unvisited.remove(i);
                        dist[i] = node[1];
                        Integer[] nextNode = {i, node[1]+1};
                        q.add(nextNode);
                    }
                }
            }

            for (int i : dist)
                if (i > 0) System.out.print(i + " ");
            System.out.println();
        }
    }
}

