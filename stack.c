#include"stack.h"

static int stack_sp;//��ջָ��
static int stack_max_size;//��ջ�������

//������ջ�������ض�ջָ��
Stack S_CreateStack(int MaxSize)
{
	Stack s = (Stack)malloc(MaxSize * sizeof(S_ElementType));
	stack_sp = 0;
	stack_max_size = MaxSize;
	return s;
}

//�ж϶�ջ�Ƿ�����
char S_IsFull(Stack s)
{
	if (stack_sp >= stack_max_size) { return 1; }
	return 0;
}

//ѹջ
char S_Push(Stack s, S_ElementType x)
{
	if (S_IsFull)return 0;
	s[stack_sp++] = x;
	return 1;
}

//�ж϶�ջ�Ƿ�Ϊ��
char S_IsEmpty(Stack s)
{
	if (stack_sp <= 0)return 1;
	return 0;
}

//��ջ
S_ElementType S_Pop(Stack s)
{
	if (S_IsEmpty)return 0;
	return s[stack_sp--];
}

//�رն�ջ
void S_CloseStack(Stack s)
{
	free(s);
	stack_sp = 0;
	stack_max_size = 0;
}

//��ջ����
int S_FindStack(S_ElementType n, Stack s)
{
	for (int i = 0; i < stack_sp; ++i) {
		if (s[i] == n)return i;
	}
	return ERR_NOT_FOUND_NUM_IN_STACK;
}