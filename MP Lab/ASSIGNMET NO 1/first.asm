%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data

msg db "Counting +ve and -ve elements of an array.",10
msglen equ $-msg
msg1 db "Positive nos. are : "
msglen1 equ $-msg1
msg2 db "Negetive nos. are :  "
msglen2 equ $-msg2

array dq 123456789ABCDDFh,123444400000000Ah,-123444400000000Ah, 7FFFFFFFFFFFFFFFh
pcnt db 0
ncnt db 0
newline db 0xa

section .bss

output resb 1
 
section .txt
global _start
_start:
print msg,msglen

mov rsi,array
mov rcx,05

again:
        bt qword[rsi],63
        jnc pnxt
        inc byte[ncnt]
        jmp pskip
   pnxt: inc byte[pcnt]
   pskip: inc rsi
loop again
print msg1,msglen1
mov al,[pcnt]
call display
print newline,1

print msg2,msglen2
mov al,[ncnt]
call display
print newline,1

mov rax,60
mov rdi,0
Syscall

display:
mov rbx,rax
mov cx,1004h		;16 digits to display and 04 count to rotate
ll6:
rol rbx,cl
mov rdx,rbx
and rdx,0fh
add rdx,30h
cmp rdx,039h
jbe skip4
add rdx,7
skip4:
mov byte[output],dl
push rcx
print output,1
pop rcx
dec ch
jnz ll6
ret


