.model small
        print macro msg
                lea dx,msg
                mov ah,09h
                int 21h
        endm
.data
        msg1 dB "Enter number : $"
        one dB 0ah,0dh, "Number of 1's : $"
        zero dB 0ah,0dh, "Number of 0's : $"
.code
        mov ax,@data
        mov ds,ax
        print msg1
        mov ah,01h
        int 21h
        sub al,30h
	mov cl,08h
	mov bx,00h

	loop2 : shr al,01h
	jc loop1
	inc bl
	jmp loop3

	loop1 : inc bh
	loop3 : dec cl
	       jnz loop2

	print one
	mov ah,02h
	add bh,30h
	mov dl,bh
	int 21h

	print zero
	add bl,30h
	mov ah,02h
	mov dl,bl
	int 21h

	mov ah,4ch
	int 21h
	end