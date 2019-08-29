/*
 _______________________________________________________________________
|                                                                       |
|                          Author: ay2306                               |
|Code Reference: https://codeforces.com/contest/180/submission/49500212 |
|_______________________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

int i;
string s,t;
string ans;
const ll maxn = 1e5;
map<char,int> m;

int main(){
    ans = "";
    cin >> s >> t;
    for(auto i: s)m[i]++;
    int i;
    bool uneq = false;
    for(i = 0; i < t.size(); ++i){
        if(m[t[i]] > 0){
            ans+=t[i];
            m[t[i]]--;
        }else{
            uneq = true;
            break;
        }
    }
    // From above code uneq remains false until we can match character of string t
    // with that of s. Thus if there is any position for which we cannot fill equal character
    // we break
    if(uneq || s.size() <= t.size()){
        // In this if we deal with the case where either we cannot place an equal character for respective t[i]
        // Reason 1: we dont have that many t[i] characters
        // Even if we have our string s is smaller that t, so equal characters will make it lexicographically smaller
        // or atmax equal
        priority_queue<char> p;
        // We create a priority queue for all the remaining characters
        for(auto iter: m){
            if(iter.S > 0){
                p.push(iter.F);
            }
        }
        //If our largest remaining character is greater than t[i], it means we can make this lexicographically larger than t
        if(p.size() && p.top() > t[i]){
            //First we choose smallest character greater than t[i] and decrease that from hashTable
            for(auto iter: m){
                if(iter.S > 0 && iter.F > t[i]){
                    ans+=iter.F;
                    m[iter.F]--;
                    break;
                }
            }
            //Then add all the remaining characters in lexicographical order
            for(auto iter: m){
                for(int j = 0; j < iter.S; ++j)ans+=iter.F;
            }
            cout << ans;
        }else{
            // This else means that in the remaining characters we donot have any character placing which can make string
            // lexicographically larger
            // Thus we go back our answer string and check if inclusion of that character can help or not
            while(p.empty() || p.top() <= t[i]){
                if(ans.size() == 0)break;
                p.push(ans[ans.size()-1]);
                m[ans[ans.size()-1]]++;
                ans.pop_back();
                --i;
            }
            //We stop either when string ans is empty or we found a character placing which can 
            // make string lexicographically larger

            // If we found the character
            if(p.size() && p.top() > t[i]){
                for(auto iter: m){
                    if(iter.S > 0 && iter.F > t[i]){
                        ans+=iter.F;
                        m[iter.F]--;
                        break;
                    }
                }
                for(auto iter: m){
                    for(int j = 0; j < iter.S; ++j)ans+=iter.F;
                }
                cout << ans;
            }
            // If it is not possible as we emptied answer string but not possible
            else{
                cout << "-1";
            }
        }
    }else{
        // We come to this else if we matched all characters with t and length of string s is greater than that of t
        for(auto iter: m){
            for(int j = 0; j < iter.S; ++j)ans+=iter.F;
        }
        cout << ans;
        
    }
    return 0;
}