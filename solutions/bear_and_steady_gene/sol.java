import java.util.*;
import java.math.*;
import java.lang.*;
import java.io.*;

public class Solution {
    private static final Scanner scanner = new Scanner(System.in);
    static HashMap<Character,Integer> map = new HashMap<Character,Integer>();
    static int[] B = new int[4];
    static int lim;
    static String s;

    public static boolean valid() {
        return B[0] <= lim && B[1] <= lim && B[2] <= lim && B[3] <= lim;
    }

    public static final void main(String[] args) throws IOException {
        int n, ans = 100000000;
        n = scanner.nextInt();
        s = scanner.next();
        int p1 = 0, p2 = 0; lim = n/4;
        map.put('A',0); map.put('C',1); map.put('G',2); map.put('T',3);
        for (int i = n-1; i >= 0; i--) {
            B[map.get(s.charAt(i))]++;
            if (B[map.get(s.charAt(i))] > lim) { p2 = i; break; }
        }
        for (p1 = -1; p1 < n-1 && p2 < n && p1 < p2; p1++) {
            while (!valid() && p2 < n) {
                B[map.get(s.charAt(p2))]--; p2++;
            }
            if (p2 > n || !valid()) break;
            int subSLen = p2-p1-1;
            ans = Math.min(ans,Math.max(0,subSLen));
            B[map.get(s.charAt(p1+1))]++;
        }
        System.out.println(ans);
    }
}
