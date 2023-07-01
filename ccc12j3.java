import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();

        for (int i=0; i<n; i++){
            for (int k=0; k<n; k++){
               System.out.print('*'); 
            }
            for (int k=0; k<n; k++){
                System.out.print('x');
            }
            for (int k=0; k<n; k++){
                System.out.print('*');
            }
            System.out.println();
        }
        for (int i=0; i<n; i++){
            for (int k=0; k<n; k++){
               System.out.print(' '); 
            }
            for (int k=0; k<n; k++){
                System.out.print('x');
            }
            for (int k=0; k<n; k++){
                System.out.print('x');
            }
            System.out.println();
        }
        
        
        for (int i=0; i<n; i++){
            for (int k=0; k<n; k++){
               System.out.print('*'); 
            }
            for (int k=0; k<n; k++){
                System.out.print(' ');
            }
            for (int k=0; k<n; k++){
                System.out.print('*');
            }
            System.out.println();

        }
    }
}