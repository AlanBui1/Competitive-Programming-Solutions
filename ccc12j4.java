import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int k = kb.nextInt();
        kb.nextLine();
        
        String line = kb.nextLine();

        char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        for (int i=0; i<line.length(); i++){
            int P = 3*(i+1) + k;
            //System.out.println(line.charAt(i));
            System.out.print(arr[(line.charAt(i)-'A'-P+26)%26]);
        }
        System.out.println();
    }
}