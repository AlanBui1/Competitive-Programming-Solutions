import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        double a = kb.nextDouble(), b = kb.nextDouble();
        String ans = " ";
        if (a == 0 && b == 0){
            ans = "indeterminate";
            System.out.println(ans);
        }
        
        else if (a == 0){
            ans = "undefined";
            System.out.println(ans);
        }
        
        else{
            System.out.printf("%.2f", -b/a);
            System.out.println();
        }
    }
}