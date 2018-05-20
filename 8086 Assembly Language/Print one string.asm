.model small
.data
 	msg1 dB "hai$"
.code
 	mov ax,@data
 	mov ds,ax

	lea dx,msg1
 	mov ah,09h
 	int 21h
 	mov ah,4ch
 	int 21h
end
