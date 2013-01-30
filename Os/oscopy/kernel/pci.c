/*************************************************************************//**
 *****************************************************************************
 * @file   pci.c
 * @brief  
 * @author ppx
 * @date   2012
 *****************************************************************************
 *****************************************************************************/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "hd.h"
#include "pci.h"

PUBLIC void init_pci()
{
	int i = 0,busNo,deviceNo,funcNo,regVal,retVal,baseAddr,innerRegVal,j;
	u16 vendorID,devID,classCode,subClass,specialCode;

	for(busNo = 0; busNo < 256 ; busNo++)
	{
		for(deviceNo = 0; deviceNo < 32; deviceNo++)
		{
			for(funcNo = 0; funcNo < 8 ;funcNo++)
			{
				regVal = MAKECONFIGREG(busNo,deviceNo,funcNo);
				innerRegVal = regVal;
				out_dword(PCICONFIGREG,innerRegVal);
				retVal = in_dword(PCIDATAREG);
				if(retVal == 0xffffffff || retVal == 0x00000000 ||
					retVal == 0x0000ffff || retVal == 0xffff0000)
				{
					continue;
				}
				vendorID = retVal & 0xffff;		//�õ���Ӧ�̴���
				devID = (retVal >> 16) & 0xffff; //�õ��豸����
				innerRegVal =  regVal + 0x08;				//�õ����ÿռ�ƫ��Ϊ08H��˫��
				out_dword(PCICONFIGREG,innerRegVal);
				retVal = in_dword(PCIDATAREG);
				retVal = retVal >> 8;  //���˵��汾��
				specialCode = retVal & 0x0FF;
				subClass = (retVal >> 8) & 0x0FF;
				classCode = (retVal >> 16) & 0x0FF;

				if(classCode == 0x01 && subClass == 0x01)
				{
					innerRegVal = regVal +  0x18;
					out_dword(PCICONFIGREG,innerRegVal);
					retVal = in_dword(PCIDATAREG) & 0xfffc;
					if(retVal == 0x01 || retVal == 0x00)
						hdd_base.ata_filebase = 0x1F0;
					else
						hdd_base.ata_filebase = retVal;
					printl("File Base:--0x%x--\n",hdd_base.ata_filebase);
					innerRegVal = regVal +  0x1C;
					out_dword(PCICONFIGREG,innerRegVal);
					retVal = in_dword(PCIDATAREG) & 0xfffc;
					if(retVal == 0x01 || retVal == 0x00)
						hdd_base.ata_ctlbase = 0x3F4;
					else
						hdd_base.ata_ctlbase = retVal;
					printl("Ctl Base:--0x%x--\n",hdd_base.ata_ctlbase);
					innerRegVal = regVal + 0x3c;
					out_dword(PCICONFIGREG,innerRegVal);
					out_dword(PCIDATAREG,0xFE);
					out_dword(PCICONFIGREG,innerRegVal);
					retVal = in_dword(PCIDATAREG);
					if( (retVal & 0xFF) == 0xFE)
					{
						printl("The Device needs IRQ assignment.\n");
					}
					else
					{
						if(specialCode == 0x8A || specialCode == 0x80)
						{
							printl("this is a PATA\n");
						}
					}
					printl("irq:--0x%x--\n",retVal & 0xff);
					printl("--busNo:%d,DeviceNo:%d,funcNo:%d--\n",busNo,deviceNo,funcNo);
					retVal = in_byte(REG_STATUS+hdd_base.ata_filebase);
					i++;
				}
				if(funcNo == 0)    // ����ǵ������豸�����ٲ�funcNo>0���豸
				{
					innerRegVal = regVal + 0x0C; //���ÿռ�ƫ��0x0C
					out_dword(PCICONFIGREG,innerRegVal);
					retVal = in_dword(PCIDATAREG);
					retVal = retVal >> 16;		//ƫ��0x0EΪͶ�������ֶ�
					if((retVal & 0x80) == 0) funcNo = 8;
				}

			}

		}

	}
	printl("PCI Device Number:%d\n",i);

}