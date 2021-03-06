
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
	u32 in_buf[TTY_IN_BYTES]; /* tty 输入缓冲区 */
	u32* p_inbuf_head;        /* 指向缓冲区中下一个空闲位置 */
	u32* p_inbuf_tail;		  /* 指向键盘任务应处理的键值 */
	int  inbuf_count;		/* 缓冲区中已经填充了多少 */
	struct s_console *	p_console;
}TTY;

#endif