import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        double n = kb.nextDouble(), m = kb.nextDouble(), y = kb.nextDouble();

        String p = String.format("0 %.2f", n);
        System.out.println(p);
        for (int i=1; i<=y; i++){
            System.out.print(i+" ");
            n *= 1+(m/100);
            p = String.format("%.2f", n);
            System.out.println(p);
        }


    }
}