#include"lx.h"
#include"lxerror.h"
#include"stack.h"

//disk_alloc��λͼ���޸Ľ���Ԥ�ȴ�������
//i��λͼλ�ã�blocks������
tree_error dalloc_bmp_spush(uint32 i, uint32 blocks)
{
	S_Push(dalloc_BMP, (S_ElementType)i);
	dalloc_BMP_sp++;
	S_Push(dalloc_BMP, (S_ElementType)blocks);
	dalloc_BMP_sp++;
	return 0;
}

//�����Ķ���λͼ������ջ
tree_error DataBMP_Stack_Push(uint32 n)
{
	tree_error err = S_FindStack((S_ElementType)n, DataBMP_Stack);
	if (err == ERR_NOT_FOUND_NUM_IN_STACK) {
		S_Push(DataBMP_Stack, (S_ElementType)n); 
		DataBMP_Stack_sp++;
	}
	return 0;
}