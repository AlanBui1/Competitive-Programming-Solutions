import java.util.*;

public class Main{
    public static void main(String []args){
        Scanner kb = new Scanner(System.in);

        int r = kb.nextInt(), c = kb.nextInt(), zr = kb.nextInt(), zc = kb.nextInt();

        kb.nextLine();

        for (int i=0; i<r; i++){
            String line = kb.nextLine();
            for (int k=0; k<zr; k++){
                for (int l = 0; l < c; l++){
                    for (int j=0; j<zc; j++){
                        System.out.print(line.charAt(l));
                    }
                }
                System.out.println();   
            }
        }
    }
}