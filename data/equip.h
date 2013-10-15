#ifndef EQUIP_DATA
#define EQUIP_DATA

#include <stdint.h>

// Definiciones de los tipos de equipamientos
#define	_HULL		0
#define	_MATERIAL	1
#define	_ENGINE		2
#define	_TURRET		3
#define	_WEAPON		4
#define	_AMMO		5
#define _SCANNER	6
#define _ARCD		7
#define _ARCP		8
#define _ARCW		9
#define	_EXTENSION	10
// Macros relacionados
#define ENDEQUIP(_)	((_).head == 0x0005 && (_).equip == 0xFFFF && (_).arg[0] == 0xFFFF && (_).arg[1] == 0x0000)
#define READEQUIP(_)	fread((_), sizeof(equipment), 1, input)
#define MAXEQUIPS	35
// Funciones relacionadas
char *str_equips[] = {
	"HULL",
	"MATERIAL",
	"ENGINE",
	"TURRET",
	"WEAPON",
	"AMMO",
	"SCANNER",
	"ARCD",
	"ARCP",
	"ARCW",
	"EXTENSION"
};
inline char* get_equip(uint16_t id) {
	return str_equips[id];
}
#endif
