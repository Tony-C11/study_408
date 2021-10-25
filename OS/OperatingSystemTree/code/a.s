	.file	"a.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	fork@PLT
	testl	%eax, %eax
	jne	.L2
.L3:
	movl	$65, %edi
	call	putchar@PLT
	jmp	.L3
.L2:
	call	fork@PLT
	testl	%eax, %eax
	jne	.L4
.L5:
	movl	$66, %edi
	call	putchar@PLT
	jmp	.L5
.L4:
	movl	$0, %eax
	call	wait@PLT
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
