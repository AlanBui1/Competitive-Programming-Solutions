import java.util.Scanner;

public class Main{
    static public void main(String []args){
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        String garbage = kb.nextLine();
        String lin = kb.nextLine();

        int a = 0, b = 0;

        for (int i=0; i<n; i++){
            if (lin.charAt(i) == 'A'){
                a++;
            }
            else{
                b++;
            }
        }
        if (a > b){
            System.out.println('A');
        }
        else if (b > a){
            System.out.println('B');
        }
        else{
            System.out.println("Tie");
        }
        
    }   
}