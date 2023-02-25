
template<size_t ASZ> struct AC {/*{{{*/
    struct node {
        AR<int, ASZ> to;
        int lk;
    };
    V<node> d{{}};
    int ins(str s) {
        int u = 0;
        each(ch, s) {
            int c = ch - 'a';
            if (!d[u].to[c]) d[u].to[c] = SZ(d), d.eb();
            u = d[u].to[c];
        }
        return u;
    }
    void build() {
        queue<int> q; q.push(0);
        d[0].lk = -1;
        while (!q.empty()) {
            int u = q.ft; q.pop();
            F0R(c, ASZ) {
                int v = d[u].to[c]; 
                if (!v) continue;
                d[v].lk = ~d[u].lk ? d[d[u].lk].to[c] : 0;
                q.push(v);
            }
            if (u) {
                F0R(c, ASZ) if (!d[u].to[c]) {
                    d[u].to[c] = d[d[u].lk].to[c];
                }
            }
        }
    }
};/*}}}*/
