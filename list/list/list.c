#include "list.h"

// ����һ���ڵ�
ListNode* creatNode(TypeData data){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = data;
	// Ŀǰ������ǰ��ָ�붼ָ��NULL
	node->_front = node->_next = NULL;
	return node;
}
// ��ʼ������,��ǰ��ʼ��������Ϊһ��������
void InitList(List* ls){
	// ��������βָ�붼ָ��NULL�����κ�����
	ls->_head = ls->_rear = NULL;
}

// ͷ��
void pushFront(List* ls, TypeData data){
	ListNode* node = creatNode(data);
	if (ls->_head == NULL && ls->_rear == NULL){ // û��ͷ�ڵ�
		ls->_head = ls->_rear = node;
		ls->_head->_next = ls->_head;
		ls->_head->_front = ls->_rear;
		ls->_rear->_next = ls->_head;
		ls->_rear->_front = ls->_head;
	}
	else{ // ��ͷ�ڵ�
		node->_next = ls->_head;
		ls->_head->_front = node;
		ls->_head = node;

		ls->_head->_front = ls->_rear;
		ls->_rear->_next = ls->_head;
	}
}

// β�� 
void pushBack(List* ls, TypeData data){
	ListNode* node = creatNode(data);
	if (ls->_head == NULL && ls->_rear == NULL){
		ls->_head = ls->_rear = node;
		ls->_head->_next = ls->_head;
		ls->_head->_front = ls->_rear;

		ls->_rear->_front = ls->_head;
		ls->_rear->_next = ls->_head;
	}
	else{ // ��ͷ�ڵ��ʱ��
		ls->_rear->_next = node;
		node->_front = ls->_rear;
		node->_next = ls->_head;
		ls->_head->_front = node;
		ls->_rear = node;
	}
}

// ͷɾ
void popFront(List* ls){
	if (ls->_head == NULL){
		return;
	}
	// ��Ҫ�������ɾ��֮��Ϊһ��Ԫ�ص������βָ��ָ��

	// ֻ��һ��Ԫ�ص����,��Ҫ�ж���Ԫ�صĺ�һ��Ԫ���Ƿ�Ϊ��Ԫ��
	if (ls->_head->_next == ls->_head){
		ls->_head->_front = NULL;
		ls->_head->_next = NULL;
		free(ls->_head);
		ls->_head = ls->_rear = NULL;
		return;
	}
	// �˴���nextΪNULL�Ѿ��ų�
	ListNode* next = ls->_head->_next;
	free(ls->_head);
	ls->_head = next;
	ls->_head->_front = ls->_rear;
	ls->_rear->_next = ls->_head;
}
// print ����
void printLinkList(List* ls){
	if (ls->_head == NULL) {
		printf("����Ϊ��\n");
		return;
	}
	ListNode* cur = ls->_head;
	do{
		ListNode* next = cur->_next;
		printf("%d ", cur->_data);
		cur = next;
	} while (cur != ls->_head);
	printf("\n");
}

// βɾ
void popBack(List* ls){
	// �п�
	if (ls->_head == NULL)
		return;
	// ֻ��һ��Ԫ�ص����
	if (ls->_head->_next == ls->_head){
		free(ls->_head);
		ls->_head = ls->_rear = NULL;
		return;
	}
	// һ�����
	ListNode* rear = ls->_head->_front;
	ListNode* cur = rear->_front;
	free(rear);
	cur->_next = ls->_head;
	ls->_head->_front = cur;
}

// ͳ�������е�Ԫ�ظ���
size_t size(List* ls){
	if (ls->_head == NULL){
		return 0;
	}
	ListNode* cur = ls->_head;
	int cnt = 0;
	do{
		++cnt;
		cur = cur->_next;
	} while (cur != ls->_head);
	return cnt;
}