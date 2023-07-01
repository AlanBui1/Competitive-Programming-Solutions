import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        int l = kb.nextInt();
        kb.nextLine();
        String line = kb.nextLine();
        int leng = line.length();
        l %= 26;
        for (int i=0; i<leng; i++){
            char c = line.charAt(i);
            if (c == 32){
                System.out.print(" ");
            }
            else{
                c -= 97;
                c += l;
                c %= 26;
                char out = (char)(c+97);
                System.out.print(out);
            }
            
        }

        System.out.println();
    }
}