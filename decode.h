#ifndef RUNTIME_HEADER
#define RUNTIME_HEADER
#include "data/equip.h"

void do_equip();
void do_name();
void do_color();
void do_code();
int main(int argc, uint8_t **argv);

FILE *input;
FILE *output;

uint8_t header[6];

int cequips;
typedef struct {
	uint16_t head;
	uint16_t equip;
	uint16_t arg[2];
} equipment;
equipment equips[MAXEQUIPS];

char *Nombre;

typedef struct {
	uint8_t b;
	uint8_t g;
	uint8_t r;
	uint8_t end;
} color;
color rcolor[2];

typedef struct {
	uint8_t opcode;
	uint8_t flags;
	uint16_t arg[2];
} instruction;
instruction *Code;
#endif
