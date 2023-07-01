import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        int x = 0, y = 0;
        while (n != 0){
            int best = 10000000;
            for (int i=1; i<=n; i++){
                if (n%i == 0){
                    int test = 2* (i + (n/i));

                    if (test < best){
                        best = test;
                        x = i;
                        y = n/i;
                    }
                }
            }

            System.out.print("Minimum perimeter is "+best+" with dimensions ");
            System.out.print(x);
            System.out.print(" x ");
            System.out.println(y);
            n =kb.nextInt();
        }
    }
}