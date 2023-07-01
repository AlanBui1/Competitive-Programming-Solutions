import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        
        String line = kb.nextLine();

        int leng = line.length();

        String ret = "", num="";

        for (int i=0; i<leng; i++){
            if (65 <= line.charAt(i) && line.charAt(i) <= 91){
                if (num.length()>0){
                    System.out.println(num);
                    num = "";
                }
                ret += line.charAt(i);
            }

            else{
                if (line.charAt(i) == '+'){
                    System.out.print(ret + " tighten ");
                    ret = "";
                }

                else if (line.charAt(i) == '-'){
                    System.out.print(ret + " loosen ");
                    ret = "";
                }

                else{
                    num += line.charAt(i);
                }
            }
        }
        if (num.length() > 0){
            System.out.println(num);
        }
    }
}