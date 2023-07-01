import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();
        int[] arr = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
        int s = 0;
        for (int i=0; i<10; i++) s += arr[i];
        for (int i=0; i<n; i++){
            int x = kb.nextInt();
            s -= arr[x-1];
        }

        int deal = kb.nextInt();

        if (deal*(10-n) > s){
            System.out.println("deal");
        }
        else{
            System.out.println("no deal");
        }
    }
}