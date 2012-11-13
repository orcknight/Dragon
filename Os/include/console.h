
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			      console.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
						    ppx, 2012
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef _MYOS_CONSOLE_H_
#define _MYOS_CONSOLE_H_

/* CONSOLE */
typedef struct s_console
{
	unsigned int current_start_addr; /* ��ǰ��ʾ����ʲôλ��	  */
	unsigned int	original_addr;		/* ��ǰ����̨��Ӧ�Դ�λ�� */
	unsigned int	v_mem_limit;		/* ��ǰ����̨ռ���Դ��С */
	unsigned int	cursor;			/* ��ǰ���λ�� */
}CONSOLE;


#define SCR_UP  1 /*scroll forward */
#define SCR_DN  -1 /*scroll backward */

#define SCR_SIZE (80 * 25)
#define SCR_WIDTH 80

#define DEFAULT_CHAR_COLOR	0x07	/* 0000 0111 �ڵװ��� */
#define GRAY_CHAR		(MAKE_COLOR(BLACK, BLACK) | BRIGHT)
#define RED_CHAR		(MAKE_COLOR(BLUE, RED) | BRIGHT)

#endif