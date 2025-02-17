/* Program to add two polynomials using linked list */

#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
#define  NULL  0

/*I have compiled this program on Turbo C++ compiler which does not support a float or double member in a structure. If your compiler supports a float member in a structure then change the member c to data type float */

struct  node
{
  int  c ;
  int  pw ;
  struct  node  *next ;
} ;

struct  node  *first1 , *first2 , *first3 ;

void  create(int  flag)
{
  int  i , n ;
  struct  node  *pnode , *p ;

  struct  node  *first=NULL ;

  printf("Enter the number of terms in the polynomial:") ;
  scanf("%d",&n) ;

  printf("Enter the co-efficient and power of each term (higher to lower order): \n") ;
  for(i=1 ; i<=n ; i++)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;
    scanf("%d %d", &pnode->c , &pnode->pw) ;
    pnode->next=NULL ;   /* New node will be the last node */

    if(first==NULL)
	 first=p=pnode ;
    else
    {
	 p->next=pnode ;
	 p=pnode ;    /* p keeps track of last node */
    }
  }

  if(flag==1)
    first1=first;
  if(flag==2)
    first2=first;
}

void  add()
{
  struct  node  *p , *p1 , *p2 , *pnode ;

  if(first1==NULL&&first2==NULL)
    return ;

  p1=first1 ;
  p2=first2 ;

  /* Elements remaining in polynomial 1 and 2 */
  while(p1!=NULL&&p2!=NULL)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;
    pnode->next=NULL ;

    if(first3==NULL)
	 first3=p=pnode ;
    else
    {
	  p->next=pnode ;
	  p=pnode ;
    }

    if(p1->pw==p2->pw)
    {
	  p->c=p1->c + p2->c ;
	  p->pw=p1->pw ;
	  p1=p1->next ;
	  p2=p2->next ;
    }
    else if(p1->pw>p2->pw)
    {
	  p->c=p1->c ;
	  p->pw=p1->pw ;
	  p1=p1->next ;
    }
    else
    {
	  p->c=p2->c ;
	  p->pw=p2->pw ;
	  p2=p2->next ;
    }
  }

  /* Elements remaining in polynomial 1 but not 2 */
  while(p1!=NULL)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;
    pnode->next=NULL ;

    if(first3==NULL)
	first3=p=pnode ;
    else
    {
	  p->next=pnode ;
	  p=pnode ;
    }

    p->c=p1->c ;
    p->pw=p1->pw ;

    p1=p1->next ;
  }

  /* Elements remaining in polynomial 2 but not 1 */
  while(p2!=NULL)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;
    pnode->next=NULL ;

    if(first3==NULL)
	first3=p=pnode ;
    else
    {
	  p->next=pnode ;
	  p=pnode ;
    }

    p->c=p2->c ;
    p->pw=p2->pw ;

    p2=p2->next ;
  }

}

void  traverse(struct  node  *first)
{
  struct node *p ;
  if(first==NULL)
    printf("Polynomial Empty. \n") ;
  else
  {
    p=first ;
    while(p->next!=NULL)
    {
      printf("%dx^%d + ",p->c,p->pw) ;
      p=p->next ;
    }
    printf("%dx^%d",p->c,p->pw) ;
    printf("\n") ;
  }
}

void main()
{
  first1 = first2 = first3 = NULL ;

  clrscr() ;

  printf("Creating First polynomial:\n") ;
  create(1) ;
  traverse(first1) ;

  printf("Creating Second polynomial:\n") ;
  create(2) ;
  traverse(first2) ;

  printf("Sum of two polynomials is:\n") ;
  add() ;
  traverse(first3) ;

  getch() ;
}

    








