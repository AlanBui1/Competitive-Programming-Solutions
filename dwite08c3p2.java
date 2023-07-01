import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        for (int i=0; i<5; i++){
            String line = kb.nextLine();

            String ans = line.replaceAll("[^a-z, ^A-Z]", " ").replaceAll(",", " ");

            String[] arr = ans.split(" ");

            int ret = 0;
            for (String s : arr){
                if (s.length() > 3){
                    ret++;
                }
            }

            System.out.println(ret);
        }
    }
}