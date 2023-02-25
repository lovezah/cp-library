
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
namespace treap {

    typedef struct tnode* pt;
    struct tnode {
        int pri, val, sz;
        int64_t sum = 0;
        pt c[2];
        bool flip = 0;
        tnode (int val) : val(val) {
            pri = rng(); sum = val;
            sz = 1; c[0] = c[1] = NULL;
        }
        ~tnode() { for (int i = 0; i < 2; i++) delete c[i]; }
    };
    int getSz(pt x) { return x ? x->sz : 0; }
    ll getSum(pt x) { return x ? x->sum : 0; }
    void push(pt x) {
        if (!x || !x->flip) return;
        std::swap(x->c[0], x->c[1]);
        x->flip = 0;
        for (int i = 0; i < 2; i++) if (x->c[i]) x->c[i]->flip ^= 1;
    }
    pt calc(pt x) {
        pt a = x->c[0], b = x->c[1];
        push(a), push(b);
        x->sz = getSz(a) + getSz(b) + 1;
        x->sum = getSum(a) + getSum(b) + x->val;
        return x;
    }
    void tour(pt x, std::vector<int>& v) {
        if (!x) return; push(x);
        tour(x->c[0], v);
        v.push_back(x->val);
        tour(x->c[1], v);
    }
    std::pair<pt, pt> split(pt t, int v) { // >= v goes to the right
        if (!t) return {t, t};
        push(t);
        if (t->val >= v) {
            auto p = split(t->c[0], v); t->c[0] = p.second;
            return {p.first, calc(t)};
        } else {
            auto p = split(t->c[1], v); t->c[1] = p.first;
            return {calc(t), p.second};
        }
    }
    std::pair<pt, pt> split_by_size(pt t, int sz) { // sz nodes go to left
        if (!t) return {t, t};
        push(t);
        if (getSz(t->c[0]) >= sz) {
            auto p = split_by_size(t->c[0], sz); t->c[0] = p.second;
            return {p.first, calc(t)};
        } else {
            auto p = split_by_size(t->c[1], sz-getSz(t->c[0])-1); t->c[1] = p.first;
            return {calc(t), p.second};
        }
    }
    pt merge(pt l, pt r) {
        if (!l || !r) return l ?: r;
        push(l), push(r);
        pt t;
        if (l->pri > r->pri) l->c[1] = merge(l->c[1], r), t = l;
        else r->c[0] = merge(l, r->c[0]), t = r;
        return calc(t);
    }
    pt ins(pt x, int v) {
        auto a = split(x, v), b = split(a.second, v+1);
        return merge(a.first, merge(new tnode(v), b.second));
    }
    pt del(pt x, int v) {
        auto a = split(x, v), b = split(a.second, v+1);
        return merge(a.first, b.second);
    }

} // namespace treap
using namespace std;

