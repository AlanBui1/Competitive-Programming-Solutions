import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();

        String[] arr = {"GGGGG", "G....", "G..GG", "G...G", "GGGGG"};

        for (String s : arr){
            for (int j=0; j<n; j++){
                for (int i=0; i<5; i++){
                    for (int k=0; k<n; k++){
                        System.out.print(s.charAt(i));
                    }
                }
                System.out.println();
            }
        }

        

        
    }
}