import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int t = kb.nextInt();
        
        for (int i=0; i<t; i++){
            int x = kb.nextInt();
            
            if (80 <= x && x <= 100){
                System.out.println("A");
            }
            else if (70 <= x && x <= 79){
                System.out.println("B");
            }
            else if (60 <= x && x <= 69){
                System.out.println("C");
            }
            else if (50 <= x && x <= 59){
                System.out.println("D");
            }
            else if (0 <= x && x <= 49){
                System.out.println("F");
            }
            else System.out.println("X");
        }
    }
}