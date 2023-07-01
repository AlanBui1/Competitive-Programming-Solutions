import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        String line = kb.nextLine();
        int n = line.length();

        int a = 1, b = 2, c = 3, d = 4;

        for (int i=0; i<n; i++){
            if (line.charAt(i) == 'H'){
                int extra = a;
                a = c;
                c = extra;
                extra = b;
                b = d;
                d = extra;
            }

            else{
                int extra = a;
                a = b;
                b = extra;
                extra = c;
                c = d;
                d = extra;
                
            }
        }
        System.out.println(a+ " " +b);
        System.out.println(c+ " "+d);
        
    }
}