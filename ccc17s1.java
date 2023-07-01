import java.util.Scanner;
import java.util.ArrayList;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);
        
        int n= kb.nextInt();
        ArrayList<Integer> a= new ArrayList<Integer>();
        ArrayList<Integer> b= new ArrayList<Integer>();
        
        for (int i=0; i<n; i++){
            int x = kb.nextInt();
            a.add(x);
        }
        for (int i=0; i<n; i++){
            int x = kb.nextInt();
            b.add(x);
        }

        int s1 = 0, s2 = 0, ans=0;

        for (int i=0; i<n; i++){
            s1 += a.get(i);
            s2 += b.get(i);
            if (s1 == s2)ans=i+1;
        }

        System.out.println(ans);
    }
}