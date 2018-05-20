.model small
        print macro msg
                lea dx,msg
                mov ah,09h
                int 21h
        endm
.data
        msg1 dB "Enter number : $"
        msg2 dB 0ah,0dh, "Square root : $"
	msg3 dB 0ah,0dh, "Not a perfect Square root$"
.code
        mov ax,@data
        mov ds,ax
        print msg1
        mov ah,01h
        int 21h
	mov ah,00
        sub al,48
	mov bh,00
	mov bl,01
	mov cl,00

	loop1 : inc cl
		sub ax,bx
		jc loop3 
		jz loop2		
		add bl,02h
		jmp loop1

	loop2 : print msg2
		add cl,48
		mov ah,02h
		mov dl,cl
		int 21h
		jmp loop4

	loop3 : print msg3

	loop4 :	mov ah,4ch
		int 21h
	end