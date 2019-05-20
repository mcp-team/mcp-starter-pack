import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int alphas = 26;
        int[] array = new int[alphas];
        for (int i = 0; i < alphas; i++)
            array[i] = scanner.nextInt();
        String s = scanner.next();
        int maxH = 0;
        for (char c : s.toCharArray()) 
            maxH = Math.max(maxH, array[(int)c - 'a']);
        
        System.out.println(maxH * s.length());
    }
}

