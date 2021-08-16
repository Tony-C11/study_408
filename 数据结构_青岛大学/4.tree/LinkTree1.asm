	.file	"LinkTree.c"
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
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"%c\n"
	.text
	.globl	preOrderTraverse
	.type	preOrderTraverse, @function
preOrderTraverse:
.LFB7:
	.cfi_startproc
	pushq	%rbp
    ; %rbp用来寻址参数
    ; 进行递归调用时，参数入栈，参见：movq	%rdi, -8(%rbp)
    ; 使得pTree == (%rbp - 8)，通过%rbp能寻址pTree，从而使用pTree
    ; 在递归进行的一开始，%rbp此时保存的是上一层调用者的pTree所在的位置（实际上是pTree所在位置+8），
    ; 将这个值入栈，当这层递归结束前，将这个值出栈到%rbp中，以此在返回上一级调用者的函数时能够在通过%rbp来寻址上一级的pTree的值。
    ; 这里，栈进行了保存上层调用者的pTree的位置的功能，
    ; 每次递归调用时，都要进行保存，
    ; 还要进行movq %rdi, -8(%rbp) -> 二叉树递归的空间复杂度是O(n)，n为结点数量。
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp       ; 让栈指针直接到栈帧底部
	movq	%rdi, -8(%rbp) ; %rdi 存的是pTree的值（pTree指向的内存的地址），这相当于让参数pTree入栈，这也能方便递归返回上一级时，能够通过寻址使用上一层的pTree，让返回到上一级调用者时，上一级的pTree不会丢失，参数入栈是二叉树遍历算法的空间复杂度结果的原因
	cmpq	$0, -8(%rbp)
	je	.L6
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi      ; %rsi = pTree->data
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi      ; %rdi = "%c\n"
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax   ; 让%rax = pTree->lChild
	movq	%rax, %rdi      ; %rdi 存储函数调用要使用的第一个参数
	call	preOrderTraverse
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	preOrderTraverse
	nop
.L6:
	nop
	leave       ; movq %rbp, %rsp   popq %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	preOrderTraverse, .-preOrderTraverse
	.globl	midOrderTraverse
	.type	midOrderTraverse, @function
midOrderTraverse:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L10
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	midOrderTraverse
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	midOrderTraverse
	nop
.L10:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	midOrderTraverse, .-midOrderTraverse
	.globl	postOrderTraverse
	.type	postOrderTraverse, @function
postOrderTraverse:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L14
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	postOrderTraverse
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	postOrderTraverse
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L14:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	postOrderTraverse, .-postOrderTraverse
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
