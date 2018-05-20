.model small
.data
 	msg1 dB "hai$"
 	msg2 dB 0ah,0dh, "Welcome$"
.code
 	mov ax,@data
 	mov ds,ax
 
	lea dx,msg1
 	mov ah,09h
 	int 21h
 
	lea dx,msg2
 	mov ah,09h
 	int 21h
 	mov ah,4ch
 	int 21h
end
