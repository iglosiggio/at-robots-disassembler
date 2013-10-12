#include <stdint.h>
#include <stdio.h>
#ifndef CODE
	#define	CODE
	#define	NOP	0
	#define	MOV	1
	#define	XCHG	2
	#define	ADD	3
	#define	SUB	4
	#define	MUL	5
	#define	DIV	6
	#define	INC	7
	#define	DEC	8
	#define	NEG	9
	#define	SHL	10
	#define	SHR	11
	#define	ROL	12
	#define	ROR	13
	#define	SAL	14
	#define	SAR	15
	#define	NOT	16
	#define	AND	17
	#define	OR	18
	#define	XOR	19
	#define	TEST	20
	#define	CMP	21
	#define	JMP	22
	#define	JE	23
	#define	JNE	24
	#define	JL	25
	#define	JLE	26
	#define	JG	27
	#define	JGE	28
	#define	LOOP	29
	#define	PUSH	30
	#define	POP	31
	#define	IN	32
	#define	OUT	33
	#define	CALL	34
	#define	RET	35
	#define	INT	36
	#define	CLE	37
	#define	STE	38
	#define	CLG	39
	#define	STG	40
	#define	CLL	41
	#define	STL	42
	#define	DLY	43
	#define	SAXF	44
	#define	LAXF	45
	#define	LEX	46
	#define	MSG	47
	#define	FREG	1
	#define	FMEM	2
	#define FLABEL	4
	#define	AX	0
	#define	BX	1
	#define	CX	2
	#define	DC	3
	#define	EX	4
	#define	FX	5
	char* opcodes[] = {
		"NOP", "MOV", "XCHG", "ADD", "SUB", "MUL", "DIV", "INC", "DEC",
		"NEG", "SHL", "SHR", "ROL", "ROR", "SAL", "SAR", "NOT", "AND",
		"OR", "XOR", "TEST", "CMP", "JMP", "JE", "JNE", "JL", "JLE",
		"JG", "JGE", "LOOP", "PUSH", "POP", "IN", "OUT", "CALL", "RET",
		"INT", "CLE", "STE", "CLG", "STG", "CLL", "STL", "DLY", "SAXF",
		"LAXF", "LEX", "MSG"
	};
	const char* registers[] = { "AX", "BX", "CX", "DX", "EX", "FX" };
	void string_arg(uint8_t flags, int shift, uint16_t arg) {
		if(flags & FREG << shift && flags & FMEM << shift)
			printf("[%s]", registers[arg]);
		else if(flags & FMEM << shift)
			printf("[%i]", arg);
		else if(flags & FREG << shift)
			printf("%s", registers[arg]);
		else if(flags & FLABEL << shift)
			printf("@L%X", Labels[arg]);
		else
			printf("%i", arg);
	}
	void string_instruction(instruction i) {
		printf("\t%s\t", opcodes[i.opcode]);
		string_arg(i.flags, 0, i.arg[0]);
		if(i.opcode < JMP || i.opcode > JGE) {
			putchar('\t');
			string_arg(i.flags, 4, i.arg[1]);
		}
		putchar('\n');
	}
#endif
