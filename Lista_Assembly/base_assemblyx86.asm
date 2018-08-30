org ;0x7c00			;endereço de memória em que o programa será carregado
jmp 0x0000:start 	;far jump - seta cs para 0

start:
	xor ax, ax		;zera ax, xor é mais rápido que mov
	mov ds, ax		;nao pode ser zerado diretamente
	mov es, ax

	;código

	jmp done

done:
	jmp $		;$ = linha atual

times 510 - ($ - $$) db 0 ; terminar o numero de processos
dw 0xaa55 		;assinatura de boot