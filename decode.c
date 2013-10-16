#ifndef RUNTIME
#define RUNTIME

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include "decode.h"
#include "data/equip.h"
#include "data/name.h"
#include "data/code.h"

int main(int argc, uint8_t **argv) {
	switch (argc) {
		case 3:
			input = fopen(argv[1], "r");
			output = fopen(argv[2], "w+");
			break;
		case 2:
			input = fopen(argv[1], "r");
			output = stdout;
			break;
		default:
			input = stdin;
			output = stdout;
			break;
	}
	if(!input | !output) {
		perror((uint8_t *)strerror(errno));
		exit(-1);
	}
	fread(header, sizeof(uint8_t), 6, input);	// Ignore header
	do_equip();
	do_name();
	do_color();
	do_code();
	fclose(input);
	fclose(output);
	return 1;
}

void do_equip() {
	int i;
	fputs("#EQUIP\n", output);
	for(i = 0, READEQUIP(&equips[i]); !ENDEQUIP(equips[i]) && i < MAXEQUIPS; i++, READEQUIP(&equips[i]));
	cequips = i;
	for(i = 0; i < cequips; i++) {
		fprintf(output, "\t%s\t%i", get_equip(equips[i].equip), equips[i].arg[0]);
		if(equip_args[equips[i].equip] == 2)
			fprintf(output, "\t%i", equips[i].arg[1]);
		fputc('\n', output);
	}
	fputs("#EQUIP\n", output);
}

void do_name() {
	int i;
	uint16_t tNombre;
	uint16_t *iNombre;
	fread(&tNombre, sizeof(uint16_t), 1, input);
	Nombre = calloc(tNombre + 1, sizeof(char));
	iNombre = calloc(tNombre, sizeof(uint16_t));
	fread(iNombre, sizeof(uint16_t), tNombre, input);
	for(i = 0; i<tNombre; i++)
		Nombre[i] = GET_CHAR(tNombre, iNombre[i]);
	Nombre[tNombre + 1] = '\0';
	fprintf(output, "#NAME %s\n", Nombre);
}

void do_color() {
	fread(&rcolor, sizeof(color), 2, input);
	fprintf(output, "#COLOR $%.2X%.2X%.2X\n", rcolor[0].r, rcolor[0].g, rcolor[0].b);
	fprintf(output, "#TCOLOR $%.2X%.2X%.2X\n", rcolor[1].r, rcolor[1].g, rcolor[1].b);
}

void do_code() {
	uint16_t i;
	uint16_t tCode;
	uint16_t lastLabel = 1;
	fputs("#BEGIN\n", output);
	fread(&tCode, sizeof(uint16_t), 1, input);
	tCode++;
	Code = calloc(tCode, sizeof(instruction));
	Labels = calloc(tCode, sizeof(uint16_t));
	fread(Code, sizeof(instruction), tCode, input);
	for(i = 0; i < tCode; i++)
		if((Code[i].opcode >= JMP && Code[i].opcode <= JGE) || Code[i].opcode == CALL || Code[i].opcode == LEX) {
			if(Code[i].opcode == LEX) {
				if(Code[i].arg[0] < 1024)
					Code[i].flags += FMEM;
				else
					Code[i].arg[0] -= 1024;
			}
			if(!Labels[Code[i].arg[0]])
				Labels[Code[i].arg[0]] = lastLabel++;
			Code[i].flags += FLABEL;
		}
	for(i = 0; i < tCode; i++) {
		if(Labels[i])
			fprintf(output, "@L%hX", Labels[i] - 1);
		string_instruction(Code[i]);
	}
}
#endif
