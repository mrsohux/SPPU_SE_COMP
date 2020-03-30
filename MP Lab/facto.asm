Section .data
    msg1 db 10,'Program for Factorial',10
    len1 equ $-msg1
    msg2 db 10,'Enter Two no',10
    len2 equ $-msg2
      msg3 db 10,'Factorial is:',10
    len3 equ $-msg3
    nxline db 10
    blankspace db ' ',10
    len4 equ $-blankspace
factorial dq 1
Section .bss
   numascii resb 3
   multi1 resb 2
   res1 resb 2
   disbuff resb 4

%macro display 2
   mov rax,1
   mov rdi,1
   mov rsi,%1
   mov rdx,%2
   syscall
%endmacro

%macro accept 2
   mov rax,0
   mov rdi,0
   mov rsi,%1
   mov rdx,%2
   syscall
%endmacro

Section .text

global _start
_start:
display msg1,len1
display msg2,len2
accept numascii,3
call packnum
mov [multi1],bl
mov rcx,[multi1]
call facto
mov rax,0
display msg3,len3

mov rbx,qword[factorial]
call disp16 
mov rax,60
	
syscall

facto:
push rcx
cmp rcx,01
jne ahead
jmp exit2
ahead: dec rcx
call facto
exit2:
pop rcx
mov rax,rcx
mul qword[factorial]
mov qword[factorial],rax
ret

packnum:
   mov bl,0
   mov rcx,2
   mov rsi,numascii
 
up1:
   rol bl,04
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
 
 disp16:
    mov rcx,4
   mov rdi,disbuff
   dup1:
   rol bx,4
   mov al,bl
   and al,0fh
   cmp al,09           
   jbe dskip
   add al,07h
   dskip:
   add al,30h
   mov [rdi],al
   inc rdi
   loop dup1
   display disbuff,4
   display nxline,1
   ret
