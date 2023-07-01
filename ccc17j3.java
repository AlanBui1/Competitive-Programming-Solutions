import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int a = kb.nextInt();
        int b = kb.nextInt();
        int c = kb.nextInt();
        int d = kb.nextInt();
        int t = kb.nextInt();

        int dist = 0;
        if (a > c){
            dist += a-c;
        }
        else{
            dist += c-a;
        }

        if (b > d){
            dist += b-d;
        }
        else{
            dist += d-b;
        }

        if (dist > t || (t-dist)%2 == 1){
            System.out.println("N");
        }

        else{
            if ((t-dist)%2 == 0){
                System.out.println("Y");
            }
        }
    }
}