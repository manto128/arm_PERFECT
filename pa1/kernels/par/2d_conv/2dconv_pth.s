	.file	"2dconv_pth.c"
	.text
	.p2align 4,,15
	.globl	multiply_accumulate
	.type	multiply_accumulate, @function
multiply_accumulate:
.LFB54:
	.cfi_startproc
	movl	nFilterRowsFD(%rip), %edx
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	nFilterColsFD(%rip), %ebx
	movl	%edx, %r10d
	movl	(%rdi), %eax
	movl	4(%rdi), %ecx
	shrl	$31, %r10d
	addl	%edx, %r10d
	movl	%ebx, %r11d
	sarl	%r10d
	shrl	$31, %r11d
	movl	%eax, %edi
	movl	%ecx, %ebp
	addl	%ebx, %r11d
	subl	%r10d, %edi
	addl	%r10d, %eax
	sarl	%r11d
	movl	%edi, -4(%rsp)
	subl	%r11d, %ebp
	cmpl	%eax, %edi
	jg	.L6
	addl	%ecx, %r11d
	leal	48(%rbx), %r12d
	movl	%edi, %r9d
	leal	1(%rax), %r10d
	movslq	%ebp, %r13
	movl	%r11d, %eax
	movq	%r13, %r14
	subl	%ebp, %eax
	movq	tmpBuf(%rip), %r15
	imull	%r12d, %r9d
	pxor	%xmm1, %xmm1
	negq	%r14
	leaq	1(%r13,%rax), %rsi
	subl	%edi, %r10d
	salq	$2, %r14
	xorl	%r8d, %r8d
	xorl	%edi, %edi
	.p2align 4,,10
	.p2align 3
.L5:
	cmpl	%ebp, %r11d
	jl	.L3
	movslq	%r9d, %rax
	leaq	(%r15,%rax,4), %rcx
	movslq	%r8d, %rax
	leaq	(%r14,%rax,4), %rdx
	leaq	FD(%rip), %rax
	addq	%rax, %rdx
	movq	%r13, %rax
	.p2align 4,,10
	.p2align 3
.L4:
	pxor	%xmm0, %xmm0
	cvtsi2ss	(%rcx,%rax,4), %xmm0
	mulss	(%rdx,%rax,4), %xmm0
	addq	$1, %rax
	cmpq	%rax, %rsi
	addss	%xmm0, %xmm1
	jne	.L4
.L3:
	addl	$1, %edi
	addl	%r12d, %r9d
	addl	%ebx, %r8d
	cmpl	%edi, %r10d
	jne	.L5
	cvttss2si	%xmm1, %eax
	movl	-4(%rsp), %ebx
.L2:
	leal	(%rbx,%rbx,2), %edx
	sall	$4, %edx
	addl	%edx, %ebp
	movq	output(%rip), %rdx
	movslq	%ebp, %rbp
	movl	%eax, (%rdx,%rbp,4)
	xorl	%eax, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	xorl	%eax, %eax
	movl	%edi, %ebx
	jmp	.L2
	.cfi_endproc
.LFE54:
	.size	multiply_accumulate, .-multiply_accumulate
	.p2align 4,,15
	.globl	conv2d
	.type	conv2d, @function
conv2d:
.LFB55:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movl	$4, %esi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24648, %rsp
	.cfi_def_cfa_offset 24704
	movq	%fs:40, %rax
	movq	%rax, 24632(%rsp)
	xorl	%eax, %eax
	movl	nFilterRowsFD(%rip), %eax
	movl	%eax, %edx
	leal	64(%rax), %edi
	shrl	$31, %edx
	addl	%eax, %edx
	movl	%edx, %ebx
	movl	nFilterColsFD(%rip), %edx
	sarl	%ebx
	movl	%ebx, 28(%rsp)
	movl	%edx, %ebp
	shrl	$31, %ebp
	addl	%edx, %ebp
	addl	$48, %edx
	imull	%edx, %edi
	sarl	%ebp
	movl	%edx, 8(%rsp)
	movslq	%edi, %rdi
	call	calloc@PLT
	movslq	%ebp, %rdi
	movq	%rax, tmpBuf(%rip)
	movl	%ebx, %esi
	xorl	%ecx, %ecx
	movl	8(%rsp), %edx
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L20:
	movl	nFilterColsFD(%rip), %edx
	movq	tmpBuf(%rip), %rax
	addl	$48, %edx
.L13:
	imull	%esi, %edx
	addl	$1, %esi
	movslq	%edx, %rdx
	addq	%rdi, %rdx
	leaq	(%rax,%rdx,4), %rax
	movq	frame(%rip), %rdx
	addq	%rcx, %rdx
	addq	$192, %rcx
	movdqu	(%rdx), %xmm0
	cmpq	$12288, %rcx
	movups	%xmm0, (%rax)
	movdqu	16(%rdx), %xmm0
	movups	%xmm0, 16(%rax)
	movdqu	32(%rdx), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	48(%rdx), %xmm0
	movups	%xmm0, 48(%rax)
	movdqu	64(%rdx), %xmm0
	movups	%xmm0, 64(%rax)
	movdqu	80(%rdx), %xmm0
	movups	%xmm0, 80(%rax)
	movdqu	96(%rdx), %xmm0
	movups	%xmm0, 96(%rax)
	movdqu	112(%rdx), %xmm0
	movups	%xmm0, 112(%rax)
	movdqu	128(%rdx), %xmm0
	movups	%xmm0, 128(%rax)
	movdqu	144(%rdx), %xmm0
	movups	%xmm0, 144(%rax)
	movdqu	160(%rdx), %xmm0
	movups	%xmm0, 160(%rax)
	movdqu	176(%rdx), %xmm0
	movups	%xmm0, 176(%rax)
	jne	.L20
	movslq	28(%rsp), %rax
	leaq	40(%rsp), %r13
	leaq	multiply_accumulate(%rip), %r12
	movq	$0, 8(%rsp)
	leaq	(%rax,%rax,2), %rax
	salq	$4, %rax
	addq	%rax, %rdi
	leaq	48(%rsp,%rdi,8), %rax
	movq	%rax, 16(%rsp)
	.p2align 4,,10
	.p2align 3
.L14:
	movl	28(%rsp), %ebx
	addl	8(%rsp), %ebx
	xorl	%r15d, %r15d
	movq	16(%rsp), %r14
	.p2align 4,,10
	.p2align 3
.L15:
	leal	0(%rbp,%r15), %eax
	xorl	%esi, %esi
	movq	%r14, %rdi
	movq	%r13, %rcx
	movq	%r12, %rdx
	addq	$1, %r15
	movl	%ebx, 40(%rsp)
	movl	%eax, 44(%rsp)
	addq	$8, %r14
	call	pthread_create@PLT
	cmpq	$48, %r15
	jne	.L15
	addq	$1, 8(%rsp)
	addq	$384, 16(%rsp)
	movq	8(%rsp), %rax
	cmpq	$64, %rax
	jne	.L14
	xorl	%edi, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE55:
	.size	conv2d, .-conv2d
	.comm	tmpBuf,8,8
	.globl	FD
	.data
	.align 32
	.type	FD, @object
	.size	FD, 324
FD:
	.long	1065353216
	.long	1077936128
	.long	1082130432
	.long	1084227584
	.long	1086324736
	.long	1084227584
	.long	1082130432
	.long	1077936128
	.long	1065353216
	.long	1077936128
	.long	1091567616
	.long	1094713344
	.long	1097859072
	.long	1099956224
	.long	1097859072
	.long	1094713344
	.long	1091567616
	.long	1077936128
	.long	1082130432
	.long	1094713344
	.long	1098907648
	.long	1101004800
	.long	1103101952
	.long	1101004800
	.long	1098907648
	.long	1094713344
	.long	1082130432
	.long	1084227584
	.long	1097859072
	.long	1101004800
	.long	1103626240
	.long	1106247680
	.long	1103626240
	.long	1101004800
	.long	1097859072
	.long	1084227584
	.long	1086324736
	.long	1099956224
	.long	1103101952
	.long	1106247680
	.long	1108344832
	.long	1106247680
	.long	1103101952
	.long	1099956224
	.long	1086324736
	.long	1084227584
	.long	1097859072
	.long	1101004800
	.long	1103626240
	.long	1106247680
	.long	1103626240
	.long	1101004800
	.long	1097859072
	.long	1084227584
	.long	1082130432
	.long	1094713344
	.long	1098907648
	.long	1101004800
	.long	1103101952
	.long	1101004800
	.long	1098907648
	.long	1094713344
	.long	1082130432
	.long	1077936128
	.long	1091567616
	.long	1094713344
	.long	1097859072
	.long	1099956224
	.long	1097859072
	.long	1094713344
	.long	1091567616
	.long	1077936128
	.long	1065353216
	.long	1077936128
	.long	1082130432
	.long	1084227584
	.long	1086324736
	.long	1084227584
	.long	1082130432
	.long	1077936128
	.long	1065353216
	.globl	nFilterColsFD
	.align 4
	.type	nFilterColsFD, @object
	.size	nFilterColsFD, 4
nFilterColsFD:
	.long	9
	.globl	nFilterRowsFD
	.align 4
	.type	nFilterRowsFD, @object
	.size	nFilterRowsFD, 4
nFilterRowsFD:
	.long	9
	.comm	output,8,8
	.comm	frame,8,8
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
