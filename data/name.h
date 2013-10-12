#ifndef NAME_DATA
	#define NAME_DATA
	char letras[] = {
		'\0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};
	#define GET_CHAR(size, character) (letras[(character) - (size)  * 2 + 1])
#endif
