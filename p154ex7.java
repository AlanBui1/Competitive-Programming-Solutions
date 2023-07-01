import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);
        int m = kb.nextInt(), n = kb.nextInt();
        for (int i=m; i<=n; i++){
            if (Math.pow(i%10, 3) + Math.pow(((i%100)-(i%10))/10, 3) + Math.pow((i - (i%100))/100, 3) == i){
                System.out.println(i);
            }
        }
    }
}