import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt(), p1 = 100, p2 = 100;

        for (int i=0; i<n; i++){
            int a = kb.nextInt();
            int b = kb.nextInt();

            if (a > b){
                p2 -= a;
            }
            if (b > a){
                p1-=b;
            }
        }

        System.out.println(p1);
        System.out.println(p2);
    }
}