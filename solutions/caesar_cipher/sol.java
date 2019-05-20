import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;

public class Solution {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int n = scanner.nextInt();
        String str = scanner.next();
        int k = scanner.nextInt();

        for (char c : str.toCharArray()) {
            if (!Character.isLetter(c)) System.out.print(c);
            else {
                int offset = (int)c < 97 ? 65 : 97;
                int rot = ((int)c - offset + k) % 26 + offset;
                System.out.print((char)rot);
            }
        }
    }

}
