/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    ppx, 2012
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* Extern is defined as extern except in global.c */
#ifdef GLOBAL_VARIABLES_HERE
#undef	EXTERN
#define EXTERN
#endif

#include "proc.h"
#include "tty.h"
#include "console.h"
#include "fs.h"

EXTERN int disp_pos;
EXTERN  int ticks;

EXTERN u8  gdt_ptr[6];/* 0~15:Limit  16~47:Base */
EXTERN DESCRIPTOR gdt[GDT_SIZE];
EXTERN u8  idt_ptr[6];/* 0~15:Limit  16~47:Base */
EXTERN	GATE  idt[IDT_SIZE];

EXTERN u32 k_reenter;
EXTERN int nr_current_console;

EXTERN	TSS		tss;
EXTERN	PROCESS*	p_proc_ready;

extern	char		task_stack[];
extern	PROCESS		proc_table[];
extern	TASK		task_table[];
extern  TASK		user_proc_table[];
extern  irq_handler  irq_table[];
extern  TTY    tty_table[];
extern  CONSOLE  console_table[];

/* FS */
extern	struct dev_drv_map dd_map[];
