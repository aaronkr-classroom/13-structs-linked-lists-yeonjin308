//linked_list.c
#include <stdio.h>
#include <malloc.h>

typedef struct {
	int number;
	struct node* p_next; //���� ��带 ����ų ������
}Node;

void AddNumber(Node **pp_head, Node **pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (Node*)malloc(sizeof(Node)); // �� ��带 �Ҵ�
		*pp_tail = (*pp_tail)->p_next; //p-tail(*pp_tail) �� �� ����� �ּ� ���� ����

	}
	else {
		//*p_head���� NULL�̶� ù ��尡 �߰���. p_head���� ���� ������.
		*pp_head = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head; //�� ����� �ּҰ��� p_tail(*pp_tail)�� ������.
	}
	(*pp_tail)->number = data;// �� ����� number�� data���� ����
	(*pp_tail)->p_next = NULL; //���� ��尡 ������ �����.
}

int main(void) {
	//����� ���۰� ���� ����� ������
	Node* p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	//���ѷ���: �߰��� 9999�� ������ ������.
	while (1) {
		printf("���ڸ� �Է��ϼ��� (9999�� ������ ����): ");
		scanf_s("%d", &temp);

		if (9999 == temp) break;

		//����� ���۰� ���� ����ϴ� �����Ϳ� �ּ� ���� �Էµ� ���ڸ� ����
		AddNumber(&p_head, &p_tail, temp);
	}

	//�Էµ� ���ڸ� ����ϱ� ���ؼ� ��带 Ž���� �����Ϳ� ���۳���� �ּ� ���� ������.
	p = p_head;
	while (NULL != p) {
		if (p != p_head) 
			printf(" + "); //���ڿ� ���� ���̿� + ���

		printf("%d", p->number);

		sum = sum + p->number; //sum + = p->number �ϸ�...?
		p = p->p_next; //���� ���� �̵�
	}
	printf(" = %d\n", sum);

	//����� ��� ��带 ������.
	while (NULL != p_head) {
		p = p_head; //���� ��带 �����ϱ� ���� p ������ ����ּҰ��� ����
		p_head = p_head->p_next; //���� ��ġ�� ���� ���� �ű�

		free(p);//����ߴ� �ּҸ� ����Ͽ� ��带 ������.
	}
	p_tail = p_head; //�ݺ����� ������ p_head���� NULL, p_tail ���� NULL�� ����

	return 0;
}