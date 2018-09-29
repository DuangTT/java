#include <iostream>
using namespace std;
class ListNode
{
public:
    int data1, data2;
    ListNode *next;
    ListNode()
    {
        next = NULL;
    }
};
class linklist
{
public:
    ListNode *head;
    int len;
    linklist()
    {
        head = new ListNode;
        len = 0;
    }
    linklist &operator=(const linklist &r)
    {
        int i;
        ListNode *p = new ListNode;
        head = new ListNode;
        p = head;
        len = r.len;
        for(i = 0; i < len; i++)
        {
            ListNode *q = new ListNode;
            p->next = q;
            q->next = NULL;
        }
        return *this;
    }
    ~linklist()
    {
        ListNode *p, *q;
        p = head;
        while(p)
        {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }
    void createlist(int n)
    {
        int i;
        ListNode *q = head;
        int d1, d2;
        for(i = 0; i < n; i++)
        {
            cin >> d1 >> d2;
            ListNode *p = new ListNode;
            p->data1 = d1;
            p->data2 = d2;
            q->next = p;
            p->next = NULL;
            q = p;
        }
        len = n;
    }
    void display()
    {
        int i;
        ListNode *p = head->next;
        for(i = 0; i < len; i++)
        {
            if(p->data1 == 0)
            {
                p = p->next;
                continue;
            }
            else if(p->data2 == 0)
            {
                if(p->data1 < 0)
                    cout << "(" << p->data1 << ")";
                else
                    cout << p->data1;
                p = p->next;
            }
            else
            {
                if(p->data1 < 0)
                    cout << "(" << p->data1 << ")x^";
                else
                    cout << p->data1 << "x^";
                if(p->data2 < 0)
                    cout << "(" << p->data2 << ")";
                else
                    cout << p->data2;
                p = p->next;
            }
            if(i != len-1)
                cout << " + ";
        }
        cout << endl;
    }
    linklist *add(linklist *q)
    {
        ListNode *pre = head;
        ListNode *p1 = head->next;
        ListNode *p2 = q->head->next;
        while(p1 != NULL && p2 != NULL)
        {
            if(p1->data2 < p2->data2)
            {
                p1 = p1->next;
                pre = pre->next;
            }
            else if(p1->data2 > p2->data2)
            {
                ListNode *r = new ListNode;
                r->next = pre->next;
                pre->next = r;
                r->data1 = p2->data1;
                r->data2 = p2->data2;
                p2 = p2->next;
                q->len--;
            }
            else
            {
                p1->data1 = p1->data1+p2->data1;
                p1 = p1->next;
                p2 = p2->next;
                pre = pre->next;
                q->len--;
            }
        }
        if(p2 != NULL)
        {
            pre->next = p2;
            len += q->len;
        }
        return this;
    }
    ListNode *index(int i)
    {
        int k;
        ListNode *p = head;
        if(i != 0)
        {
            for(k = 1; k < i; k++)
            {
                p = p->next;
            }
            return p->next;
        }
        else
        {
            return head;
        }
    }
};
int main()
{
    int T, n, m;
     
    linklist *l3 = NULL;
    cin >> T;
    while(T--)
    {
        linklist *l1 = new linklist,*l2 = new linklist;
        cin >> n;
        l1->createlist(n);
        cin >> m;
        l2->createlist(m);
        l1->display();
        l2->display();
        l3 = l1->add(l2);
        l3->display();
        delete l1,l2;
    }
    return 0;
}
