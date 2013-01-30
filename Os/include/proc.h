
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               proc.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#ifndef _MYOS_PROC_H_
#define _MYOS_PROC_H_

struct stackframe {	/* proc_ptr points here				â†?Low			*/
	u32	gs;		/* â”?					â”?		*/
	u32	fs;		/* â”?					â”?		*/
	u32	es;		/* â”?					â”?		*/
	u32	ds;		/* â”?					â”?		*/
	u32	edi;		/* â”?					â”?		*/
	u32	esi;		/* â”?pushed by save()				â”?		*/
	u32	ebp;		/* â”?					â”?		*/
	u32	kernel_esp;	/* <- 'popad' will ignore it			â”?		*/
	u32	ebx;		/* â”?					â†‘æ ˆä»Žé«˜åœ°å€å¾€ä½Žåœ°å€å¢žé•¿*/		
	u32	edx;		/* â”?					â”?		*/
	u32	ecx;		/* â”?					â”?		*/
	u32	eax;		/* â”?					â”?		*/
	u32	retaddr;	/* return address for assembly code save()	â”?		*/
	u32	eip;		/*  â”?					â”?		*/
	u32	cs;		/*  â”?					â”?		*/
	u32	eflags;		/*  â”?these are pushed by CPU during interrupt	â”?		*/
	u32	esp;		/*  â”?					â”?		*/
	u32	ss;		/*  â”?					â”·High			*/
};


struct proc {
	struct stackframe regs;    /* process registers saved in stack frame */

	u16 ldt_sel;               /* gdt selector giving ldt base and limit */
	struct descriptor ldts[LDT_SIZE]; /* local descs for code and data */

        int ticks;                 /* remained ticks */
        int priority;

	u32 pid;                   /* process id passed in from MM */
	char name[16];		   /* name of the process */

	int  p_flags;              /**
				    * process flags.
				    * A proc is runnable iff p_flags==0
				    */

	MESSAGE * p_msg;
	int p_recvfrom;
	int p_sendto;

	int has_int_msg;           /**
				    * nonzero if an INTERRUPT occurred when
				    * the task is not ready to deal with it.
				    */

	struct proc * q_sending;   /**
				    * queue of procs sending messages to
				    * this proc
				    */
	struct proc * next_sending;/**
				    * next proc in the sending
				    * queue (q_sending)
				    */

	int nr_tty;
	struct file_desc * filp[NR_FILES];
};

struct task {
	task_f	initial_eip;
	int	stacksize;
	char	name[32];
};

#define proc2pid(x) (x - proc_table)

/* Number of tasks & procs */
#define NR_TASKS	4
#define NR_PROCS	3
#define FIRST_PROC	proc_table[0]
#define LAST_PROC	proc_table[NR_TASKS + NR_PROCS - 1]

/* stacks of tasks */
#define STACK_SIZE_TTY		0x8000
#define STACK_SIZE_SYS		0x8000
#define STACK_SIZE_HD		0x8000
#define STACK_SIZE_FS		0x8000
#define STACK_SIZE_TESTA	0x8000
#define STACK_SIZE_TESTB	0x8000
#define STACK_SIZE_TESTC	0x8000

#define STACK_SIZE_TOTAL	(STACK_SIZE_TTY + \
				STACK_SIZE_SYS + \
				STACK_SIZE_HD + \
				STACK_SIZE_FS + \
				STACK_SIZE_TESTA + \
				STACK_SIZE_TESTB + \
				STACK_SIZE_TESTC)
#endif
