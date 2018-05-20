.model small
.data
msg1 dB "First number : $"
msg2 dB 0ah,0dh, "Second number : $"
msg3 dB 0ah,0dh, "Result : $"

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

        add al,bl
        mov cl,al
        

	lea dx,msg3
        mov ah,09h
        int 21h
add cl,48
        mov dl,cl
        mov ah,02h
        int 21h
        mov ah,4ch
        int 21h
        end




