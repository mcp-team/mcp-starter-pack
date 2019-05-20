import java.lang.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {
    
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            char[] cArr = s.toCharArray(); 
            Arrays.sort(cArr);
            String flag = "Yes";
            for (int j = 0; j < cArr.length-1; j++) {
                if ( !((int)cArr[j] == (int)cArr[j+1]-1) )
                    flag = "No";
            }
            System.out.println(flag);

        }
    }
}
