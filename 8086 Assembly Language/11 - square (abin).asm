.model small
        print macro msg
                lea dx,msg
                mov ah,09h
                int 21h
        endm
.data
        msg1 dB "Enter number : $"
        msg2 dB 0ah,0dh, "Square : $"
.code
        mov ax,@data
        mov ds,ax
        print msg1
        mov ah,01h
        int 21h
        sub al,48
	mov bh,00
	mov bl,al
	mov al,00
	mov ah,00
	mov cl,01

	loop1 : add al,cl
		aaa		
		add cl,02h
		dec bl
		jnz loop1

	mov cx,ax
	print msg2
	mov ah,02h
	add ch,48
	mov dl,ch
	int 21h
	mov ah,02h
	add cl,48
	mov dl,cl
	int 21h
	mov ah,4ch
	int 21h
	end