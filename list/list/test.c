#include "list.h"
void test(){
	List ls;
	InitList(&ls);
	printf("头插:>\n");
	pushFront(&ls, 1);
	printLinkList(&ls);
	pushFront(&ls, 3);
	printLinkList(&ls);

	popFront(&ls);
	printLinkList(&ls);
	popFront(&ls);
	printLinkList(&ls);

	pushFront(&ls, 12);
	printLinkList(&ls);

	pushFront(&ls, 13);
	printLinkList(&ls);
	pushFront(&ls, 4);
	printLinkList(&ls);
	printf("尾插:>\n");
	pushBack(&ls, 89);
	printLinkList(&ls);
	pushBack(&ls, 1);
	printLinkList(&ls);
	pushBack(&ls, 34);
	printLinkList(&ls);
	pushBack(&ls, 56);
	printLinkList(&ls);
	printf(" 当前链表中元素个数为: [%u]\n", size(&ls));
	popFront(&ls);
	printLinkList(&ls);
	
	popBack(&ls);
	printLinkList(&ls);
	printf(" 当前链表中元素个数为: [%u]\n", size(&ls));
	popBack(&ls);
	printLinkList(&ls);
	popBack(&ls);
	printLinkList(&ls);
	popBack(&ls);
	printLinkList(&ls);
	popBack(&ls);
	printLinkList(&ls);
	popBack(&ls);
	printLinkList(&ls);


}
int main(void){
	test();
	system("pause");
	return 0;
}