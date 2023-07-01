import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner kb = new Scanner(System.in);

        int t = kb.nextInt();

        double highest = -1000000000;
        double[] arr = new double[105];

        for (int i=0; i<t; i++){
            double x = kb.nextDouble();

            arr[i] = x;
            if (x > highest) highest = x;
        }

        for (int i=0; i<t; i++){
            if (arr[i] != highest){
                System.out.printf("%.2f", arr[i]);
                System.out.println();
            }
        }
        System.out.printf("%.2f", highest);
        System.out.println();
    }
}