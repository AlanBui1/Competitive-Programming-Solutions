import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();

        for (int i=0; i<63; i++){
            if ((1 << i) >= n){
                System.out.println(i);
                break;
            }
        }
    }
}