#include<iostream>
using namespace std;

struct Node//������
{
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
Node *createLink(int *a, int len);//��������
Node *insertNode(Node *list, int value, int index);//�ڵ�indexλ�ò���һ��ֵΪvalue�Ľ��
Node *deleteNode(Node *list, int value);//ɾ��һ�����ֵΪvalue�Ľ��
Node *reverseLink(Node *list);//��������
Node *merge(Node *list1,Node *list2);//�ϲ��������������
void updateNode(Node *list1,int index,int update);//��������ֵΪindex����Ϊupdate
void listLen(Node *list);//��ӡ������

Node *createLink(int *a, int len) {//ͷ�����뷨��ͷ���Ϊ��
	Node *head, *pre, *cur;
	head = (Node*)malloc(sizeof(Node));//����һ����ͷ��㣬ʹ������ͷ������
	head->data = -1;
	pre = head;
	for (int i = 0; i < len; i++) {//ѭ�����齨������
		cur = (Node*)malloc(sizeof(Node));
		cur->data = a[i];
		pre->next = cur;//ԭ���������µĽ��
		pre = pre->next;//ԭ���������������Ԫ��
	}
	pre = head->next;
	free(head);//�ͷſ�ͷ���Ĵ洢�ռ䣬�����free��������һ���ģ�����׸��
	return pre;
}
Node *insertNode(Node *list, int value, int index) {//�ڵ�indexλ�ò���һ��ֵΪvalue�Ľ��
	Node *head, *pre, *in;
	head = (Node*)malloc(sizeof(Node));//����һ����ͷ��㣬ʹ������ͷ���ǰ�����������⴦������Ҳ��ͬ���Ĳ������Ͳ���׸��
	in = (Node*)malloc(sizeof(Node));//���彫Ҫ����Ľ�㲢�ҷ���ռ�
	in->data = value;
	head->data = -1;
	head->next = list;//��ͷ����������
	pre = head;
	int i = 0;
	while (i < index) {//������������index��λ��
		pre = pre->next;//preΪҪ�������ǰһ�����
		list = list->next;
		i++;
	}
	in->next = list;
	pre->next = in;
	pre = head->next;
	free(head);
	return pre;
}
Node *deleteNode(Node *list, int value) {//ɾ�����ֵΪvalue�Ľ��
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
	free(list);//�ͷ�ɾ���Ľ��Ŀռ�
	free(head);
	return pre;
}
Node *reverseLink(Node *list) {//��������
	if (list == NULL || list->next == NULL) return list;//�������Ϊ�ջ���ֻ��һ�����ʱ��ֱ�ӷ���
	Node *rev = NULL;//�������ʼΪ��
	while (list != NULL) {
		Node *temp = list->next;//��ʱ�����洢���ֵ
		list->next = rev;//��ͷ���ǰ����ԭ����Ľ��
		rev = list;//������ͷ��������Ԫͷ����ǰһ�����
		list = temp;//ԭ����������һ�����
	}
	return rev;//����������ͷ���
}
Node *merge(Node *list_a, Node *list_b) {//�ϲ�����list_a������list_b��˳��Ϊ����
	Node *head, *pre;
	head = (Node*)malloc(sizeof(Node));
	head->data = -1;
	pre = head;
	while (list_a != NULL && list_b != NULL) {
		if (list_a->data < list_b->data) {//����ֵС�Ľ�������������
			pre->next = list_a;
			list_a = list_a->next;
		}
		else {
			pre->next = list_b;
			list_b = list_b->next;
		}
		pre = pre->next;
	}
	if (list_a != NULL) {//������list_a��ʣ�������������β��
		pre->next = list_a;
	}
	if (list_b != NULL) {//������list_b��ʣ�������������β��
		pre->next = list_b;
	}
	pre = head->next;
	free(head);
	return pre;
}
void updateNode(Node *list, int index, int update) {//��������ֵΪindex����Ϊupdate
	if (list == NULL) return;
	while (list != NULL) {
		if (list->data == index) {//�жϽ��ֵ�Ƿ����
			list->data = update;
		}
		list = list->next;
	}
}
void listLen(Node *list) {//�����������������
	int len = 0;//len�洢������
	while (list != NULL) {
		len++;
		list = list->next;
	}
	printf("������Ϊ��%d\n", len);
}
void output(Node *head) {
	if (head == NULL) {//����Ϊ��ʱ��ӡ��
		printf("����Ϊ��");
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
	int len_a = (sizeof(a) / sizeof(int));//���������ĳ���
	int len_b = (sizeof(b) / sizeof(int));

	Node *head_a = createLink(a, len_a);//��������
	printf("��������:");
	output(head_a);

	head_a = deleteNode(head_a, index);//���ɾ��
	printf("ɾ���ڵ�Ϊ%d�Ľ�㣺", index);
	output(head_a);

	head_a = insertNode(head_a, 0, 0);//������
	printf("����ڵ�Ϊ%d�Ľ�㣺", index);
	output(head_a);

	head_a = reverseLink(head_a);//��������
	printf("���ƺ������Ϊ��");
	output(head_a);

	head_a = reverseLink(head_a);
	Node *head_b = createLink(b, len_b);//��������b������
	printf("�ϲ���������");
	Node *head = merge(head_a, head_b);
	output(head);

	listLen(head);//��ӡ������

	updateNode(head, 13, 14);//��������ֵΪ13�Ľ�����Ϊ14
	printf("�����º������Ϊ��");
	output(head);

	return 0;
}