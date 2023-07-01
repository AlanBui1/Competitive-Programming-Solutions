import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int a = kb.nextInt();
        int b = kb.nextInt();
        int ans = 0;
        
        for (int i=a; i<=b; i++){
            int n = 0;

            for (int k=1; k<=i; k++){
                if (i%k == 0){
                    n++;
                }
            }

            if (n == 4) ans++;
        }
        System.out.print("The number of RSA numbers between ");
        System.out.print(a);
        System.out.print(" and ");
        System.out.print(b);
        System.out.print(" is ");
        System.out.println(ans);
    }
}