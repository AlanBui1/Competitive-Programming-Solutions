import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        String a = "A", b = "B", c = "C", d = "D", e= "E";

        while (true){
            int n = kb.nextInt();
            int x = kb.nextInt();

            if (n == 4) break;

            if (n == 1){
                for (int i=0; i<x; i++){
                    String garbage = a;
                    a = b;
                    b = c;
                    c = d;
                    d = e;
                    e = garbage;
                }
            }

            else if (n == 2){
                for (int i=0; i<x; i++){
                    String garbage = e;
                    e = d;
                    d = c;
                    c = b;
                    b = a;
                    a = garbage;
                }
            }

            else if (n == 3){
                for (int i=0; i<x; i++){
                    String garbage = a;
                    a = b;
                    b = garbage;
                }
                
            }
        }

        System.out.println(a + " " + b + " " + c + " " + d + " " + e);
    }
    
}