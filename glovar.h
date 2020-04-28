#pragma once
#include"lxerror.h"
#include"lxstruct.h"
#include"radix_tree.h"
#include"stack.h"
//ȫ�ֱ���ͷ�ļ�
extern _bootloder DiskBOOT;//ָ��Ӵ��̶�ȡ����������
//ϵͳ��������
extern unsigned char UNIT;//����UNITֵ
extern uint16 BytePerSec;//��������ռ���ֽ���
extern uint16 RootEntCnt;//��Ŀ¼����ļ���
extern uint32 BLOCK_SIZE;//��Ĵ�С
extern uint32 BLOCK_GROUP_SIZE;//����ռ�ÿ���
extern uint32 DISK_SIZE;//Ӳ������,��
extern uint64 DISK_SIZE_BYTES;//Ӳ���������ֽ�
//����λͼ
extern uint32 sizeDAB;//����λͼռ���ֽ���
extern uint32 BGSize;//�����С��block group size
extern uint64 DAB_0;//0��λͼλ�ã���λ��
extern _dabmp DataBMP;//λͼ�洢�飬�����̵�λͼȫ�������ڴ�
extern uint32 DataBMPNum;//λͼ����
//�ڵ�
extern uint32 sizeLFDB;//Ҷ�ڵ��ļ�������ռ���ֽ���
extern uint32 sizeBFDB;//�ڲ��ڵ��ļ�������ռ���ֽ���
//��־��
extern uint32 addrLB_0;//��־���׵�ַ
extern uint32 sizeLB;//��־��ռ���ֽ���
//B+�����
extern uint32 RootAddr;//���ڵ��ַ���ýڵ�������ĳ���ļ����������ʼ���������ſ��Ա�����
extern _lx_info_block _lxinfoblock;//��Ϣ��ָ��
extern uint32 mem_lnode_num;//�ڴ��е�ǰӵ�е�Ҷ�ڵ�ڵ�����
extern uint32 mem_bnode_num;//�ڴ��е�ǰӵ�е��ڲ��ڵ�����
//��ʽ������Ҫ����
extern uint32 format_block_size;			//�鳤��
extern uint8 format_unit;					//��Ԫֵ
extern uint16 format_bytepersec;			//��������
extern uint32 format_root;					//���ڵ��ַ
extern uint64 format_root_addr;
extern uint32 format_backup_root;			//���ݸ��ڵ��ַ
extern uint64 format_backup_root_addr;
extern uint32 format_lxinfo;				//lx��Ϣ���ַ
extern uint64 format_lxinfo_addr;
extern uint32 format_backup_lxinfo;			//������Ϣ���ַ
extern uint64 format_backup_lxinfo_addr;
extern uint32 format_boot;					//����������ַ
extern uint64 format_boot_addr;
extern uint32 format_backup_boot;			//��������������ַ
extern uint64 format_backup_boot_addr;

extern uint32 format_disk_n;				//Ӳ����������λ����
extern uint64 format_disk_size;				//Ӳ����������λ��byte
extern uint32 block_group_n;				//����ռ�ÿ�������λ����
extern uint64 block_group_size;				//����ռ�ÿ�������λ��byte
extern uint32 end_block_group_n;			//���Ŀ���ռ�Ŀ�������λ����
extern uint64 end_block_group_size;			//���Ŀ���ռ�Ŀ�������λ��byte

//�ļ����亯������
extern char* filenamebuf;//���ڴ���ӽڵ���������ļ���������Ҫ��ʼ��
extern int fnb_p;//����filenamebuf����Ч����
extern FileTreeRoot _file_tree_root;//������ڵ�ָ��
extern uint32 _file_tree_lnode0;//�ļ����ĵ�һ��Ҷ�ڵ�

//������
extern radix_tree_t* radix_node_ptr;//����ڵ�ָ�룬�ڴ�ָ����������Ҷ�ڵ㣬����ָ����Ϊ����
//��ջ
extern Stack DataBMP_Stack;//λͼ��ջ

//�ļ���
