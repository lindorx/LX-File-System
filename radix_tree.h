#pragma once
#include<stdlib.h>
#include<stdio.h>
//#define _RADIX_NDOE_PRINT	//��������˴˺꣬radix_tree_traversal()����������Ļ��ӡ�������

#define MEMPAGE 4096
#define INIT_POOL_SIZE (MEMPAGE*1)	//��ʼ�ڴ�ش�С
#define RADIX_INSERT_VALUE_OCCUPY -1		//�ýڵ��ѱ�ռ��
#define RADIX_INSERT_VALUE_SAME -2		//��������ͬ��ֵ
#define RADIX_DELETE_ERROR -3			//ɾ������
typedef unsigned int ptr_t;
typedef unsigned int uint32;

#define BITS 2
//����keyָ��λ��ֵ��λ����BITSָ��
#define CHECK_BITS(key,pos) (((unsigned int)((int)0-(int)1))>>(sizeof(char*)*8-BITS))&((unsigned long)(key)>>(BITS*(unsigned short)(pos)))
//#define CHECK_BITS(key,pos) ()
//�������ڵ�
typedef struct radix_node_t radix_node_t;
struct radix_node_t {
	radix_node_t* child[4];
	radix_node_t* parent;
};
typedef struct radix_leafnode_t {
	struct radix_leafnode_t* next;
	uint32 key;//·��
	ptr_t value;//ֵ
}radix_leafnode_t;

//�ڴ�ؽṹ�������ڴ�ص�ǰ��
typedef struct radix_pool {
	struct radix_pool* next;
	struct radix_pool* prev;
	char* start;
	size_t size;
}radix_pool, *pool_t;
//����������ṹ
typedef struct radix_tree_t {
	//ָ����ڵ�
	radix_node_t* root;
	//�ڴ��ָ�룬(һҳ�ڴ�)
	pool_t pool;
	//�����ѷ��䵫�������еĽڵ㣨˫���������ﴢ�����е�һ���ڵ㣩
	radix_node_t* free;
	//Ҷ�ڵ��ڴ��
	pool_t leafpool;
	//�����ѷ��䵫�������е�Ҷ�ڵ�
	radix_leafnode_t* lfree;
}radix_tree_t;

//�ڴ����������num�����ڴ�صĴ�С��=-1ʹ��Ĭ��ֵ,��λ��ҳ
pool_t get_new_pool(radix_tree_t* t, int num);

//����һ���ڵ㣬���ڴ����ȡ������ʹ�õĽڵ�
radix_node_t* radix_node_alloc(radix_tree_t* t);

//��������ṹ
radix_tree_t* radix_tree_create();

//����
int radix_tree_insert(radix_tree_t* t, uint32 key, ptr_t value);

//���ڲ���ʱ�ᴴ���ܶ�ڵ㣬Ϊ������ٶ�����ֻ��ɾ����ײ��ָ���ڵ�
int radix_tree_delete(radix_tree_t* t, uint32 key);

//��ӡ���������ӡ�����еײ�ڵ�ĳ���
//void radix_print(radix_node_t* node);

//�ڵ���Һ���
ptr_t radix_tree_find(radix_tree_t * t, uint32 key);
pool_t get_new_leafpool(radix_tree_t* t, int num);
radix_leafnode_t* radix_leafnode_alloc(radix_tree_t* t);
//����Ҷ�ڵ㣬����Ҷ�ڵ�����
int radix_tree_traversal(radix_tree_t* t);
//����Ҷ�ڵ㣬��ָ������
int radix_tree_traversal_fun(radix_tree_t* t, void(*fun)(uint32, uint32));
