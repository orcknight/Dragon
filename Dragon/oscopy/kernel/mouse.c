/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            mouse.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    ppx, 2012
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"


void wait_KBC_sendready(void)
{
	/* �L�[�{�[�h�R���g���[�����f�[�^���M�\�ɂȂ�̂�҂� */
	for (;;) {
		if ((in_byte(KB_CMD) & 0x02) == 0) {
			break;
		}
	}
	return;
}

/*======================================================================*
                            mouse_handler
 *======================================================================*/
PUBLIC void mouse_handler(int irq)
{
	disp_str("mouse");
}



/*======================================================================*
                           init_mouse
*======================================================================*/
PUBLIC void init_mouse()
{
	wait_KBC_sendready();
	out_byte(KB_CMD,0x60);
	wait_KBC_sendready();
	out_byte(KB_DATA,0x47);
	wait_KBC_sendready();
	out_byte(KB_CMD,0xd4);
	wait_KBC_sendready();
	out_byte(KB_DATA,0xf4);


	//put_irq_handler(MOUSE_IRQ,mouse_handler); /*�趨�����жϴ������*/
	//enable_irq(MOUSE_IRQ);                       /*�������ж�*/
}


