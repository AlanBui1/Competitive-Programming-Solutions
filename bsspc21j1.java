import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        int s = kb.nextInt();
        int x = kb.nextInt();
        
        int v = ((s+2)*3)+16;
        
        if (v <= x){
            System.out.println("Yes it fits!");
        }
        else System.out.println("No, it's too small :(");
    }
}