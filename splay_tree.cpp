typedef long long ll;
const ll inf=1e16;
struct node
{
    node *p,*l,*r;
    ll key;
    ll cnt;
    int flip;
    int dummy;
    ll mx,mn,sum;
    node(ll _key, node *par) : key(_key),p(par) {
        l=r=nullptr;
        sum=mx=mn=_key;
        cnt=1,dummy=0,flip=0;
    }
};
struct Splay_tree
{
    node *root;
    node *ptr[1000010];
    void push(node *x)
    {
        if(x->flip==0) return;
        swap(x->l,x->r);
        for(node *i:{x->l,x->r})
            if(i!=NULL) (i->flip)^=1;
        x->flip=0;
    }
    void update(node *x)
    {
        x->cnt=1,x->sum=x->mn=x->mx=x->key;
        if(x->l!=NULL)
        {
            x->cnt+=x->l->cnt;
            x->mx=max(x->mx,x->l->mx);
            x->sum=x->sum+x->l->sum;
            x->mn=min(x->mn,x->l->mn);
        }
        if(x->r!=NULL)
        {
            x->cnt+=x->r->cnt;
            x->mx=max(x->mx,x->r->mx);
            x->sum=x->sum+x->r->sum;
            x->mn=min(x->mn,x->r->mn);
        }
    }
    void rotate(node *x)
    {
        node *par=x->p;
        node *child;
        if(par==NULL) return;
        push(par);
        push(x);
        if(par->l==x)
        {
            child=x->r;
            par->l=child; 
            x->r=par;
        }
        else
        {
            child=x->l;
            par->r=child;
            x->l=par;
        }
        x->p=par->p;
        par->p=x;
        if(child!=NULL) child->p=par;
        if(x->p!=NULL)
        {
            if(x->p->l==par) x->p->l=x;
            else x->p->r=x;
        }
        else root=x;
        update(par);
        update(x);
    }
    void splay(node *x,node *g=nullptr)
    {
        while(x->p!=g)
        {
            node *par=x->p;
            node *gpar=par->p;
            if(gpar==g)
            {
                rotate(x);
                break;
            }
            if((gpar->l==par && par->l==x) || (gpar->r==par && par->r==x))
            {
                rotate(par);
                rotate(x);
            }
            else
            {
                rotate(x);
                rotate(x);
            }
        }
        if(!g) root=x;
    }
    void _insert(int num)
    {
        node *x;
        if(root==NULL)
        {
            x->l=x->r=x->p=NULL;
            x->key=num;
            root=x;
            return;
        }
        node *cur=root;
        node **idx;
        while(1)
        {
            if(num==cur->key) return;
            if(num<cur->key)
            {
                if(cur->l==NULL)
                {
                    idx=&(cur->l);
                    break;
                }
                else cur=cur->l;
            }
            else
            {
                if(cur->r==NULL)
                {
                    idx=&(cur->r);
                    break;
                }
                else cur=cur->r;
            }
        }
        *idx=x;
        x->l=x->r=NULL;
        x->p=cur,x->key=num;
        splay(x);
    }
    int _find(int num)
    {
        node *x;
        if(root==NULL)
            return 0;
        node *cur=root;
        while(1)
        {
            if(num==cur->key) return 1;
            if(num<cur->key)
            {
                if(cur->l==NULL)
                    break;
                else cur=cur->l;
            }
            else
            {
                if(cur->r==NULL)
                    break;
                else cur=cur->r;
            }
        }
        splay(x);
        return num==cur->key;
    }
    void _delete(int key)
    {
        if(_find(key)==0) return;    //여기서 삭제해야할 정점이 splay되어 루트 노드가 됨.
        node *cur=root;
        if(cur->l!=NULL && cur->r!=NULL)
        {
            root=cur->l;
            root->p=NULL;
            node *temp=root;
            while(temp->r!=NULL) temp=temp->r;
            temp->r=cur->r;
            cur->r->p=temp;
        }
        else if(cur->l!=NULL)
        {
            root=cur->r;
            root->p=NULL;
        }
        else if(cur->r!=NULL)
        {
            root=cur->l;
            root->p=NULL;
        }
        else root=NULL;
        delete cur;
    }
    void kth(int num)
    {
        node *cur=root;
        push(cur);
        while(1)
        {
            while(cur->l!=NULL && cur->l->cnt>num)
            {
                cur=cur->l;
                push(cur);
            }
            if(cur->l!=NULL) num-=cur->l->cnt;
            if(num==0) break;
            num--;
            cur=cur->r;
            push(cur);
        }
        splay(cur);
    }
    node* gather(int s,int e)
    {
        kth(e+1);
        node *temp=root;
        kth(s-1);
        splay(temp,root);
        return root->r->l;
    }
    void flip(int s,int e)
    {
        node *cur=gather(s,e);
        (cur->flip)^=1;
    }
    void shift(int s,int e,int idx)
    {
        node *cur=gather(s,e);
        cout<<cur->mn<<" "<<cur->mx<<" "<<cur->sum<<'\n';
        if(idx>=0)
        {
            idx%=(e-s+1);
            if(idx==0) return;
            flip(s,e);
            flip(s,s+idx-1);
            flip(s+idx,e);
        }
        else
        {
            idx*=-1;
            idx%=(e-s+1);
            if(idx==0) return;
            flip(s,e);
            flip(s,e-idx);
            flip(e-idx+1,e);
        }
    }
    void get(int idx)
    {
        splay(ptr[idx]);
        cout<<root->l->cnt<<'\n';
    }
    void print(node *x)
    {
        push(x);
        if(x->l!=NULL) print(x->l);
        if(x->dummy==0) cout<<x->key<<' ';
        if(x->r) print(x->r);
    }
    void init()
    {
        memset(ptr,0,sizeof ptr);
        if(root!=NULL) delete root; 
        root=new node(-inf,nullptr);
        node *cur=root;
        for(int i=1;i<=n;i++)
        {
            ptr[i]=cur->r=new node(i,cur);
            cur=cur->r;
        }
        cur->r=new node(inf,cur);
        root->dummy=cur->r->dummy=1;
        for(int i=n;i>=1;i--) update(ptr[i]);
        splay(ptr[n/2]);
    }
}sptree;