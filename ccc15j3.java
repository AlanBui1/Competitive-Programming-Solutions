import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        String line = kb.nextLine(), ans= "";
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};

        int leng = line.length();

        for (int i=0; i<leng; i++){
            char C = line.charAt(i);

            boolean in = false;

            for (char c : vowels){
                if (c == C){
                    in = true;
                    break;
                }
            }

            if (in){
                ans += C;
            }

            else{
                ans += C;

                int closest = 1000;
                char ret = ' ';

                for (char c : vowels){
                    int dist = C-c;
                    if (dist < 0) dist = -dist;

                    if (dist < closest){
                        closest = dist;
                        ret = c;
                    }
                }

                ans += ret;
                if (C == 'z'){
                    ans += 'z';
                }
                else{
                    char add = (char)(C+1);
                    
                    for (char z : vowels){
                        if (z == add){
                            add++;
                            break;
                        }
                    }
                    ans +=add ;
                    
                }
                
            }
        }
        System.out.println(ans);
    }
}