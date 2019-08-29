import java.util.*;

public class MAXEP{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int a = n/2;
        int l = 1;
        int r = n;
        System.out.println("1 " + n/2);
        int res = sc.nextInt();
        if(res == 1){
            System.out.println("2");
            r = n/2 - 1;
        }else{
            l = n/2+1;
        }
        for(int i = l; i <= r+1; ++i){
            System.out.println("1 " + i);
            res = sc.nextInt();
            if(res == 1){
                System.out.println("2");
                System.out.println("3" + (i));
                break;
            }
        }
    }
}