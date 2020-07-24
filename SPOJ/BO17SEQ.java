import java.util.*;
public class BO17SEQ{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Long ans = Long.valueOf(0), a, mn = Long.MAX_VALUE;
		for(int i = 0 ; i < n; ++i){
			a = sc.nextLong();
			ans += a;
			mn = Math.min(mn,a);
		}
		ans -= mn;
		System.out.println(ans);
	}
}
