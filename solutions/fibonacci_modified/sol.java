import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger;

public class Solution {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int n;
        BigInteger a, b, c;
        a = scanner.nextBigInteger();
        b = scanner.nextBigInteger();
        n = scanner.nextInt(); n-=2;
        c = BigInteger.ZERO;

        while (n-- > 0) {
            c = a.add(b.multiply(b));
            a = b;
            b = c;
        }

        System.out.println(c);
    }
}
