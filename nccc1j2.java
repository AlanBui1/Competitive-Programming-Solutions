import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        String line = kb.nextLine();
        int n = line.length();
        String ans = "Odd";
        for (int i=0; i<n-1; i++){
            if (line.charAt(i) == line.charAt(i+1)){
                ans = "Even";
                break;
            }
        }
        
        System.out.println(ans);
    }
}