;
; blinkinglight.asm
;
; Created: 9/22/2021 6:11:59 AM
; Author : Amar
;
.include "m328pdef.inc" 
.org 0x0000
           RJMP begin; jump to begin  
.org 0x0034 
 begin:    CLI
           LDI    R16,low(RAMEND)
         OUT    SPL,R16
           LDI     R16,high(RAMEND)
         OUT    SPH, R16                
         LDI    R16                                                            ,0xFF 
         OUT    DDRD, R16   

;constants, 
.equ c1 = 100 ; Define number of loop executions as a constant
.equ c2 = 100 ; Define number of loop executions as a constant
.equ c3 = 100 ; Define number of loop executions as a constant

main_loop:
           LDI     R16,0xFF 
         OUT    PORTD, R16

		 RCALL  DELAY
           LDI     R16,0x00
         OUT     PORTD, R16
           RCALL  DELAY
          rjmp main_loop       
           

DELAY:	;.equ c1 = 100 ; Define number of loop executions as a constant
		ldi R30,c1 ; Instruction: load a register with this constant
		Loop1: ; Loop starts
		
			
		    ldi R31,c2 ; Instruction: load a register with this constant
		    Loop2: ; Loop starts

			    ldi R29,c3 ; Instruction: load a register with this constant
				Loop3: ; Loop starts
     			dec R29 ; Instruction: Decrease register value by one, if zero set Z flag in SREG
				brne Loop3 ; Instruction: if not zero jump to label Loop:, otherwise continue, uses Z in SREG

     		dec R31 ; Instruction: Decrease register value by one, if zero set Z flag in SREG
			brne Loop2 ; Instruction: if not zero jump to label Loop:, otherwise continue, uses Z in SREG
		dec R30 ; Instruction: Decrease register value by one, if zero set Z flag in SREG
		brne Loop1 ; Instruction: if not zero jump to label Loop:, otherwise continue, uses Z in SREG
     RET

