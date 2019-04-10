#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node* next;
};

Node *build(int *a,int n){
	Node *pre,*cur;
	Node *head=new Node();//ÐÂ½¨Ò»¸ö¿ÕÍ·½áµã
	head->val=-1;
	head->next=NULL;//Í·½áµãºóÖÃ¿Õ
	pre=head;//±£´æ¿ÕÍ·½áµã
	for(int i=0;i<n;i++){
		cur=new Node();
		cur->val=a[i];//½«Êý×éÔªËØÖÃÈë½áµãÖÐ
		cur->next=NULL;
		pre->next=cur;//Ç°Ò»¸ö½áµãµÄºóÖÃ½ÓÈëÐÂµÄ½áµã
		pre=pre->next;//½áµãºóÒÆ£¬Ê¹Á´±í×îºóµÄºóÖÃÎª¿Õ
	}
	pre=head->next;//·µ»Ø¿ÕÍ·½áµãµÄºóµÄµÚÒ»¸ö½áµã
	delete head;
	return pre;
}
void deleteNode(Node *head,int x){
	Node *pre,*cur;
	pre=new Node();
	pre->val=-1;
	pre->next=head;
	cur=pre;
	while(head->next!=NULL){
		if(head->val!=x){
			head=head->next;
			cur=cur->next;
		}
		else{
			head=head->next;
			cur->next=head;
		}

	}
}
//´òÓ¡Á´±í£¬Á´±íÔªËØ¼äÓÐÒ»¸ö¿Õ¸ñ£¬Ä©Î²Ã»ÓÐ¿Õ¸ñ
void print(Node *pre){
	while(pre!=NULL){
		printf("%d", pre->val);
		if(pre->next!=NULL)printf(" ");
		pre=pre->next;
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int *a=new int(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	Node *pre=build(a,n);
	print(pre);
	deleteNode(pre,3);
	print(pre);

	return 0;
}
