import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int n = kb.nextInt();
        kb.nextLine();
        
        int[] arr = {0,0,0,0,0,0,0};
        for (int i=0; i<n; i++){
            String vote = kb.nextLine();
            
            if (65 <= vote.charAt(0) && vote.charAt(0) <= 71){
                arr[vote.charAt(0) -65]++;
            }
            else arr[6]++;
        }
        
        for (int i=0; i<7; i++)System.out.println(arr[i]);
    }
}