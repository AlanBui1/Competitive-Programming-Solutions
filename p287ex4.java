import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int n = kb.nextInt();
        kb.nextLine();
        
        for (int i=0; i<n; i++){
            String line = kb.nextLine();
            int ans = 0;
            int leng = line.length();
            for (int k=0; k<leng; k++){
                if (line.charAt(k) == ' '){
                    ans = k+1;
                    break;
                }
            }
            
            System.out.println(ans);
        }
    }
}