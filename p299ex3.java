import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int n = kb.nextInt();
        kb.nextLine();
        
        for (int i=0; i<n; i++){
            String line = kb.nextLine();
            int leng = line.length();
            for (int k=0; k<leng; k++){
                if (65 <= line.charAt(k) && line.charAt(k) <= 91){
                    char ret = (char)(line.charAt(k)+32);
                    System.out.print(ret);
                }
                else System.out.print(line.charAt(k));
            }
            System.out.println();
        }
    }
}