import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int t = kb.nextInt();

        double[] deductions = {1.00, 0.90, 0.80, 0.71, 0.65};

        for (int i=0; i<t; i++){
            double hourly = kb.nextDouble();
            int hours = kb.nextInt();
            kb.nextLine();
            String tax = kb.nextLine(), donate = kb.nextLine();
            kb.nextLine();

            double ans = 0;

            if (hours >= 40){
                ans += hourly*40;
                hours -= 40;
            }
            else{
                ans += hours*hourly;
                hours =0;
            }
            
            ans += 2*hours*hourly;
            ans *= deductions[tax.charAt(0) - 65];

            if (donate.equals("y")){
                ans -= 10;
            }
            System.out.printf("%.2f", ans);
            System.out.println();
        }
    }
}