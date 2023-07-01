import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int[] arr = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

        int n= kb.nextInt();
        kb.nextLine();

        

        for (int i=0; i<n; i++){
            String s = kb.nextLine();
            int x = s.length(); int cnt = 0;
            
            for (int k=0; k<x; k++){
                if (s.charAt(k) == ' ' || s.charAt(k) == '-'){
                    continue;
                }

                if (48 <= s.charAt(k) && s.charAt(k) <= 57){
                    System.out.print(s.charAt(k));
                    
                }

                else{
                    System.out.print(arr[s.charAt(k)-'A']);
                }
                cnt++;

                if (cnt == 3 || cnt == 6){
                    System.out.print("-");
                }

                if (cnt == 10){
                    break;
                }
            }

            System.out.println();

            
        }

    }
}