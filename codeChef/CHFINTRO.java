import java.util.*;

public class CHFINTRO{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        while(n > 0){
            n--;
            int a = sc.nextInt();
            if(a >= r)System.out.println("Good boi");
            else System.out.println("Bad boi");
        }           
    }
}