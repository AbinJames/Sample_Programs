.model small
        print macro msg
                lea dx,msg
                mov ah,09h
                int 21h
        endm
.data
        msg1 dB "Enter number : $"
        evenm dB 0ah,0dh, "Even$"
        oddm dB 0ah,0dh, "Odd$"
.code
        mov ax,@data
        mov ds,ax
        print msg1
        mov ah,01h
        int 21h
        sub al,48
        shr al,01h
        jc loop1
        print evenm
        jmp loop2
	loop1 : print oddm
	loop2 : mov ah,4ch
        int 21h
 	end