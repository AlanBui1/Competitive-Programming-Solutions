import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int n = kb.nextInt();

        for (int i=0; i<n; i++){
            int w = kb.nextInt();

            if (0 <= w && w <= 30){
                System.out.println(38);
            }

            else if (30 < w && w <= 50){
                System.out.println(55);
            }

            else if (50 < w && w <= 100){
                System.out.println(73);
            }

            else{
                int ans = (73 + (24 * ((w-100)/50)));
                if ((w-100)%50 > 0){
                    ans += 24;
                }
                System.out.println(ans);
            }
        }
    }
}