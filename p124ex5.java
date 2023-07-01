import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int n = kb.nextInt();
        
        for (int i=0; i<n; i++){
            double x = kb.nextDouble(), p = kb.nextDouble();
            System.out.printf("%.2f", Math.pow(x, p));
            System.out.println();
        }
    }
}