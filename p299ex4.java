import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int t = readInt();
		
		for (int _=0; _<t; _++){
		    int n = readInt();
		    int ans = 1;
		    
		    if (n == 1){
		        ans = 0;
		    }
		    else if (n == 2 || n == 3 || n == 5){
		        ;
		    }
		    else if (n == 4){
		        ans = 0;
		    }
		    
		    else{
		        for (int i=2; i*i <= n; i++){
		            if (n%i == 0){
		                ans = 0;
		                break;
		            }
		        }
		    }
		    
		    System.out.println(ans);
	
		}
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}