;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; Mod calls for mod player.
;
; The MOD player was ripped from a shareware game. Its seems to be an 
; updated MOD player to the one I was using previously. Its smaller and 
; faster.
; Ripped, cracked and hacked by TRIPWIRE
;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�

;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; Data kept inside code segment for easy access!
;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
ModFile         db 'a.mod',0             
_init_          dw 2b2bh              
_tdata1_        dw 0                  
_volume_        dw 295dh
_tdata2_        dw 0
_setup_         dw 29bbh
_tdata3_        dw 0
_end_           dw 2a64h
_tdata4_        dw 0

;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; Initalise MOD player
;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
InitMOD         PROC    NEAR
                mov     ax,PLAYERSEG
                mov     cs:[_tdata1_],ax
                mov     cs:[_tdata2_],ax
                mov     cs:[_tdata3_],ax
                mov     cs:[_tdata4_],ax
                ret
InitMOD         ENDP

;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; Play MOD file in background
;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
PlayMOD         PROC    NEAR
                call    dword ptr cs:[_init_]
                mov     ax,00ffh
                push    ax
                push    ax
                push    ax
                push    ax
                call    dword ptr cs:[_volume_]
                pop     ax
                pop     ax
                pop     ax
                pop     ax
                mov     dx,0
                push    cs
                push    dx
                mov     ax,7
                push    ax
                mov     ax,2710h
                push    ax
                mov     ax,0
                push    ax
                mov     ax,4
                push    ax
                push    ax
                mov     ax,cs
                mov     ds,ax
                pop     ax
                lea     dx,ModFile
                push    cs
                push    dx
                call    dword ptr cs:[_setup_]
                pop     ax
                pop     ax
                pop     ax
                pop     ax
                pop     ax
                pop     ax
                pop     ax
                pop     ax
                ret
PlayMOD         ENDP                

;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; Stop playing MOD file
;컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
StopMOD         PROC    NEAR
                call    dword ptr cs:[_end_]
                ret
StopMOD         ENDP
