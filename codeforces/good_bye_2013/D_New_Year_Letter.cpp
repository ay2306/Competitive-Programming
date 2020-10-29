#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int k,x,n,m,res[202];
    pair<char,char> prv[202];
    string s = "ACZ";
    scanf("%lld%lld%lld%lld",&k,&x,&n,&m);
    if(n == 1 && m == 1 && k == 1)return printf("A\nC"),0;
    for(int first = 0; first <= n/2; first++){
        for(int second = 0; second <= m/2; ++second){
            for(char c1: s){
                for(char c2: s){
                    for(char c3: s){
                        for(char c4: s){
                            if(n == 1 && c1 != c2)continue;
                            if(m == 1 && c3 != c4)continue;
                            if(m == 2 && (c3 != 'A' || c4 != 'C') && second != 0)continue;
                            if(n == 2 && (c1 != 'A' || c2 != 'C') && first != 0)continue;
                            if(m == 2 && (c3 == 'A' && c4 == 'C') && second != 1)continue;
                            if(n == 2 && (c1 == 'A' && c2 == 'C') && first != 1)continue;
                            pair<char,char> a,b;
                            res[1] = first, res[2] = second;
                            prv[1] = make_pair(c1,c2), prv[2] = make_pair(c3,c4);
                            for(int i = 3; i <= k; ++i){
                                res[i] = res[i-1] + res[i-2];
                                if(prv[i-2].second == 'A' && prv[i-1].first == 'C')res[i]++;
                                prv[i] = make_pair(prv[i-2].first,prv[i-1].second);
                            }
                            if(res[k] == x){
                                string ans[2];
                                ans[0] = string(n,' ');
                                ans[1] = string(m,' ');
                                ans[0][0] = c1;
                                ans[0][n-1] = c2;
                                ans[1][0] = c3;
                                ans[1][m-1] = c4;
                                int i = 1;
                                int cnt = first;
                                while(cnt && i < n-1){
                                    if(ans[0][i-1] == 'A')ans[0][i] = 'C',cnt--;
                                    else ans[0][i] = 'A';
                                    i++;
                                }
                                while(i < n-1)ans[0][i++] = 'S';
                                i = 1;
                                cnt = second;
                                while(cnt && i < m-1){
                                    if(ans[1][i-1] == 'A')ans[1][i] = 'C',cnt--;
                                    else ans[1][i] = 'A';
                                    i++;
                                }
                                while(i < m-1)ans[1][i++] = 'S';
                                // cout << ans[0] << "\n" << ans[1] << "\n";
                                // cout << c1 << " " << c2 << " " << c3 << " " << c4 << " " << first << " " << second << "\n";
                                if(ans[0].front() != c1 || ans[0].back() != c2)continue;
                                if(ans[1].front() != c3 || ans[1].back() != c4)continue;
                                {
                                    int cnt = 0;
                                    for(int i = 1; i < n; ++i)
                                        cnt+=ans[0][i-1] == 'A' && ans[0][i] == 'C';
                                    if(cnt != first)continue;
                                }
                                {
                                    int cnt = 0;
                                    for(int i = 1; i < m; ++i)
                                        cnt+=ans[1][i-1] == 'A' && ans[1][i] == 'C';
                                    if(cnt != second)continue;
                                }
                                cout << ans[0] << "\n" << ans[1] << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Happy new year!");
    return 0;
}