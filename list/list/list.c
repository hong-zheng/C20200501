#include "list.h"

// 创建一个节点
ListNode* creatNode(TypeData data){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = data;
	// 目前创建的前后指针都指向NULL
	node->_front = node->_next = NULL;
	return node;
}
// 初始化链表,当前初始化的链表为一个空链表
void InitList(List* ls){
	// 空链表首尾指针都指向NULL，无任何数据
	ls->_head = ls->_rear = NULL;
}

// 头插
void pushFront(List* ls, TypeData data){
	ListNode* node = creatNode(data);
	if (ls->_head == NULL && ls->_rear == NULL){ // 没有头节点
		ls->_head = ls->_rear = node;
		ls->_head->_next = ls->_head;
		ls->_head->_front = ls->_rear;
		ls->_rear->_next = ls->_head;
		ls->_rear->_front = ls->_head;
	}
	else{ // 有头节点
		node->_next = ls->_head;
		ls->_head->_front = node;
		ls->_head = node;

		ls->_head->_front = ls->_rear;
		ls->_rear->_next = ls->_head;
	}
}

// 尾插 
void pushBack(List* ls, TypeData data){
	ListNode* node = creatNode(data);
	if (ls->_head == NULL && ls->_rear == NULL){
		ls->_head = ls->_rear = node;
		ls->_head->_next = ls->_head;
		ls->_head->_front = ls->_rear;

		ls->_rear->_front = ls->_head;
		ls->_rear->_next = ls->_head;
	}
	else{ // 有头节点的时候
		ls->_rear->_next = node;
		node->_front = ls->_rear;
		node->_next = ls->_head;
		ls->_head->_front = node;
		ls->_rear = node;
	}
}

// 头删
void popFront(List* ls){
	if (ls->_head == NULL){
		return;
	}
	// 需要考虑最后删掉之后为一个元素的情况的尾指针指向

	// 只有一个元素的情况,需要判断首元素的后一个元素是否为首元素
	if (ls->_head->_next == ls->_head){
		ls->_head->_front = NULL;
		ls->_head->_next = NULL;
		free(ls->_head);
		ls->_head = ls->_rear = NULL;
		return;
	}
	// 此处的next为NULL已经排除
	ListNode* next = ls->_head->_next;
	free(ls->_head);
	ls->_head = next;
	ls->_head->_front = ls->_rear;
	ls->_rear->_next = ls->_head;
}
// print 链表
void printLinkList(List* ls){
	if (ls->_head == NULL) {
		printf("链表为空\n");
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

// 尾删
void popBack(List* ls){
	// 判空
	if (ls->_head == NULL)
		return;
	// 只有一个元素的情况
	if (ls->_head->_next == ls->_head){
		free(ls->_head);
		ls->_head = ls->_rear = NULL;
		return;
	}
	// 一般情况
	ListNode* rear = ls->_head->_front;
	ListNode* cur = rear->_front;
	free(rear);
	cur->_next = ls->_head;
	ls->_head->_front = cur;
}

// 统计链表中的元素个数
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