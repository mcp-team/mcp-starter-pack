#include <cstdio>
#include <set>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef set<int, greater<int>> st;
typedef vector<st> vst;

struct Node
{   int sz, label; /* size, label */
    Node *p, *pp, *l, *r; /* parent, path-parent, left, right pointers */
    Node() { p = pp = l = r = 0; }
};

void update(Node *x)
{   x->sz = 1;
    if(x->l) x->sz += x->l->sz;
    if(x->r) x->sz += x->r->sz;
}

void rotr(Node *x)
{   Node *y, *z;
    y = x->p, z = y->p;
    if((y->l = x->r)) y->l->p = y;
    x->r = y, y->p = x;
    if((x->p = z))
    {   if(y == z->l) z->l = x;
        else z->r = x;
    }
    x->pp = y->pp;
    y->pp = 0;
    update(y);
}

void rotl(Node *x)
{   Node *y, *z;
    y = x->p, z = y->p;
    if((y->r = x->l)) y->r->p = y;
    x->l = y, y->p = x;
    if((x->p = z))
    {   if(y == z->l) z->l = x;
        else z->r = x;
    }
    x->pp = y->pp;
    y->pp = 0;
    update(y);
}

void splay(Node *x)
{   Node *y, *z;
    while(x->p)
    {   y = x->p;
        if(y->p == 0)
        {   if(x == y->l) rotr(x);
            else rotl(x);
        }
        else
        {   z = y->p;
            if(y == z->l)
            {   if(x == y->l) rotr(y), rotr(x);
                else rotl(x), rotr(x);
            }
            else
            {   if(x == y->r) rotl(y), rotl(x);
                else rotr(x), rotl(x);
            }
        }
    }
    update(x);
}

Node *access(Node *x)
{   splay(x);
    if(x->r)
    {   x->r->pp = x;
        x->r->p = 0;
        x->r = 0;
        update(x);
    }

    Node *last = x;
    while(x->pp)
    {   Node *y = x->pp;
        last = y;
        splay(y);
        if(y->r)
        {   y->r->pp = y;
            y->r->p = 0;
        }
        y->r = x;
        x->p = y;
        x->pp = 0;
        update(y);
        splay(x);
    }
    return last;
}

Node *root(Node *x)
{   access(x);
    while(x->l) x = x->l;
    splay(x);
    return x;
}

void cut(Node *x)
{   access(x);
    x->l->p = 0;
    x->l = 0;
    update(x);
}

void link(Node *x, Node *y)
{   access(x);
    access(y);
    x->l = y;
    y->p = x;
    update(x);
}

Node *lca(Node *x, Node *y)
{   access(x);
    return access(y);
}

int depth(Node *x)
{   access(x);
    return x->sz - 1;
}

class LinkCut
{   Node *x;

    public:
    LinkCut(int n)
    {   x = new Node[n];
        for(int i = 0; i < n; i++)
        {   x[i].label = i;
            update(&x[i]);
        }
    }

    virtual ~LinkCut()
    {   delete[] x;
    }

    void link(int u, int v)
    {   ::link(&x[u], &x[v]);
    }

    void cut(int u)
    {   ::cut(&x[u]);
    }

    int root(int u)
    {   return ::root(&x[u])->label;
    }

    int depth(int u)
    {   return ::depth(&x[u]);
    }

    int lca(int u, int v)
    {   return ::lca(&x[u], &x[v])->label;
    }
};

vst AdjTree;
vst DirTree;
vi marked;

void buildLC(int node, LinkCut &LC) {
    marked[node] = 1;
    for (auto t : AdjTree[node]) {
        if (marked[t] == 0) {
        	// printf("%d ", t);
            LC.link(t,node);
            DirTree[t].insert(node);
            buildLC(t, LC);
        }
    }
}

int main(void)
{   
    int n, query, s, t, ex, xe;
    char c;
    scanf("%d", &n);
    LinkCut LC(n);
    AdjTree.assign(n,st());
    DirTree.assign(n,st());
    marked.assign(n,0);
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &s, &t);
        s--; t--;
        AdjTree[s].insert(t);
        AdjTree[t].insert(s);
    }
    buildLC(0,LC);
    scanf("%d", &query);
    while (query--) {
        scanf(" %c %d %d", &c, &s, &t);
        s--; t--;
        if (c == 'd') {
            if (AdjTree[s].find(t) == AdjTree[s].end()) continue; 
            ex = LC.root(s); xe = LC.root(t);
            if (ex != xe) continue;
            if (DirTree[t].find(s) != DirTree[t].end()) LC.cut(t);
            else LC.cut(s);
        }
        else if (c == 'c') {
            if (AdjTree[s].find(t) == AdjTree[s].end())  continue;
            int ex = LC.root(s); xe = LC.root(t);
            if (ex == xe) continue;
            if (DirTree[t].find(s) != DirTree[t].end()) LC.link(t,s);
            else LC.link(s,t);
        }
        else {
            int ex = LC.root(s); xe = LC.root(t);
            if (ex != xe) 
                printf("Impossible\n");
            else {
                printf("%d\n", LC.depth(s) + LC.depth(t) - 2*LC.depth(LC.lca(s,t)));
            }
        }
    }
    return 0;
}
