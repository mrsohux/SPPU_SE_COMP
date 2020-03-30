%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro
%macro read 2 
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro
%macro Menu 0
print msg4,msg4len
print msg4,msg4len
print msg1,msg1len
print msg2,msg2len
print msg5,msg5len
print msg3,msg3len

read num_ascii,2
print msg4,msg4len
%endmacro

section .bss
num_ascii resb 06
opbuff resb 05
dnumbuff resb 08


section .data
wrchmsg db 10,10,'lnvalid choice....Please try again!!!',10,10
wrchmsg_len equ $-wrchmsg ;wrong choice message and its length

hexinmsg db 10,10,'Enter a 4 digit hex number:'
hexinmsg_len equ $-hexinmsg ;message for hex number and its length

bcdopmsg db 10,10,'lts BCD Equivalent:'
bcdopmsg_len equ $-bcdopmsg ;message for BCD number and its length

bcdinmsg db 10,10,'Enter 5 digit BCD number:'
bcdinmsg_len equ $-bcdinmsg

hexopmsg db 10,10,'lts Hex Equivalent:'
hexopmsg_len equ $-hexopmsg

msg1 db '1 : BCD -> HEX ',10,13
msg1len equ $-msg1

msg2 db '2 : HEX -> BCD ',10,13
msg2len equ $-msg2

msg5 db '3 : Exit ',10,13
msg5len equ $-msg5

msg3 db 'Enter Choice : '
msg3len equ $-msg3

msg4 db '',10
msg4len equ $-msg4


section .txt
global _start
_start:

	Menu
	case1:
	cmp byte[num_ascii],'1'
	jne case2
	call bcd2hex_proc
	jmp _start
	
	case2:
	cmp byte[num_ascii],'2'
	jne case3
	call hex2bcd_proc
	jmp _start
	
	case3:
	cmp byte[num_ascii],'3'
	je exit


	exit:
	mov rax,60
	xor rdi,rdi
	syscall
	
	hex2bcd_proc:
	print  hexinmsg,hexinmsg_len
	read num_ascii,5
	call packnum
	mov rcx,0
	mov ax,bx
	mov bx,10

	
	h2bup1:
	mov dx,0
	div bx
	push rdx
	inc rcx
	cmp ax,0
	jne h2bup1
	mov rdi,opbuff

	h2bup2:
	pop rdx
	add dl,30h
	mov [rdi],dl
	inc rdi
	loop h2bup2
	
	print bcdopmsg,bcdopmsg_len
	print opbuff,5
	ret
	
	bcd2hex_proc:

	print bcdinmsg, bcdinmsg_len
	read num_ascii,6
	print hexopmsg, hexopmsg_len
	mov rsi,num_ascii
	mov rcx,05
	mov rax,0
	mov rbx,0ah


	b2hup1:
	mov rdx,0
	mul rbx 
	mov dl,[rsi]
	sub dl,30h
	add rax,rdx
	inc rsi
	loop b2hup1
	mov rbx,rax
	call disp32_num
	ret

	packnum:

	mov bx,0
	mov rcx,04
	mov rsi,num_ascii
	
	up1:
	rol bx,04
	mov al,[rsi]
	cmp al,39h
	jbe skip1
	sub al,07h


	skip1:
	sub al,30h
	add bl,al
	inc rsi
	loop up1
	ret

	disp32_num:
	mov rdi,dnumbuff 
	mov rcx,08 

	dispup1:
	rol ebx,4 
	mov dl,bl 
	and dl,0fh
	add dl,30h
	cmp dl,39h
	jbe dispskipl
	add dl,07h

	dispskipl:
	mov [rdi],dl 
	inc rdi
	loop dispup1
	print dnumbuff+3,5

	ret
	

