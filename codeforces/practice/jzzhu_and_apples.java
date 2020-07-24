import java.util.*;


public class jzzhu_and_apples {
    static class Pair{
        public int first, second;
        public Pair(int first, int second){
            this.first = first;
            this.second = second;
        }
        public void printf(){
            System.out.println(first + " " + second);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n <= 3){
            System.out.println(0);
            return;
        }
        int pr[] = new int[n+1];
        int used[] = new int[n+1];
        ArrayList<Integer> p = new ArrayList<Integer>();
        for(int i = 2; i <= n; ++i){
            if(pr[i] != 0)continue;
            if(i != 2)p.add(i);
            for(int j = i; j <= n; j +=i){
                pr[j] = i;
            }
        }
        p.add(2);
        ArrayList<Pair> ans = new ArrayList<Pair>();
        for(Integer i: p){
            if(2*i > n)continue;
            ArrayList<Integer> s = new ArrayList<Integer>();
            for(int j = i; j <= n; j+=i){
                if(used[j] == 0)s.add(j);
            }
            if(s.size() == 1)continue;
            if(s.size() % 2 == 1){
                s.remove(1);
            }
            for(int j = 1; j < s.size(); j+=2){
                ans.add(new Pair(s.get(j-1),s.get(j)));
                used[s.get(j-1)] = 1;
                used[s.get(j)] = 1;
            }
        }
        System.out.println(ans.size());
        for(Pair i: ans)i.printf();
    }
}