//linked_list.c
#include <stdio.h>
#include <malloc.h>

typedef struct {
	int number;
	struct node* p_next; //다음 노드를 가리킬 포인터
}Node;

void AddNumber(Node **pp_head, Node **pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (Node*)malloc(sizeof(Node)); // 새 노드를 할당
		*pp_tail = (*pp_tail)->p_next; //p-tail(*pp_tail) 에 새 노드의 주소 값을 저장

	}
	else {
		//*p_head값이 NULL이라서 첫 노드가 추가됨. p_head값에 직접 대입함.
		*pp_head = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head; //새 노드의 주소값을 p_tail(*pp_tail)에 저장함.
	}
	(*pp_tail)->number = data;// 새 노드의 number에 data값을 저장
	(*pp_tail)->p_next = NULL; //다음 노드가 없음을 명시함.
}

int main(void) {
	//노드의 시작과 끝을 기억할 포인터
	Node* p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	//무한루프: 중간에 9999를 누르면 종료함.
	while (1) {
		printf("숫자를 입력하세요 (9999를 누르면 종료): ");
		scanf_s("%d", &temp);

		if (9999 == temp) break;

		//노드의 시작과 끝을 기억하는 포인터에 주소 값과 입력된 숫자를 전달
		AddNumber(&p_head, &p_tail, temp);
	}

	//입력된 숫자를 출력하기 위해서 노드를 탐색할 포인터에 시작노드의 주소 값을 대입함.
	p = p_head;
	while (NULL != p) {
		if (p != p_head) 
			printf(" + "); //숫자와 숫자 사이에 + 출력

		printf("%d", p->number);

		sum = sum + p->number; //sum + = p->number 하면...?
		p = p->p_next; //다음 노드로 이동
	}
	printf(" = %d\n", sum);

	//사용한 모든 노드를 삭제함.
	while (NULL != p_head) {
		p = p_head; //현재 노드를 삭제하기 위해 p 변수에 노드주소값을 저장
		p_head = p_head->p_next; //시작 위치를 다음 노드로 옮김

		free(p);//기억했던 주소를 사용하여 노드를 삭제함.
	}
	p_tail = p_head; //반복문이 나오면 p_head값은 NULL, p_tail 값도 NULL로 변경

	return 0;
}