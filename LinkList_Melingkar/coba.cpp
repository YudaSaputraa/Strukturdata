#include <stdio.h>
#include <malloc.h>

typedef struct typenode *typeptr;
typedef struct typenode{ int info;
typeptr next; };
int main()
{ int a=50;
typeptr p,q,r;
p=(typenode *) malloc(sizeof(typenode));
q=(typenode *) malloc(sizeof(typenode));
r=(typenode *) malloc(sizeof(typenode));
p->info=a; r->next=p; p=q; q->info=90;
printf ("p->info = %d\n", p->info);
printf ("r->next = %d\n", r->next);
printf ("p = %d\n",p);
printf ("q->next = %d\n",q->info);
p->info=2 * r->next->info - 5;
r->info=q->info; q=r->next; q->next=p;
p->next=r->next; a=q->next->info + q->info - a;
printf("p->next->next->info = %d\n",p->next->next->info);
printf("q->next->info = %d\n",q->next->info);
printf("r->info = %d\n",r->info);
printf("a = %d",a);
}