; FAT12 ���̵�ͷ
;-----------------------------------------------------------------

        BS_OEMName      DB      'ForrestY'              ;OEM String,����8���ֽ�
        BPB_BytsPerSec  DW      512                     ;ÿ�����ֽ���
        BPB_SecPerClus  DB      1                       ;ÿ�ض�������
        BPB_RsvdSecCnt  DW      1                       ;Boot��¼ռ�ö�������
        BPB_NumFATs             DB      2                       ;���ж���FAT��
        BPB_RootEntCnt  DW      224                     ;��Ŀ¼�ļ������ֵ
        BPB_TotSec16    DW      2880            ;�߼���������
        BPB_Media               DB      0xF0            ;ý��������
        BPB_FATSz16             DW      9                       ;ÿFAT������
        BPB_SecPerTrk   DW      18                      ;ÿ�ŵ�������
        BPB_NumHeads    DW      2                       ;��ͷ����������
        BPB_HiddSec             DD      0                       ;����������
        BPB_TotSec32    DD      0                       ;wTotalSectorCountΪ0ʱ���ֵ��¼������
        
        BS_DrvNum               DB      0                     ;�ж�13����������
        BS_Reserved1    DB      0                       ;δʹ��
        BS_BootSig              DB      29h                     ;��չ������ǣ�29h��
        BS_VolID                DD      0                       ;�����к�
        BS_VolLab               DB      'OrangeS0.02'   ;���꣬����11���ֽ�
        BS_FileSysType  DB      'FAT12   '              ;�ļ�ϵͳ���ͣ�����8���ֽ�
        
;====================================================================================
;���� FAT12 ͷ��һЩ�������壬���ͷ��Ϣ�ı䣬����ĳ�������ҲҪ����Ӧ�ı�
;=====================================================================================��
;BPB_FATSz16
FATSz                   equ             9

;��Ŀ¼ռ�ÿռ䣺
; RootDirSectors = ((BPB_RootEntCnt * 32) + (BPB_BytsPerSec-1))/BPB_BytsPerSec
; ��������մ˹�ʽ����������ʶ���˺�
RootDirSectors          equ             14

; Root Directory �ĵ�һ�������� =       BPB_RsvdSecCnt + (BPB_NumFATs * FATSz)
SectorNoOfRootDirectory equ     19

; FAT1 �ĵ�һ�������� = BPB_RsvdSecCnt
SectorNoOfFAT1          equ             1

; DeltaSectorNo = BPB_RsvdSecCnt + (BPB_NumFATs + FATSz) - 2
; �ļ��Ŀ�ʼSector�� = DirEntry�еĿ�ʼSector�� + ��Ŀ¼ռ��Sector��Ŀ
;                                                       + DeltaSectorNo
DeltaSectorNo           equ             17

















