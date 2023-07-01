import java.util.*;
import java.io.*;

public class dmopc21c7p2{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
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

    public static void main(String [] args) throws IOException{
        LNode [] linkedList = new LNode [1000005];

        int n = dmopc21c7p2.readInt();
        int q = dmopc21c7p2.readInt();

        linkedList[n+1] = new LNode(-1, linkedList[n], null);
        for (int i=n; i>=0; i--){
            linkedList[i] = new LNode(i, null, linkedList[i+1]);
        }
        for (int i=n+1; i>0; i--){
            linkedList[i].setPrev(linkedList[i-1]);
        }
        
        for (int i=0; i<q; i++){
            int L = dmopc21c7p2.readInt(), R = dmopc21c7p2.readInt(), K = dmopc21c7p2.readInt();

            linkedList[L].getPrev().setNext(linkedList[R].getNext());
            linkedList[R].getNext().setPrev(linkedList[L].getPrev());

            linkedList[K].getNext().setPrev(linkedList[R]);
            linkedList[R].setNext(linkedList[K].getNext());

            linkedList[L].setPrev(linkedList[K]);
            
            linkedList[K].setNext(linkedList[L]);
            
        }

        LNode temp = linkedList[0];
        int count= 0;
        
        while (temp.getNext() != null && count < n){
            if (temp.getVal() > n) break;
            temp = temp.getNext();
            if (temp.getVal() > n) break;
            count++;
            System.out.print(temp.getVal()+" ");
        }
    }
}

class LNode {
    private int val;
    private LNode prevNode, nextNode;

    public LNode(int v, LNode prev, LNode next){
        val = v;
        prevNode = prev;
        nextNode = next;
    }

    public LNode getNext(){
        return nextNode;
    }
    public LNode getPrev(){
        return prevNode;
    }
    public int getVal(){
        return val;
    }

    public void setNext(LNode node){
        nextNode = node;
    }
    public void setPrev(LNode node){
        prevNode = node;
    }

    @Override
    public String toString(){
        return "{"+val+"}";
    }
}