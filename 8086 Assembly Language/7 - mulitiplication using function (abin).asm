.model small
print macro msg
	lea dx,msg
        mov ah,09h
        int 21h
endm

read macro kb
	mov ah,01h
        int 21h
        sub al,48
endm

result macro h
 	mul bl
	aam
        mov cx,ax
        
	print msg3

        add ch,48
        mov dl,ch
        mov ah,02h
        int 21h

	add cl,48
        mov dl,cl
        mov ah,02h
        int 21h
endm

.data
	msg1 dB "First number : $"
	msg2 dB 0ah,0dh, "Second number : $"
	msg3 dB 0ah,0dh, "Poduct : $"

.code
        mov ax,@data
        mov ds,ax
print msg1
read k1
        
        
        mov bl,al

print msg2
read k2

	mov ah,00
	mov bh,00

       result h

        mov ah,4ch
        int 21h
end




