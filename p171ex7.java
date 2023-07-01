import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int[] ranges = {0,0,0,0,0,0};
        int[] a = {0,10000,20000,30000,40000,50000};
        int[] b = {9999,19999,29999,39999,49999,1000000};
        
        while (true){
            int n = kb.nextInt();
            
            if (n == -1) break;
            
            for (int i=0; i<6; i++){
                if (a[i] <= n && n <= b[i]){
                    ranges[i]++;
                    break;
                }
            }
            
        }
        for (int i=0; i<6; i++) System.out.println(ranges[i]);
    }
}