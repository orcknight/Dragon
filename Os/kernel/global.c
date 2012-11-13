
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    ppx, 2012
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define GLOBAL_VARIABLES_HERE

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "global.h"
#include "proc.h"

PUBLIC PROCESS proc_table[NR_TASKS + NR_PROCS];
PUBLIC char task_stack[STACK_SIZE_TOTAL];

PUBLIC TASK task_table[NR_TASKS] = { 
	{task_tty,STACK_SIZE_TTY,"tty"},
	{task_sys,STACK_SIZE_SYS,"SYS"}};

PUBLIC TASK user_proc_table[NR_PROCS] = {
	{TestA,STACK_SIZE_TESTA,"TestA"},
	{TestB,STACK_SIZE_TESTB,"TestB"},
	{TestC,STACK_SIZE_TESTC,"TestC"}
};


PUBLIC TTY tty_table[NR_CONSOLES];
PUBLIC CONSOLE console_table[NR_CONSOLES];

PUBLIC irq_handler irq_table[NR_IRQ];
PUBLIC system_call sys_call_table[NR_SYS_CALL] = 
					{sys_printx,sys_sendrec};