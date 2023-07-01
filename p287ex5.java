import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int n= kb.nextInt();
        
        for (int i=0; i<n; i++){
            int x = kb.nextInt();
            
            x = Math.abs(x);
            int digits = 0;
            
            if (x == 0){
                System.out.println(1);
                continue;
            }
            while (x > 0){
                x/=10;
                digits++;
            }
            System.out.println(digits);
        }
    }
}