
%macro __i80_byte 2
%ifidn %2,b
	db	(%1)
%elifidn %2,c
	db	(%1)|1
%elifidn %2,d
	db	(%1)|2
%elifidn %2,e
	db	(%1)|3
%elifidn %2,h
	db	(%1)|4
%elifidn %2,l
	db	(%1)|5
%elifidn %2,m
	db	(%1)|6
%elifidn %2,a
	db	(%1)|7
%else
%error invalid combination of opcodes and operands
%endif
%endmacro

%macro __i80_byte3 2
%ifidn %2,b
	db	(%1)
%elifidn %2,c
	db	(%1)|0o10
%elifidn %2,d
	db	(%1)|0o20
%elifidn %2,e
	db	(%1)|0o30
%elifidn %2,h
	db	(%1)|0o40
%elifidn %2,l
	db	(%1)|0o50
%elifidn %2,m
	db	(%1)|0o60
%elifidn %2,a
	db	(%1)|0o70
%else
%error invalid combination of opcodes and operands
%endif
%endmacro

%macro __i80_word 2
%ifidn %2,b
	db	(%1)
%elifidn %2,d
	db	(%1)|0x10
%elifidn %2,h
	db	(%1)|0x20
%elifidn %2,sp
	db	(%1)|0x30
%else
%error invalid combination of opcodes and operands
%endif
%endmacro

%macro __i80_word3 2
%ifidn %2,b
	db	(%1)
%elifidn %2,d
	db	(%1)|0x10
%elifidn %2,h
	db	(%1)|0x20
%else
%error invalid combination of opcodes and operands
%endif
%endmacro

%macro __i80_word2 2
%ifidn %2,b
	db	(%1)
%elifidn %2,d
	db	(%1)|0x10
%else
%error invalid combination of opcodes and operands
%endif
%endmacro

%macro code8086 0
%ifdef __i80_enabled
%undef __i80_enabled
%unmacro nop 0
%unmacro lxi 2
%unmacro stax 1
%unmacro inx 1
%unmacro inr 1
%unmacro dcr 1
%unmacro mvi 2
%unmacro rlc 0
%unmacro dad 1
%unmacro ldax 1
%unmacro dcx 1
%unmacro rrc 0
%unmacro ral 0
%unmacro rar 0
%unmacro shld 1
%unmacro daa 0
%unmacro lhld 1
%unmacro cma 0
%unmacro sta 1
%unmacro stc 0
%unmacro lda 1
%unmacro cmc 0
%unmacro mov 2
%unmacro hlt 0
%unmacro add 1
%unmacro adc 1
%unmacro sub 1
%unmacro sbb 1
%unmacro ana 1
%unmacro xra 1
%unmacro ora 1
%unmacro cmp 1
%unmacro rnz 0
%unmacro rz 0
%unmacro rnc 0
%unmacro rc 0
%unmacro rpo 0
%unmacro rpe 0
%unmacro rp 0
%unmacro rm 0
%unmacro pop 1
%unmacro jnz 1
%unmacro jz 1
%unmacro jnc 1
%unmacro jc 1
%unmacro jpo 1
%unmacro jpe 1
%unmacro jp 1
%unmacro jm 1
%unmacro jmp 1
%unmacro cnz 1
%unmacro cz 1
%unmacro cnc 1
%unmacro cc 1
%unmacro cpo 1
%unmacro cpe 1
%unmacro cp 1
%unmacro cm 1
%unmacro push 1
%unmacro adi 1
%unmacro aci 1
%unmacro sui 1
%unmacro sbi 1
%unmacro ani 1
%unmacro xri 1
%unmacro ori 1
%unmacro cpi 1
%unmacro rst 1
%unmacro ret 0
%unmacro call 1
%unmacro out 1
%unmacro in 1
%unmacro xthl 0
%unmacro pchl 0
%unmacro xchg 0
%unmacro di 0
%unmacro sphl 0
%unmacro ei 0
; 8085 specific
%unmacro rim 0
%unmacro sim 0
; 8085 undocumented
%unmacro dsub 0
%unmacro arhl 0
%unmacro rdel 0
%unmacro ldhi 1
%unmacro ldsi 1
%unmacro rstv 0
%unmacro shlx 0
%unmacro jnui 1
%unmacro lhlx 0
%unmacro jui 1
%endif
%endmacro

%macro code8080 0
%define __i80_enabled

%macro nop 0
	db	0x00
%endmacro

%macro lxi 2
%%value equ %2
	__i80_word 0x01,%1
	dw	%%value
%endmacro

%macro stax 1
	__i80_word2 0x02,%1
%endmacro

%macro inx 1
	__i80_word 0x03,%1
%endmacro

%macro inr 1
	__i80_byte3 0x04,%1
%endmacro

%macro dcr 1
	__i80_byte3 0x05,%1
%endmacro

%macro mvi 2
%%value equ %2
	__i80_byte3 0x06,%1
	db	%%value
%endmacro

%macro rlc 0
	db	0x07
%endmacro

%macro dad 1
	__i80_word 0x09,%1
%endmacro

%macro ldax 1
	__i80_word2 0x0A,%1
%endmacro

%macro dcx 1
	__i80_word 0x0B,%1
%endmacro

%macro rrc 0
	db	0x0F
%endmacro

%macro ral 0
	db	0x17
%endmacro

%macro rar 0
	db	0x1F
%endmacro

%macro shld 1
%%value equ %1
	db	0x22
	dw	%%value
%endmacro

%macro daa 0
	db	0x27
%endmacro

%macro lhld 1
%%value equ %1
	db	0x2A
	dw	%%value
%endmacro

%macro cma 0
	db	0x2F
%endmacro

%macro sta 1
%%value equ %1
	db	0x32
	dw	%%value
%endmacro

%macro stc 0
	db	0x37
%endmacro

%macro lda 1
%%value equ %1
	db	0x3A
	dw	%%value
%endmacro

%macro cmc 0
	db	0x3F
%endmacro

%macro mov 2
%ifidn %1,b
	__i80_byte 0x40,%2
%elifidn %1,c
	__i80_byte 0x40|0o10,%2
%elifidn %1,d
	__i80_byte 0x40|0o20,%2
%elifidn %1,e
	__i80_byte 0x40|0o30,%2
%elifidn %1,h
	__i80_byte 0x40|0o40,%2
%elifidn %1,l
	__i80_byte 0x40|0o50,%2
%elifidn %1,m
%ifnidn %2,m
	__i80_byte 0x40|0o60,%2
%else
%error invalid combination of opcodes and operands
%endif
%elifidn %1,a
	__i80_byte 0x40|0o70,%2
%else
%error invalid combination of opcodes and operands
%endif
%endmacro

%macro hlt 0
	db	0x76
%endmacro

%macro add 1
	__i80_byte 0x80,%1
%endmacro

%macro adc 1
	__i80_byte 0x88,%1
%endmacro

%macro sub 1
	__i80_byte 0x90,%1
%endmacro

%macro sbb 1
	__i80_byte 0x98,%1
%endmacro

%macro ana 1
	__i80_byte 0xA0,%1
%endmacro

%macro xra 1
	__i80_byte 0xA8,%1
%endmacro

%macro ora 1
	__i80_byte 0xB0,%1
%endmacro

%macro cmp 1
	__i80_byte 0xB8,%1
%endmacro

%macro rnz 0
	db	0xC0
%endmacro
%macro rz 0
	db	0xC8
%endmacro
%macro rnc 0
	db	0xD0
%endmacro
%macro rc 0
	db	0xD8
%endmacro
%macro rpo 0
	db	0xE0
%endmacro
%macro rpe 0
	db	0xE8
%endmacro
%macro rp 0
	db	0xF0
%endmacro
%macro rm 0
	db	0xF8
%endmacro

%macro pop 1
%ifidn psw,%1
	db	0xF1
%else
	__i80_word3 0xC1,%1
%endif
%endmacro

%macro jnz 1
%%value equ %1
	db	0xC2
	dw	%%value
%endmacro
%macro jz 1
%%value equ %1
	db	0xCA
	dw	%%value
%endmacro
%macro jnc 1
%%value equ %1
	db	0xD2
	dw	%%value
%endmacro
%macro jc 1
%%value equ %1
	db	0xDA
	dw	%%value
%endmacro
%macro jpo 1
%%value equ %1
	db	0xE2
	dw	%%value
%endmacro
%macro jpe 1
%%value equ %1
	db	0xEA
	dw	%%value
%endmacro
%macro jp 1
%%value equ %1
	db	0xF2
	dw	%%value
%endmacro
%macro jm 1
%%value equ %1
	db	0xFA
	dw	%%value
%endmacro

%macro jmp 1
%%value equ %1
	db	0xC3
	dw	%%value
%endmacro

%macro cnz 1
%%value equ %1
	db	0xC4
	dw	%%value
%endmacro
%macro cz 1
%%value equ %1
	db	0xCC
	dw	%%value
%endmacro
%macro cnc 1
%%value equ %1
	db	0xD4
	dw	%%value
%endmacro
%macro cc 1
%%value equ %1
	db	0xDC
	dw	%%value
%endmacro
%macro cpo 1
%%value equ %1
	db	0xE4
	dw	%%value
%endmacro
%macro cpe 1
%%value equ %1
	db	0xEC
	dw	%%value
%endmacro
%macro cp 1
%%value equ %1
	db	0xF4
	dw	%%value
%endmacro
%macro cm 1
%%value equ %1
	db	0xFC
	dw	%%value
%endmacro

%macro push 1
%ifidn psw,%1
	db	0xF5
%else
	__i80_word3 0xC5,%1
%endif
%endmacro

%macro adi 1
	db	0xC6, %1
%endmacro
%macro aci 1
	db	0xCE, %1
%endmacro
%macro sui 1
	db	0xD6, %1
%endmacro
%macro sbi 1
	db	0xDE, %1
%endmacro
%macro ani 1
	db	0xE6, %1
%endmacro
%macro xri 1
	db	0xEE, %1
%endmacro
%macro ori 1
	db	0xF6, %1
%endmacro
%macro cpi 1
	db	0xFE, %1
%endmacro

%macro rst 1
%if (%1) >= 0 && (%1) < 8
	db	0xC7|((%1)<<3)
%else
%error invalid combination of opcodes and operands
%endif
%endmacro

%macro ret 0
	db	0xC9
%endmacro

%macro call 1
%%value equ %1
	db	0xCD
	dw	%%value
%endmacro

%macro out 1
	db	0xD3, %1
%endmacro

%macro in 1
	db	0xDB, %1
%endmacro

%macro xthl 0
	db	0xE3
%endmacro

%macro pchl 0
	db	0xE9
%endmacro

%macro xchg 0
	db	0xEB
%endmacro

%macro di 0
	db	0xF3
%endmacro

%macro sphl 0
	db	0xF9
%endmacro

%macro ei 0
	db	0xFB
%endmacro

; 8085 specific

%macro rim 0
	db	0x20
%endmacro

%macro sim 0
	db	0x30
%endmacro

; 8085 undocumented

%macro dsub 0
	db	0x08
%endmacro

%macro arhl 0
	db	0x10
%endmacro

%macro rdel 0
	db	0x18
%endmacro

%macro ldhi 1
	db	0x28, %1
%endmacro

%macro ldsi 1
	db	0x38, %1
%endmacro

%macro rstv 0
	db	0xCB
%endmacro

%macro shlx 0
	db	0xD9
%endmacro

%macro jnui 1
%%value equ %1
	db	0xDD
	dw	%%value
%endmacro

%macro lhlx 0
	db	0xED
%endmacro

%macro jui 1
%%value equ %1
	db	0xFD
	dw	%%value
%endmacro

%endmacro
