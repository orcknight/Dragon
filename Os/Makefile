#entry point of MyOs
#it must have the same value with 'KernelEntryPointPhyAddr' in load.inc!
ENTRYPOINT	= 0x30400

ENTRYOFFSET	= 0x400
#programs,flags,etc.
ASM		= nasm
DASM	= ndisasm
CC		= gcc
LD		= ld
ASMBFLAGS	= -I boot/include/
ASMKFLAGS	= -I include/ -f elf
CFLAGS		= -I include/ -c -fno-builtin -fno-stack-protector
LDFLAGS		=  -s -Ttext $(ENTRYPOINT) 
DASMFLAGS	= -u -o $(ENTRYPOINT) -e $(ENTRYOFFSET)


#this program
MYOSBOOT	= boot/boot.bin boot/loader.bin
MYOSKERNEL	= kernel.bin
OBJS		= kernel/kernel.o kernel/start.o lib/kliba.o lib/string.o \
			  kernel/i8259.o kernel/global.o kernel/protect.o \
			  lib/klib.o kernel/main.o kernel/clock.o \
			  kernel/syscall.o kernel/proc.o kernel/keyboard.o \
			  kernel/tty.o kernel/console.o kernel/mouse.o \
			  kernel/printf.o kernel/vsprintf.o kernel/systask.o \
			  lib/misc.o kernel/hd.o fs/main.o
DASMOUTPUT	= kernel.bin.asm

#all phony targets
.PHONY: everything final image clean realclean disasm all buildimg

#default starting position
everything: $(MYOSBOOT) $(MYOSKERNEL)

all: realclean everything

final: all clean

image: final buildimg

clean:
	rm -f $(OBJS)

realclean:
	rm -f $(OBJS) $(MYOSBOOT) $(MYOSKERNEL)

disasm:
	$(DASM) $(DASMFLAGS) $(MYOSKERNEL) > $(DASMOUTPUT)

#we assume that "a.img" exists in current folder
buildimg:
	dd if=boot/boot.bin of=a.img bs=512 count=1 conv=notrunc
	sudo mount -o loop a.img /mnt/floppy
	sudo cp -fv boot/loader.bin /mnt/floppy
	sudo cp -fv kernel.bin /mnt/floppy
	sudo umount /mnt/floppy

boot/boot.bin: boot/boot.asm boot/include/load.inc \
		boot/include/fat12hdr.inc
	$(ASM) $(ASMBFLAGS) -o $@ $<

boot/loader.bin: boot/loader.asm boot/include/load.inc \
		boot/include/fat12hdr.inc boot/include/pm.inc
	$(ASM) $(ASMBFLAGS) -o $@ $<

$(MYOSKERNEL): $(OBJS)
	$(LD) $(LDFLAGS) -o $(MYOSKERNEL) $(OBJS)

kernel/kernel.o: kernel/kernel.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<
kernel/syscall.o: kernel/syscall.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<
kernel/start.o: kernel/start.c include/type.h include/const.h \
		include/protect.h include/proto.h include/string.h
	$(CC) $(CFLAGS) -o $@ $<
kernel/i8259.o: kernel/i8259.c include/type.h include/const.h \
		include/protect.h include/proto.h
	$(CC) $(CFLAGS) -o $@ $<
kernel/global.o: kernel/global.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/protect.o: kernel/protect.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/clock.o: kernel/clock.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/main.o: kernel/main.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/proc.o: kernel/proc.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/keyboard.o: kernel/keyboard.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/tty.o: kernel/tty.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/console.o: kernel/console.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/mouse.o: kernel/mouse.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/printf.o: kernel/printf.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/vsprintf.o: kernel/vsprintf.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/systask.o: kernel/systask.c
	$(CC) $(CFLAGS) -o $@ $<
kernel/hd.o: kernel/hd.c
	$(CC) $(CFLAGS) -o $@ $<
fs/main.o: fs/main.c
	$(CC) $(CFLAGS) -o $@ $<
lib/misc.o: lib/misc.c
	$(CC) $(CFLAGS) -o $@ $<
lib/klib.o: lib/klib.c
	$(CC) $(CFLAGS) -o $@ $<
lib/kliba.o: lib/kliba.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<
lib/string.o: lib/string.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<
