.model small
	Print macro msg
		lea dx,msg
        	mov ah,09h
        	int 21h
	Endm

        Read macro key
		mov ah,01h
        	int 21h
        	sub al,48
	Endm

        Result macro key2
		div bl
		aaa
        	mov cx,ax

		Print msg3

        	add cl,48
       		mov dl,cl
        	mov ah,02h
        	int 21h

		Print msg4

		add ch,48
        	mov dl,ch
        	mov ah,02h
        	int 21h 	
        Endm
.data
	msg1 dB "Denominator : $"
	msg2 dB 0ah,0dh, "Numerator : $"
	msg3 dB 0ah,0dh, "Quotient : $"
	msg4 dB 0ah,0dh, "Remainder : $"

.code
        mov ax,@data
        mov ds,ax

        Print msg1
        Read key
	mov bl,al

	Print msg2
        Read key
	
	mov ah,00
	mov bh,00	

        Result key2
        mov ah,4ch
        int 21h
        end




