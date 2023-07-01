import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int a = kb.nextInt(), b = kb.nextInt();
        
        if (a%b == 0){
            System.out.println("yes");
        }
        else System.out.println("no");
    }
}