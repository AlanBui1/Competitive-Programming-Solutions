import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt(), ans = 0;

        for (int i=1; i<n; i++){
            for (int k=i+1; k<n; k++){
                for (int j=k+1; j< n; j++){
                    
                    if (i < k && k < j && j < n){
                        ans ++;
                    }
                    else{
                        break;
                    }
                    
                }
            }
        }

        System.out.println(ans);
    }
}