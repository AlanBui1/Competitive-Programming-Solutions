import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner kb = new Scanner(System.in);

        int t = kb.nextInt();
        for (int i=0; i<t; i++){
            String ans = "";
            int angle = kb.nextInt();

            if ((0 <= angle && angle <= 45) || (315 <= angle && angle <360)){
                ans = "N";
            }

            else if ((45 <= angle && angle <= 135)){
                ans = "E";
            }

            else if (135 < angle && angle <= 225){
                ans= "S";
            }
            else ans = "W";

            System.out.println(ans);
        }
    }
}