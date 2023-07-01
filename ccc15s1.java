import java.util.*;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        ArrayList <Integer> arr = new ArrayList <Integer>();

        int k = kb.nextInt(), cnt = -1;

        for (int i=0; i<k; i++){
            int op = kb.nextInt();

            if (op == 0){
                if (cnt != -1){
                    arr.remove(cnt);
                    cnt--;
                }
            }
            else{
                arr.add(op);
                cnt++;
            }
        }
        
        int sz = arr.size(), ans = 0;
        for (int i=0; i<sz; i++){
            ans += arr.get(i);
        }

        System.out.println(ans);
    }
}