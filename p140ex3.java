import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb= new Scanner(System.in);
        
        String line = kb.nextLine();
        
        int leng= line.length();
        
        for (int i=leng-1; i>=0; i--){
            System.out.println(line.charAt(i));
        }
        
    }
}