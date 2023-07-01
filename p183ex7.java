import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int n = kb.nextInt();
        
        int[] sieve = new int[505];
        
        sieve[1] = 1;
        for (int i=4; i<505; i+=2){
            sieve[i] = 1;
        }
        
        for (int i=6; i<505; i+=3){
            sieve[i] = 1;
        }
        
        for (int i=4; i<=n; i++){
            if (sieve[i] == 1) continue;
            
            boolean prime = true;
            
            for (int k=2; k*k <= i; k++){
                if (i%k == 0){
                    prime = false;
                    break;
                }
            }
            
            if (prime == true){
                for (int k=i*2; k<505; k+=i){
                    sieve[k] = 1;
                }
            }
        }
        
        
        for (int i=1; i<=n; i++){
            System.out.println(sieve[i]^1);
        }
    }
}