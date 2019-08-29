import java.util.Scanner;

public class a{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int min_m = m + 1, min_n = n+1, max_n = -1, max_m = -1;
        for(int i = 0; i < n; ++i){
            String a = sc.next();
            for(int j = 0; j < m; ++i){
                if(a.charAt(j) =='B'){
                    min_m = Math.min(min_m,j);
                    min_m = Math.min(min_n,i);
                    min_m = Math.max(max_m,j);
                    min_m = Math.max(max_n,i);
                }
            }
        }
        System.out.println("HELLO WORLD");
        System.out.println(((min_n+max_n)/2) + " " + ((min_m+max_m)/2));
    }
}