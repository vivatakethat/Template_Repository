	.file	"0.4.3.cpp"
	.local	_ZL7counter
	.comm	_ZL7counter,4,4
	.text
	.type	_ZL6threadPv, @function
_ZL6threadPv:
.LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	.L2
.L3:
	movl	_ZL7counter, %eax
	addl	$1, %eax
	movl	%eax, _ZL7counter
	addl	$1, -4(%ebp)
.L2:
	cmpl	$999999, -4(%ebp)
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE11:
	.size	_ZL6threadPv, .-_ZL6threadPv
	.section	.rodata
.LC0:
	.string	"Counter is %d by threads\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 12(%esp)
	movl	$_ZL6threadPv, 8(%esp)
	movl	$0, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	pthread_create
	movl	$0, 12(%esp)
	movl	$_ZL6threadPv, 8(%esp)
	movl	$0, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	pthread_create
	movl	24(%esp), %eax
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	pthread_join
	movl	28(%esp), %eax
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	pthread_join
	movl	_ZL7counter, %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
