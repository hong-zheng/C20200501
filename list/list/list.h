#ifndef __LIST_H__
#define __LIST_H__

/*
定义一个双向循环链表
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//  数据类型
typedef int TypeData;

// 链表上的节点类型
// 一个链表中定义前后指针，当前数据
typedef struct LISTNODE{
	struct LISTNODE* _front;
	struct LISTNODE* _next;
	TypeData _data;
}ListNode;
// 链表中包含头尾指针
typedef struct LIST{
	ListNode* _head;
	ListNode* _rear;
}List;

ListNode* creatNode(TypeData data);
void InitList(List* ls);
// 头插
void pushFront(List* ls, TypeData data);
// 尾插 
void pushBack(List* ls, TypeData data);
// print 链表
void printLinkList(List* ls);

// 头删
void popFront(List* ls); 
// 尾删
void popBack(List* ls); 

// 统计链表中的元素个数
size_t size(List* ls);
#endif //__LIST_H__