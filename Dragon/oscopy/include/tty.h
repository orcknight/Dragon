
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				tty.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
						    ppx, 2012
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef _MYOS_TTY_H_
#define _MYOS_TTY_H_

#define TTY_IN_BYTES	256		/* tty input queue size */

struct s_console;

/* TTY */
typedef struct s_tty
{
	u32 in_buf[TTY_IN_BYTES]; /* tty ���뻺���� */
	u32* p_inbuf_head;        /* ָ�򻺳�������һ������λ�� */
	u32* p_inbuf_tail;		  /* ָ���������Ӧ����ļ�ֵ */
	int  inbuf_count;		/* ���������Ѿ�����˶��� */
	struct s_console *	p_console;
}TTY;

#endif