.model small
.data
	msg1 dB "Denominator : $"
	msg2 dB 0ah,0dh, "Numerator : $"
	msg3 dB 0ah,0dh, "Quotient : $"
	msg4 dB 0ah,0dh, "Remainder : $"
.code
        mov ax,@data
        mov ds,ax

        lea dx,msg1
        mov ah,09h
        int 21h
        mov ah,01h
        int 21h
        sub al,48
        mov bl,al

        lea dx,msg2
        mov ah,09h
        int 21h
        mov ah,01h
        int 21h
        sub al,48 

	mov ah,00
	mov bh,00

        div bl
	aaa
       	mov cx,ax
        
	lea dx,msg3
        mov ah,09h
        int 21h

        add cl,48
        mov dl,cl
        mov ah,02h
        int 21h

	lea dx,msg4
        mov ah,09h
        int 21h

	add ch,48
        mov dl,ch
        mov ah,02h
        int 21h

        mov ah,4ch
        int 21h
end




