	.file	"a.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
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
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
