#include<iostream>
using namespace std;

struct Node//链表定义
{
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
Node *createLink(int *a, int len);//创建链表
Node *insertNode(Node *list, int value, int index);//在第index位置插入一个值为value的结点
Node *deleteNode(Node *list, int value);//删除一个结点值为value的结点
Node *reverseLink(Node *list);//链表逆制
Node *merge(Node *list1,Node *list2);//合并两个有序的链表
void updateNode(Node *list1,int index,int update);//将链表中值为index更新为update
void listLen(Node *list);//打印链表长度

Node *createLink(int *a, int len) {//头结点插入法，头结点为空
	Node *head, *pre, *cur;
	head = (Node*)malloc(sizeof(Node));//增加一个空头结点，使链表在头结点后建立
	head->data = -1;
	pre = head;
	for (int i = 0; i < len; i++) {//循环数组建立链表
		cur = (Node*)malloc(sizeof(Node));
		cur->data = a[i];
		pre->next = cur;//原链表后加入新的结点
		pre = pre->next;//原链表移至链表最后元素
	}
	pre = head->next;
	free(head);//释放空头结点的存储空间，后面的free函数都是一样的，不在赘述
	return pre;
}
Node *insertNode(Node *list, int value, int index) {//在第index位置插入一个值为value的结点
	Node *head, *pre, *in;
	head = (Node*)malloc(sizeof(Node));//增加一个空头结点，使链表在头结点前插入无需例外处理，后面也有同样的操作，就不在赘述
	in = (Node*)malloc(sizeof(Node));//定义将要插入的结点并且分配空间
	in->data = value;
	head->data = -1;
	head->next = list;//空头结点接入链表
	pre = head;
	int i = 0;
	while (i < index) {//遍历链表至第index个位置
		pre = pre->next;//pre为要插入结点的前一个结点
		list = list->next;
		i++;
	}
	in->next = list;
	pre->next = in;
	pre = head->next;
	free(head);
	return pre;
}
Node *deleteNode(Node *list, int value) {//删除结点值为value的结点
	if (list == NULL) return NULL;
	Node *head, *pre;
	head = (Node*)malloc(sizeof(Node));
	head->data = -1;
	head->next = list;
	pre = head;
	while (list != NULL && list->data != value) {
		pre = pre->next;
		list = list->next;
	}
	pre->next = list->next;
	pre = head->next;
	free(list);//释放删除的结点的空间
	free(head);
	return pre;
}
Node *reverseLink(Node *list) {//链表逆制
	if (list == NULL || list->next == NULL) return list;//如果链表为空或者只有一个结点时，直接返回
	Node *rev = NULL;//新链表，最开始为空
	while (list != NULL) {
		Node *temp = list->next;//临时变量存储结点值
		list->next = rev;//从头结点前接入原链表的结点
		rev = list;//新链表头结点更新至元头结点的前一个结点
		list = temp;//原链表移至后一个结点
	}
	return rev;//返回新链表头结点
}
Node *merge(Node *list_a, Node *list_b) {//合并链表list_a和链表list_b，顺序为递增
	Node *head, *pre;
	head = (Node*)malloc(sizeof(Node));
	head->data = -1;
	pre = head;
	while (list_a != NULL && list_b != NULL) {
		if (list_a->data < list_b->data) {//将数值小的结点接入新链表中
			pre->next = list_a;
			list_a = list_a->next;
		}
		else {
			pre->next = list_b;
			list_b = list_b->next;
		}
		pre = pre->next;
	}
	if (list_a != NULL) {//将链表list_a中剩余结点接入新链表尾部
		pre->next = list_a;
	}
	if (list_b != NULL) {//将链表list_b中剩余结点接入新链表尾部
		pre->next = list_b;
	}
	pre = head->next;
	free(head);
	return pre;
}
void updateNode(Node *list, int index, int update) {//将链表中值为index更新为update
	if (list == NULL) return;
	while (list != NULL) {
		if (list->data == index) {//判断结点值是否相等
			list->data = update;
		}
		list = list->next;
	}
}
void listLen(Node *list) {//遍历链表计算链表长度
	int len = 0;//len存储链表长度
	while (list != NULL) {
		len++;
		list = list->next;
	}
	printf("链表长度为：%d\n", len);
}
void output(Node *head) {
	if (head == NULL) {//链表为空时打印空
		printf("链表为空");
		return;
	}
	while (head != NULL) {
		printf("%d", head->data);
		if (head->next != NULL) printf(" ");
		head = head->next;
	}
	printf("\n");
}
int main()
{
	int a[6] = { 0,2,4,6,8,10 };
	int b[8] = { 1,3,5,7,9,11,13,15 };
	int index = 0;
	int len_a = (sizeof(a) / sizeof(int));//计算出数组的长度
	int len_b = (sizeof(b) / sizeof(int));

	Node *head_a = createLink(a, len_a);//创建链表
	printf("创建链表:");
	output(head_a);

	head_a = deleteNode(head_a, index);//结点删除
	printf("删除节点为%d的结点：", index);
	output(head_a);

	head_a = insertNode(head_a, 0, 0);//结点插入
	printf("插入节点为%d的结点：", index);
	output(head_a);

	head_a = reverseLink(head_a);//逆制链表
	printf("逆制后的链表为：");
	output(head_a);

	head_a = reverseLink(head_a);
	Node *head_b = createLink(b, len_b);//创建数组b的链表
	printf("合并两个链表");
	Node *head = merge(head_a, head_b);
	output(head);

	listLen(head);//打印链表长度

	updateNode(head, 13, 14);//将链表中值为13的结点更新为14
	printf("结点更新后的链表为：");
	output(head);

	return 0;
}