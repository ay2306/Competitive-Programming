#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+10;

/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;



struct edge{
    int dis;
    int to;
    edge(int a, int b):dis(a),to(b){}
};
int d[N],n,a,b,c,t;
vector<edge> g[N];
int dfs(int s = 1, int p = -1){
    int mx = s;
    if(p == -1)d[s] = 0;
    for(edge &i: g[s]){
        if(i.to == p)continue;
        d[i.to] = d[s] + i.dis;
        int res = dfs(i.to,s);
        if(d[res] > d[mx])mx=res;
    }   
    return mx;
}

int main(){
    t = readInt();
    while(t--){
        n = readInt();
        for(int i = 1; i <= n; ++i)g[i].clear();
        for(int i = 1; i < n; ++i){
            a = readInt();
            b = readInt();
            c = readInt();
            g[a].emplace_back(edge(c,b));
            g[b].emplace_back(edge(c,a));
        }
        int r = dfs(dfs(1));
        writeInt(d[r],'\n');
    }
    return 0;
}