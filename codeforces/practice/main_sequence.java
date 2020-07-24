import java.util.*;
import java.io.*;
public class main_sequence{
    public static void main(String[] args)  throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for(int i = 0; i < n; ++i)arr[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int neg = Integer.parseInt(st.nextToken());
        if(neg*2 > n){
            System.out.println("NO");
            return;
        }
        for(int i = 0; i < n/2; ++i){
            int e = arr[i];
            arr[i] = arr[n-1-i];
            arr[n-1-i] = e;
        }
        for(int i = 0; i < neg; ++i){
            int ind = Integer.parseInt(st.nextToken());
            ind--;
            arr[n-1-ind] = -arr[n-1-ind];
        }
        Stack<Integer> s = new Stack<Integer> ();
        for(int i = 0; i < n; ++i){
            if(arr[i] > 0 && !s.empty() && arr[s.peek()] == -arr[i])s.pop();
            else{
                arr[i] = -Math.abs(arr[i]);
                s.push(i);
            }
        }
        if(!s.empty()){
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
        StringBuilder res = new StringBuilder("");
        for(int i = n-1; i >= 0; --i)res.append(Integer.toString(arr[i]) + " ");
        System.out.println(res.toString());
    }
}