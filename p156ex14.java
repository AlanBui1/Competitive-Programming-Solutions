import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        while (true){
            int account = kb.nextInt();
            if (account< 0) break;
            
            System.out.println("Account #: "+account);
            System.out.print("Bill: ");
            
            int m1 = kb.nextInt(), m2 = kb.nextInt();
            
            int dist = ((m2-m1)+10000)%10000;
            
            double ans = 6.59;

            dist -= 10;
            if (0 <= dist && dist < 20){
                ans += .2373*dist;
            }
            
            else if (dist >= 20){
                ans += .2373*20;
            }
            dist -= 20;
            
            if (0 <= dist && dist < 55){
                ans += .2271*dist;
            }
            else if (dist >= 55){
                ans += .2271*55;
            }
            dist -= 55;
            
            if (0 <= dist && dist < 85){
                ans += .2178*dist;
            }
            else if (dist >= 85){
                ans += 85*.2178;
            }
            dist -= 85;
            
            if (0 <= dist){
                ans += .2085*dist;
            }

            System.out.printf("%.2f", ans);
            System.out.println();
        }
    }
}