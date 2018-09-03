org 0x7c00			;endereço de memória em que o programa será carregado
jmp 0x0000:start 	;far jump - seta cs para 0

;label times 10 db 0
var_a	resb 16
var_b   resb 16

start:
	xor ax, ax		;zera ax, xor é mais rápido que mov
	mov ds, ax		;nao pode ser zerado diretamente
	mov es, ax

    call fazer_leitura
    mov dl, al      ;movendo valor de al, para dl
    add dl, 1

	call printar

	jmp done

printar:
	mov ah, 0       ;modo de video
    mov bh, 12h     ;modo de vga (360x200)
    int 10h

    mov ah, 0xb     ;modo da cor da tela
    mov bh, 0       ;ID paleta de cores
    mov bl, 1h      ;Cor desejada //  azul
    int 10h 

    mov ah, 0xe     ;chamada para printar
    mov al, dl      ;al sera printado, com o conteudo de dl
    mov bh, 0       ;numero da pagina 
    mov bl, 0xf     ;cor da fonte
    int 10h

ret

fazer_leitura:
    mov ah, 0       ;numero da chamada
    int 16h         ;faz a leitura do teclado e atribui em al

ret

prints:
    .loop:
        lodsb       ;bota o character em al;
        cmp al,0            ; var al, *si;                  ;   var al, *di
        je .endloop         ; lodsb(){                      ;   stosb(){
        call printar        ;   al = *si                    ;       *di = al;
        jmp .loop           ;   si++;                       ;       di++;
    .endloop:               ; }                             ;   }

ret

quebra_de_linha:
    mov al, 10
    call printar
    mov al, 13
    call fazer_leitura 

ret

reverter_string:
    mov di,si              ;di guarda o endereço de si, antes de ser inicializada
    xor cx,cx
    .loop1:
        lodsb              ;vai removendo o caracter da string e adicionando em al
        cmp al, 0
        je .endloop1
        inc cl             ;incrementa em cl, que sera o contador, para saber a qnt de caracteres andado;
        push ax            ;coloca na pilha o valor removido da string
        jmp .loop1
    .endloop1:

    .loop2:
        cmp cl, 0
        je .endloop2
        dec cl
        pop ax
        stosb
        jmp .loop2
    .endloop2:

ret

leitura_string:
    xor cx, cx
    .loop3:
        call fazer_leitura
        cmp al, 0x08        ;backspace
        je .backspace
        cmp al, 0x0d        ;return carriage
        je .done
        cmp cl, 50          ;limite para string
        je.loop3

        stosb
        inc cl
        call fazer_leitura

        jmp .loop3

ret

done:
	jmp $		;$ = linha atual

times 510 - ($ - $$) db 0 ; terminar o numero de processos
dw 0xaa55 		;assinatura de boot
