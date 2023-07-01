import java.io.*;
import java.util.*;

public class fast{
    public static void main(String [] args) throws IOException{
        Scanner inFile = new Scanner(System.in);
        int n = inFile.nextInt();
        int [] arr = new int[n];
        for (int i=0; i<n; i++){
            arr[i] = inFile.nextInt();
        }
        // inFile.close();
        
        LList stack = new LList();
        stack.push_front(arr[0]);
        
        int ans = 1;
        
        for (int i=0; i<n; i++){
            int newElement = arr[i];
            
            while (stack.get_front() != null && stack.get_front().getVal() > newElement){
                stack.pop_front();
            }
            
            if (stack.get_front() == null){
                stack.push_front(newElement);
                //ans++;
            }
            else if (stack.get_front().getVal() != newElement){
                stack.push_front(newElement);
                if (newElement != 0) ans++;
            }
        }
        System.out.println(ans);
    }
}


class LList{
    private LNode head, tail;
    private int GARBAGE = -1;

    public LList(){
        head = null;
        tail = null;
    }

    public void push_front(int x){
        if (head == null){
            LNode node = new LNode(x, null, null, false);
            LNode temp = new LNode(GARBAGE, node, null, true);
            node.setNext(temp);
            head = node;
        }
        else{
            LNode node = new LNode(x, null, null, false);
            LNode temp = new LNode(head.getVal(), node, head.getNext(), false);
            node.setNext(temp);
            head = node;
        }
    }

    public void push_back(int x){
        if (tail == null){
            LNode node = new LNode(x, null, null, false);
            LNode temp = new LNode(GARBAGE, null, node, true);
            node.setPrev(temp);
            tail = node;
        }
        else{
            LNode node = new LNode(x, null, null, false);
            LNode temp = new LNode(tail.getVal(), tail.getPrev(), node, false);
            node.setPrev(temp);
            tail = node;
        }
    }
    
    public LNode get_front(){
        return head;
    }

    public LNode pop_front(){
        if (head == null || head.isGarbage()){
            LNode temp = tail;
            while (temp.getPrev() != null){
                head = temp;
                temp = temp.getPrev();
            }
        }
        
        LNode ret = head;
        head = ret.getNext();
        return ret;
    }

    public LNode pop_back(){
        if (tail == null || tail.isGarbage()){
            LNode temp = head;
            while (temp.getNext() != null){
                tail = temp;
                temp = temp.getNext();
            }
        }
        
        LNode ret = tail;
        tail = ret.getPrev();
        return ret;
    }

    public void printForward(){
        String ret = "";

        LNode temp = head;
        while (temp != null){
            ret += temp.getVal();
            if (temp.getNext() != null) ret += ", ";
            temp = temp.getNext(); 
        }
        ret = "{"+ret+"}\n";

        System.out.println(ret);
    }

    public void printBackward(){
        String ret = "";
        LNode temp = tail;
        while (temp != null){
            ret += temp.getVal();
            if (temp.getPrev() != null) ret += ", ";
            temp = temp.getPrev();
        }
        ret = "{"+ret+"}\n";

        System.out.println(ret);
    }

    @Override
    public String toString(){
        return "";
    }
}

class LNode{
    private int val;
    private LNode prevNode, nextNode;
    private boolean garbage;

    public LNode(int v, LNode prev, LNode next, boolean b){
        val = v;
        prevNode = prev;
        nextNode = next;
        garbage = b;
    }

    public int getVal(){
        return val;
    }

    public LNode getNext(){
        return nextNode;
    }

    public LNode getPrev(){
        return prevNode;
    }

    public boolean isGarbage(){
        return garbage;
    }

    public void setNext(LNode node){
        nextNode = node;
    }

    public void setPrev(LNode node){
        prevNode = node;
    }

    @Override
    public String toString(){
        String ret = "";
        ret += val;
        return "{"+ret+"}";
    }
}