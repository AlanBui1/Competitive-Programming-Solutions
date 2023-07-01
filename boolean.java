import java.io.*;

public class Main{
  public static void main(String []args){
    try{
      BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
        String line = kb.readLine();

        int cnt = 0, leng = line.length();
        
        for (int i=0; i<leng-3; i++){
            if (line.charAt(i) == 'n' && line.charAt(i+1) == 'o' && line.charAt(i+2) == 't'){
                cnt++;
            }
        }



        if (line.charAt(leng-2) == 's'){
            //False
            if (cnt %2 == 0){
                System.out.println("False");
            }
            else{
                System.out.println("True");
            }
        }

        else{
            if (cnt %2 == 1){
                System.out.println("False");
            }
            else{
                System.out.println("True");
            }
        }
      
    }
    catch(IOException ex){
    ;
    }
  }
}