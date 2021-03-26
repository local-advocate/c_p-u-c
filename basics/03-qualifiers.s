	.file	"03-qualifiers.c"
	.text
	.globl	extint1
	.data
	.align 4
	.type	extint1, @object
	.size	extint1, 4
extint1:
	.long	99
	.section	.rodata
.LC0:
	.string	"inline function returned: %d\n"
	.align 8
.LC1:
	.string	"static inline function returned: %d\n"
	.align 8
.LC2:
	.string	"extern inline function returned: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	leaq	16(%rbp), %rax
	movq	%rax, -56(%rbp)
	movl	$0, -60(%rbp)
	movl	$0, -4(%rbp)
	movl	$-1, -64(%rbp)
	movl	$9, -68(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, -16(%rbp)
	leaq	-68(%rbp), %rax
	movq	%rax, -24(%rbp)
	leaq	-60(%rbp), %rax
	movq	%rax, -32(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, -40(%rbp)
	movl	$0, %eax
	call	printextern@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, -48(%rbp)
	movl	$-1, %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$-2, %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	call	inlfunc3@PLT
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.data
	.align 4
	.type	stint1.2323, @object
	.size	stint1.2323, 4
stint1.2323:
	.long	10
	.ident	"GCC: (Debian 9.2.1-22) 9.2.1 20200104"
	.section	.note.GNU-stack,"",@progbits
