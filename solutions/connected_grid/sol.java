import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);
    private static int curArea, maxArea = 0;
    private static int n, m;
    private static int[][] g;

    static int dr[] = {1,1,0,-1,-1,-1, 0, 1}; 
    static int dc[] = {0,1,1, 1, 0,-1,-1,-1}; 

    public static void dfs(int r, int c) {
        if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] != 1) return;
        curArea++; g[r][c] = 2;
        for (int d = 0; d < 8; d++)
            dfs(r + dr[d], c + dc[d]);
    }

    public static void main(String[] args) throws IOException {
        n = scanner.nextInt(); m = scanner.nextInt();
        g = new int[n][m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                g[i][j] = scanner.nextInt();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == 1) {
                    curArea = 0;
                    dfs(i,j);
                    maxArea = Math.max(maxArea,curArea);
                }
        
        System.out.println(maxArea);
    }
}

