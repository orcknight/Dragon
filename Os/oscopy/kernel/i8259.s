	.file	"i8259.c"
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	-12(%ebp), %ebx
	addl	%ecx, %eax
	adcl	%ebx, %edx
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	fildq	-32(%ebp)
	addl	$28, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.globl	init_8259A
	.type	init_8259A, @function
init_8259A:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$17, 4(%esp)
	movl	$32, (%esp)
	call	out_byte
	movl	$17, 4(%esp)
	movl	$160, (%esp)
	call	out_byte
	movl	$32, 4(%esp)
	movl	$33, (%esp)
	call	out_byte
	movl	$40, 4(%esp)
	movl	$161, (%esp)
	call	out_byte
	movl	$4, 4(%esp)
	movl	$161, (%esp)
	call	out_byte
	movl	$2, 4(%esp)
	movl	$161, (%esp)
	call	out_byte
	movl	$1, 4(%esp)
	movl	$33, (%esp)
	call	out_byte
	movl	$1, 4(%esp)
	movl	$161, (%esp)
	call	out_byte
	movl	$255, 4(%esp)
	movl	$33, (%esp)
	call	out_byte
	movl	$255, 4(%esp)
	movl	$161, (%esp)
	call	out_byte
	movl	$2, 8(%esp)
	movl	$0, 12(%esp)
	movl	$1, (%esp)
	movl	$0, 4(%esp)
	call	sum
	fstp	%st(0)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	init_8259A, .-init_8259A
	.ident	"GCC: (GNU) 4.7.0 20120507 (Red Hat 4.7.0-5)"
	.section	.note.GNU-stack,"",@progbits
