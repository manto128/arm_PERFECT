	.file	"2dconv.c"
	.text
	.p2align 4,,15
	.type	conv2d._omp_fn.0, @function
conv2d._omp_fn.0:
.LFB54:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r14
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
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	movl	60(%rdi), %r15d
	movl	68(%rdi), %ebx
	movq	%rdi, 72(%rsp)
	movl	%r15d, 88(%rsp)
	call	omp_get_num_threads@PLT
	movl	%eax, %ebp
	call	omp_get_thread_num@PLT
	movl	%eax, %ecx
	movl	24(%r14), %eax
	addl	%r15d, %eax
	subl	%ebx, %eax
	cltd
	idivl	%ebp
	cmpl	%edx, %ecx
	jge	.L23
	addl	$1, %eax
	xorl	%edx, %edx
.L23:
	imull	%eax, %ecx
	addl	%edx, %ecx
	addl	%ecx, %eax
	cmpl	%eax, %ecx
	jge	.L1
	movq	72(%rsp), %rdi
	addl	%ebx, %eax
	addl	%ecx, %ebx
	movl	88(%rsp), %r10d
	movl	%eax, 116(%rsp)
	xorl	%r12d, %r12d
	movq	8(%rdi), %rsi
	movl	28(%rdi), %r9d
	movl	64(%rdi), %r11d
	movq	16(%rdi), %rdx
	leal	1(%r10,%rbx), %ebp
	movss	32(%rdi), %xmm3
	movl	76(%rdi), %r14d
	movq	%rsi, 96(%rsp)
	movq	(%rdi), %rsi
	imull	%r9d, %ecx
	movl	%r11d, %r13d
	movl	%r11d, 92(%rsp)
	movl	%r9d, 112(%rsp)
	addl	%r9d, %r11d
	movl	%ebp, 52(%rsp)
	movq	%rsi, 104(%rsp)
	movq	%rdi, %rsi
	leal	(%r10,%rbx), %ebp
	movl	%ecx, 80(%rsp)
	movl	36(%rsi), %ecx
	subl	%r10d, %ebx
	movq	%rdx, 24(%rsp)
	movl	%ebx, 44(%rsp)
	xorl	%r10d, %r10d
	movl	72(%rdi), %edx
	movl	48(%rdi), %eax
	addl	%ecx, %r9d
	movl	80(%rdi), %r15d
	movl	%ebp, 48(%rsp)
	imull	%r9d, %ebx
	movss	40(%rdi), %xmm1
	movl	%edx, 68(%rsp)
	movl	%ecx, 16(%rsp)
	xorl	%ebp, %ebp
	movl	56(%rdi), %edx
	movl	%r9d, (%rsp)
	xorl	%ecx, %ecx
	movl	%r11d, 120(%rsp)
	movl	44(%rdi), %edi
	xorl	%r9d, %r9d
	movl	52(%rsi), %r8d
	movl	%ebx, 56(%rsp)
	movl	68(%rsp), %ebx
	addl	%r13d, %ebx
	movl	%ebx, 124(%rsp)
	movl	%r11d, %ebx
	addl	%r13d, %ebx
	movl	%ebx, 60(%rsp)
.L6:
	movl	120(%rsp), %esi
	cmpl	%esi, 68(%rsp)
	jge	.L51
	movslq	80(%rsp), %rsi
	movq	104(%rsp), %rbx
	movl	48(%rsp), %edi
	movl	44(%rsp), %r8d
	movl	68(%rsp), %r11d
	subl	92(%rsp), %r11d
	movq	96(%rsp), %r13
	movl	%eax, 8(%rsp)
	leaq	(%rbx,%rsi,4), %rbx
	leal	1(%rdi), %esi
	subl	%r8d, %edi
	leal	1(%rdi), %edi
	movq	%rbx, 32(%rsp)
	movl	124(%rsp), %ebx
	movl	%esi, 84(%rsp)
	subl	%r8d, %esi
	movl	%edi, 64(%rsp)
	movl	%esi, 4(%rsp)
	movl	48(%rsp), %esi
	movl	%ebx, %r10d
	addl	$1, %ebx
	cmpl	%esi, 44(%rsp)
	movl	%ebx, 40(%rsp)
	jg	.L52
	.p2align 4,,10
	.p2align 3
.L8:
	movl	56(%rsp), %eax
	movl	%r10d, %edi
	movl	%r11d, %r12d
	subl	%r11d, %edi
	pxor	%xmm1, %xmm1
	xorl	%r9d, %r9d
	subl	%r10d, %r12d
	leal	(%r10,%rax), %r8d
	movl	%edi, %eax
	leaq	4(,%rax,4), %rsi
	movslq	%r11d, %rax
	movq	%rax, 8(%rsp)
	leal	1(%rdi), %eax
	movl	%eax, 20(%rsp)
	.p2align 4,,10
	.p2align 3
.L12:
	cmpl	%r10d, %r11d
	jg	.L53
	movl	%r8d, %eax
	movq	24(%rsp), %rcx
	subl	%r10d, %eax
	cltq
	addq	8(%rsp), %rax
	leaq	(%rcx,%rax,4), %rcx
	leal	(%r12,%rdi), %eax
	cltq
	leaq	0(%r13,%rax,4), %rdx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L14:
	pxor	%xmm0, %xmm0
	cvtsi2ss	(%rcx,%rax), %xmm0
	mulss	(%rdx,%rax), %xmm0
	addq	$4, %rax
	cmpq	%rsi, %rax
	addss	%xmm0, %xmm1
	jne	.L14
	movl	20(%rsp), %eax
	movl	%r8d, %r14d
	movl	%edi, %r15d
	movl	%ebx, %edx
	movl	$1, %ebp
	movl	$1, %ecx
.L15:
	addl	$1, %r9d
	addl	(%rsp), %r8d
	addl	16(%rsp), %edi
	cmpl	%r9d, 4(%rsp)
	jne	.L12
	movl	64(%rsp), %edi
	movl	52(%rsp), %r8d
	movl	$1, %r9d
	movl	%eax, 8(%rsp)
	movl	$1, %r12d
.L13:
	movaps	%xmm1, %xmm0
	movq	32(%rsp), %r10
	movl	60(%rsp), %eax
	addl	$1, %ebx
	addl	$1, %r11d
	divss	%xmm3, %xmm0
	addq	$4, %r10
	cvttss2si	%xmm0, %esi
	movl	%esi, -4(%r10)
	movl	40(%rsp), %esi
	movq	%r10, 32(%rsp)
	cmpl	%eax, %esi
	movl	%esi, %r10d
	je	.L48
	leal	1(%rsi), %eax
	movl	48(%rsp), %esi
	cmpl	%esi, 44(%rsp)
	movl	%eax, 40(%rsp)
	jle	.L8
.L52:
	movl	44(%rsp), %r8d
	pxor	%xmm1, %xmm1
	xorl	%edi, %edi
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L53:
	movl	%r11d, %edx
	xorl	%eax, %eax
	jmp	.L15
.L48:
	movl	8(%rsp), %eax
	movl	84(%rsp), %ebx
	movl	$1, %r10d
.L10:
	movl	%ebx, 48(%rsp)
	subl	88(%rsp), %ebx
	movl	112(%rsp), %r11d
	addl	$1, 52(%rsp)
	addl	%r11d, 80(%rsp)
	movl	(%rsp), %r11d
	addl	$1, 44(%rsp)
	addl	%r11d, 56(%rsp)
	cmpl	%ebx, 116(%rsp)
	jg	.L6
	testb	%cl, %cl
	jne	.L54
.L16:
	testb	%r10b, %r10b
	jne	.L55
.L17:
	testb	%r12b, %r12b
	je	.L18
	movq	72(%rsp), %rbx
	movl	%eax, 48(%rbx)
.L18:
	testb	%bpl, %bpl
	je	.L19
	movq	72(%rsp), %rax
	movl	%r15d, 80(%rax)
.L19:
	testb	%r10b, %r10b
	jne	.L56
	testb	%r9b, %r9b
	jne	.L24
.L1:
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
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
.L51:
	.cfi_restore_state
	movl	48(%rsp), %ebx
	addl	$1, %ebx
	movl	%ebx, 84(%rsp)
	jmp	.L10
.L54:
	movq	72(%rsp), %rbx
	movl	%r14d, 76(%rbx)
	jmp	.L16
.L55:
	movq	72(%rsp), %rbx
	movl	%edi, 44(%rbx)
	jmp	.L17
.L24:
	movq	72(%rsp), %rax
	testb	%r10b, %r10b
	movl	%edx, 56(%rax)
	je	.L1
	jmp	.L21
.L56:
	movq	72(%rsp), %rax
	testb	%r9b, %r9b
	movss	%xmm1, 40(%rax)
	jne	.L24
.L21:
	movq	72(%rsp), %rax
	movl	%r8d, 52(%rax)
	jmp	.L1
	.cfi_endproc
.LFE54:
	.size	conv2d._omp_fn.0, .-conv2d._omp_fn.0
	.p2align 4,,15
	.globl	conv2d
	.type	conv2d, @function
conv2d:
.LFB53:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r15
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
	movl	%edx, %ebp
	movslq	%ecx, %rbx
	leal	(%r9,%rbp), %edi
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	movq	%fs:40, %rax
	movq	%rax, 120(%rsp)
	xorl	%eax, %eax
	movl	%r9d, %eax
	movl	192(%rsp), %edx
	movl	192(%rsp), %r13d
	shrl	$31, %eax
	movq	%rsi, 8(%rsp)
	movl	%ebx, 24(%rsp)
	addl	%r9d, %eax
	movq	%r8, 16(%rsp)
	movss	%xmm0, 28(%rsp)
	sarl	%eax
	shrl	$31, %edx
	addl	%ebx, %r13d
	movl	%eax, (%rsp)
	movl	192(%rsp), %eax
	imull	%r13d, %edi
	addl	%edx, %eax
	movl	%eax, %esi
	movslq	%edi, %rdi
	sarl	%esi
	movl	%esi, 4(%rsp)
	movl	$4, %esi
	call	calloc@PLT
	testq	%rax, %rax
	je	.L62
	testl	%ebp, %ebp
	movq	%rax, %r14
	jle	.L59
	movl	(%rsp), %edx
	movslq	4(%rsp), %rax
	movslq	%r13d, %r12
	salq	$2, %rbx
	salq	$2, %r12
	imull	%r13d, %edx
	xorl	%r13d, %r13d
	movslq	%edx, %rdx
	addq	%rax, %rdx
	leaq	(%r14,%rdx,4), %r9
	.p2align 4,,10
	.p2align 3
.L60:
	movq	%r15, %rsi
	movq	%r9, %rdi
	movq	%rbx, %rdx
	call	memcpy@PLT
	addl	$1, %r13d
	movq	%rax, %r9
	addq	%rbx, %r15
	addq	%r12, %r9
	cmpl	%r13d, %ebp
	jne	.L60
.L59:
	movd	4(%rsp), %xmm1
	movl	192(%rsp), %eax
	leaq	32(%rsp), %rsi
	movd	(%rsp), %xmm0
	leaq	conv2d._omp_fn.0(%rip), %rdi
	xorl	%ecx, %ecx
	movss	28(%rsp), %xmm2
	xorl	%edx, %edx
	punpckldq	%xmm1, %xmm0
	movl	%eax, 68(%rsp)
	movl	24(%rsp), %eax
	movss	%xmm2, 64(%rsp)
	movq	%r14, 48(%rsp)
	movl	%ebp, 56(%rsp)
	movl	$0x00000000, 72(%rsp)
	punpcklqdq	%xmm0, %xmm0
	movq	$0, 108(%rsp)
	movl	%eax, 60(%rsp)
	movups	%xmm0, 92(%rsp)
	movq	8(%rsp), %xmm0
	movhps	16(%rsp), %xmm0
	movaps	%xmm0, 32(%rsp)
	pxor	%xmm0, %xmm0
	movups	%xmm0, 76(%rsp)
	call	GOMP_parallel@PLT
	movq	%r14, %rdi
	call	free@PLT
	xorl	%eax, %eax
.L57:
	movq	120(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L65
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
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
.L62:
	.cfi_restore_state
	movl	$-1, %eax
	jmp	.L57
.L65:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE53:
	.size	conv2d, .-conv2d
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
