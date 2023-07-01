import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        int x= kb.nextInt();

        for (int i=1; i<=x; i++){
            System.out.println(x + " X " + i + " = " + (x*i));
        }
    }
}