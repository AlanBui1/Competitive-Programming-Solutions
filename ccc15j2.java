import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);
        String line = kb.nextLine();
        int a = 0, b = 0;
        
        for (int i=0; i<line.length()-3; i++){
            if (line.charAt(i) == ':' && line.charAt(i+1) =='-' && line.charAt(i+2) == ')'){
                a++;
            }
            
            if (line.charAt(i) == ':' && line.charAt(i+1) =='-' && line.charAt(i+2) == '('){
                b++;
            }
        }

        if (a == 0 && b == 0){
            System.out.println("none");
        }

        else if (a == b){
            System.out.println("unsure");
        }

        else if (a > b){
            System.out.println("happy");
        }

        else{
            System.out.println("sad");
        }
    }
}