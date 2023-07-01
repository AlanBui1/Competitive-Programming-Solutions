import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int n = kb.nextInt();
        
        int[] sieve = new int[4000];
        
        sieve[1] = 1;
        sieve[0] = 1;
        for (int i=4; i<4000; i+=2){
            sieve[i] = 1;
        }
        
        for (int i=6; i<4000; i+=3){
            sieve[i] = 1;
        }
        
        for (int i=4; i<4000; i++){
            if (sieve[i] == 1) continue;
            
            boolean prime = true;
            
            for (int k=2; k*k <= i; k++){
                if (i%k == 0){
                    prime = false;
                    break;
                }
            }
            
            if (prime == true){
                for (int k=i*2; k<4000; k+=i){
                    sieve[k] = 1;
                }
            }
        }
        
        
        int cnt = 0;
        
        for (int i=0; i<4000; i++){
            if (cnt == n){
                System.out.println();
                break;
            }
            if (sieve[i] == 0){
                cnt++;
                System.out.print(i);
                if (cnt%10==0){
                    System.out.println();
                }
                else System.out.print(" ");
            }
            
        }
    }
}