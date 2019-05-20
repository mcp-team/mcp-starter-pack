import java.lang.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {
    
    private static final Scanner scanner = new Scanner(System.in);
    private static ArrayList<Integer>[] g;
    public static void main(String[] args) throws IOException {
        int q = scanner.nextInt();
        while (q-- > 0) {
            int n = scanner.nextInt(); int m = scanner.nextInt();
            int 
            g = new ArrayList[n];
            for (int i = 0; i < n; i++) g[i] = new ArrayList<Integer>();
            for (int i = 0; i < m; i++) {
                int u = scanner.nextInt(); int v = scanner.nextInt();
                u--; v--;
                g[u].add(v); g[v].add(u);
            }
            int[] pathlen = new int[n];
            for (int i = 0; i < n; i++) pathlen[i] = -1;

            Queue<Integer[]> queue = new LinkedList<>();
            int startNode = scanner.nextInt();
            Integer[] start = {startNode-1,0};
            queue.add(start);

            while (queue.size() > 0) {
                Integer[] node = queue.remove();
                if (pathlen[node[0]] != -1) continue;
                pathlen[node[0]] = node[1];
                for (int next : g[node[0]])
                    if (pathlen[next] == -1) {
                        Integer[] temp = new Integer[] {next,node[1]+6};
                        queue.add(temp);
                    }
            }

            for (int i = 0; i < pathlen.length; i++)
                if (i != start[0]) System.out.print(pathlen[i] + " ");
            System.out.println();
        }
    }
}
