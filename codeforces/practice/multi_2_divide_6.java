import java.util.Scanner;

public class solution{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int test = 0; test < t; ++test){
            int n = sc.nextInt();
            int two = 0, three = 0;
            while(n%3 == 0){
                three++;
                n/=3;
            }
            while(n%2 == 0){
                two++;
                n/=2;
            }
            if(n == 1 && two <= three)System.out.println(2*three-two);
            else System.out.println(-1);
        }
    }
} 