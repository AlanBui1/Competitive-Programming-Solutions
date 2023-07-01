import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int[] months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int t = kb.nextInt();
        
        for (int o = 0; o < t; o++){
            int y = kb.nextInt(), m = kb.nextInt(), d = kb.nextInt();
            boolean leap = false;
            if (y % 4 == 0 && y%100 != 0){
                leap = true;
            }
            
            else if (y%4 == 0 && y%100 == 0 && y%400 == 0){
                leap=true;
            }
            
            if (leap){
                months[1] = 29;
            }
            else months[1] = 28;
            
            for (int i=0; i<m-1; i++) d += months[i];
            System.out.println(d);
        }
    }
}