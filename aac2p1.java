import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();
        kb.nextLine();
        String line = kb.nextLine();

        int ans = 0;

        int[] arr = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        for (int i=0; i<n; i++){
            arr[line.charAt(i)-'a']++;
        }
        int one = 0;
        for (int i=0; i<26; i++){
            if (arr[i] >=2) one = 1;
            ans += arr[i]%2;
        }

        if (ans == 0 && one == 1) ans = 1;
        System.out.println(ans);


    }
}