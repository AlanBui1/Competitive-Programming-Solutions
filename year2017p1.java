import java.util.*;
import java.io.*;

public class Main{
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
    
    public static void main(String[] args) throws IOException{
        int q = Main.readInt();
        LList dq = new LList();
        HashMap <Integer, LNode> conv = new HashMap<Integer, LNode>();
        
        for (int i=0; i<q; i++){
            char op = Main.readCharacter();
            int x = Main.readInt();
            if (op == 'F'){
                dq.push_front(x);
                conv.put(x, dq.getFront());
            }
            if (op == 'E'){
                dq.push_back(x);
                conv.put(x, dq.getBack());
            }
            if (op == 'R'){
                dq.delete(conv.get(x));
                // dq.delete(x);
            }
        }
        
        dq.printOut();
    }
}

class LList {
    private LNode head, tail;

    public LList(){
        head = null;
        tail = null;
    }

    public LNode getFront(){
        return head.getNext();
    }
    public LNode getBack(){
        return tail.getPrev();
    }

    public void push_front(int v){
        LNode temp = new LNode(v, head, null, false, false);
        if (head == null){
            head = new LNode(-1, null, temp, true, false);
            tail = new LNode(-123, temp, null, false, true);
            temp.setPrev(head);
            temp.setNext(tail);
            return;
        }

        temp.setNext(head.getNext());
        head.getNext().setPrev(temp);
        head.setNext(temp);
    }

    public void push_back(int v){
        LNode temp = new LNode(v, null, tail, false, false);
        
        if (tail == null){
            head = new LNode(-1, null, temp, true, false);
            tail = new LNode(-123, temp, null, false, true);
            temp.setPrev(head);
            temp.setNext(tail);
            return;
        }

        temp.setPrev(tail.getPrev());
        tail.getPrev().setNext(temp);
        tail.setPrev(temp);
    }

    public LNode pop_front(){
        LNode ret = head.getNext();
        if (ret.isTail() || ret.isHead()){
            throw new EmptyStackException("Stack is Empty");
        }
        head.setNext(head.getNext().getNext());
        head.getNext().setPrev(head);
        if (head.getNext().isTail()){
            head = null;
            tail = null;
        }
        return ret;
    }

    public LNode pop_back(){
        LNode ret = tail.getPrev();
        if (ret.isTail() || ret.isHead()){
            throw new EmptyStackException("Stack is Empty");
        }

        tail.setPrev(tail.getPrev().getPrev());
        tail.getPrev().setNext(tail);
        if (tail.getPrev().isHead()){
            head = null;
            tail = null;
        }
        
        return ret;
    }

    public void delete(int x){
        LNode temp = head;

        while (temp.getNext() != null){
            temp = temp.getNext();
            if (temp.getVal() == x){
                delete(temp);
                return;
            }
        }
    }

    public void delete(LNode node){
        node.getPrev().setNext(node.getNext());
        node.getNext().setPrev(node.getPrev());
    }

    public void deleteAt(int ind){
        LNode temp = head;
        
        while (ind > 0){
            temp = temp.getNext();
            ind--;
        }
        
        delete(temp);
    }

    public void sortedInsert(int x){
        if (head == null){
            push_front(x);
            return;
        }

        LNode temp = head, toAdd = new LNode(x, null, null, false, false);
        while (temp.getNext() != null){
            temp = temp.getNext();

            if (temp.getVal() > x){
                toAdd.setPrev(temp.getPrev());
                toAdd.setNext(temp);

                temp.getPrev().setNext(toAdd);
                temp.setPrev(temp);
                return;
            }
        }

        push_back(x);
    }

    public int index(int v){
        LNode temp = head;
        int idx = -1;

        while (temp.getNext() != null){
            temp = temp.getNext();
            idx++;
            if (temp.getVal() == v){
                return idx;
            }
        }

        return idx;
    }

    public void removeDuplicates(){
        if (head == null) return;
        LNode temp = head.getNext();
        int curIndex = -1;
        while (temp.getNext() != null){
            curIndex++;

            if (index(temp.getVal()) < curIndex){
                temp = temp.getNext();
                delete(temp.getPrev());
            }
            else{
                temp = temp.getNext();
            }
        }
    }

    public void reverse(){
        LList temp = new LList();

        LNode node = head;
        while (node.getNext() != null){
            node = node.getNext();
            temp.push_back(node.getVal());
        }

        head = temp.head;
        tail = temp.tail;
    }

    public LList clone(){
        LList ret = new LList();

        LNode temp = head;

        while (temp.getNext() != null){
            temp = temp.getNext();
            ret.push_back(temp.getVal());
        }

        return ret;
    }

    public void printOut(){
        if (head == null) return;
        
        LNode temp = head;
        
        while (temp.getNext() != null){
            temp = temp.getNext();
            if (!temp.isTail()) System.out.println(temp.getVal());
        }
    }
}

class LNode {
    private int val;
    private LNode prevNode, nextNode;
    private boolean isHead, isTail;

    public LNode(int v, LNode prev, LNode next, boolean h, boolean t){
        val = v;
        prevNode = prev;
        nextNode = next;
        isHead = h;
        isTail = t;
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

    public boolean isHead(){
        return isHead;
    }
    public boolean isTail(){
        return isTail;
    }

    @Override
    public String toString(){
        return "{"+val+"}";
    }
}

class EmptyStackException extends RuntimeException { 
    public EmptyStackException(String mess) {
        super(mess);
    }
}