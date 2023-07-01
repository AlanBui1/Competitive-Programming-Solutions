import java.util.*;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt(), ans=0;
        kb.nextLine();
        String line1 = kb.nextLine();
        String line2 = kb.nextLine();

        for (int i=0; i<n; i++){
            if (line1.charAt(i) == line2.charAt(i) && line1.charAt(i) == 'C'){
                ans++;
            }
        }
        System.out.println(ans);
    }
}