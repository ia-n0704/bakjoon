#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	char key;
	struct node* prev;
    struct node* next;
}node;
node* head, *tail, *p;
void init()
{
    head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
	p = head;
}
void left() {
	if (p != head)
		p = p->prev;
}
void right()
{
	if (p != tail->prev)
		p = p->next;
}
void _delete()
{
	if (p != head)
    {
		node* t = p; 
		p = p->prev;
		p->next = t->next;
		t->next->prev = p;
		free(t);
	}
}
void insert(char c)
{
	node* n = (node*)malloc(sizeof(node));
	n->key = c;
	n->prev = p;
	n->next = p->next;
	p->next->prev = n;
	p->next = n;
	p = n;
}
void print()
{
	node* cur = head->next;
	for(;cur!=tail;cur=cur->next)
		cout<<cur->key;
}
int main()
{
    string s;
    cin>>s;
    init();
    for(int i=0;i<s.length();i++)
        insert(s[i]);
	int n;
    cin>>n;
	while(n--)
    {
        char a;
        char c;
		cin>>a;
		if (a=='P')
        {
			cin>>c;
			insert(c);
		}
		else if(a=='L')
			left();
		else if (a=='D')
			right();
		else
			_delete();
	}
	print();
}