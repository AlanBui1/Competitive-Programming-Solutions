import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int a = kb.nextInt(), b=kb.nextInt(), c=kb.nextInt(), d=kb.nextInt();

        System.out.println(0 + " " + a + " " + (a+b) + " " + (a+b+c) + " " + (a+b+c+d));
        System.out.println(a + " " + 0 + " " + (b) + " " + (b+c) + " " + (b+c+d));
        System.out.println((a+b) + " " + b + " " + (0) + " " + (c) + " " + (c+d));
        System.out.println((a+b+c) + " " + (b+c) + " " + (c) + " " + (0) + " " + (d));
        System.out.println((a+b+c+d) + " " + (b+c+d) + " " + (c+d) + " " + (d) + " " + (0));
        
        
    }
}