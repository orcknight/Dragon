#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "global.h"


/*======================================================================*
                            cstart
 *======================================================================*/
PUBLIC void cstart()
{
	disp_str("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		 "-----\"cstart\" begins-----\n");

		 
	/* �� LOADER �е� GDT ���Ƶ��µ� GDT �� */
	memcpy(&gdt,     /* New GDT */
	(void*)(*((u32*)(&gdt_ptr[2]))),/* Base  of Old GDT */
	*((u16*)(&gdt_ptr[0])) + 1 /* Limit of Old GDT */
		);
	/* gdt_ptr[6] �� 6 ���ֽڣ�0~15:Limit  16~47:Base������ sgdt/lgdt �Ĳ�����*/
	u16* p_gdt_limit = (u16*)(&gdt_ptr[0]);
	u32* p_gdt_base	 = (u32*)(&gdt_ptr[2]);
	*p_gdt_limit = GDT_SIZE * sizeof(DESCRIPTOR) - 1;
	*p_gdt_base	 = (u32)&gdt;	
	
	/* idt_ptr[6] �� 6 ���ֽڣ�0~15:Limit  16~47:Base������ sidt/lidt �Ĳ�����*/
	u16* p_idt_limit = (u16*)(&idt_ptr[0]);
	u32* p_idt_base  = (u32*)(&idt_ptr[2]);
	*p_idt_limit = IDT_SIZE * sizeof(GATE) - 1;
	*p_idt_base  = (u32)&idt;

	init_port();

	disp_str("-----\"cstart\" ends-----\n");
}
