; ************************************************************************************************
; ************************************************************************************************
;
;		Name:		time.asm
;		Purpose:	Return time in cs
;		Created:	11th December 2023
;		Reviewed:   No
;		Author:		Paul Robson (paul@robsons.org.uk)
;
; ************************************************************************************************
; ************************************************************************************************

; ************************************************************************************************
;
;										Return time in cs
;
; ************************************************************************************************

		.section code	

EXPUnaryTime: ;; [time(]
		jsr 	ERRCheckRParen 					; )

		lda 	#1 								; read timer
		sta 	ControlFunction
		sta 	ControlCommand
		
		lda 	ControlPort+4 					; return as integer
		sta 	XSNumber0,x
		lda 	ControlPort+5
		sta 	XSNumber1,x
		lda 	ControlPort+6
		sta 	XSNumber2,x
		lda 	ControlPort+7
		sta 	XSNumber3,x
		stz 	XSControl,x
		rts

		.send code

				
; ************************************************************************************************
;
;									Changes and Updates
;
; ************************************************************************************************
;
;		Date			Notes
;		==== 			=====
;
; ************************************************************************************************
