import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();

        for (int i=1; i*i <= n; i++){
            if (n%i == 0){
                System.out.println(i);
                
                if (i != n/i) System.out.println(n/i);
            }
        }
    }
}