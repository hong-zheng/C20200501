#ifndef __LIST_H__
#define __LIST_H__

/*
����һ��˫��ѭ������
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//  ��������
typedef int TypeData;

// �����ϵĽڵ�����
// һ�������ж���ǰ��ָ�룬��ǰ����
typedef struct LISTNODE{
	struct LISTNODE* _front;
	struct LISTNODE* _next;
	TypeData _data;
}ListNode;
// �����а���ͷβָ��
typedef struct LIST{
	ListNode* _head;
	ListNode* _rear;
}List;

ListNode* creatNode(TypeData data);
void InitList(List* ls);
// ͷ��
void pushFront(List* ls, TypeData data);
// β�� 
void pushBack(List* ls, TypeData data);
// print ����
void printLinkList(List* ls);

// ͷɾ
void popFront(List* ls); 
// βɾ
void popBack(List* ls); 

// ͳ�������е�Ԫ�ظ���
size_t size(List* ls);
#endif //__LIST_H__