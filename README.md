at-robots-dissasembler
======================

Transforma ["archivos .atc"](https://github.com/iglosiggio/at-robots-disassembler/wiki/Estructura-del-.atc) (Compilados del Advanced T-Robots 3) en código fuente compatible.

Compilarlo
==========

Actualmente no está encarado de forma seria, por lo que compilarlo simplemente es `gcc -o decode decode.c`

Uso
===

El uso es por consola, en el formato `decode [origen] [destino]`, en caso de no ser suplida la salida
se utilizará la salida estándar, en caso de nos er suplido ninguno de los dos se utilizará
tanto la entrada como la salida estándar

Implementado (_"Decompila" las siguientes cosas_):
--------------------------------------------------

  * El equipamiento del robot
  * El nombre del robot (**incompleto, faltan caracteres**)
  * Los colores del robot
  * El código símil-asm del robot
  * Genera los labels correspondientes
  * Evita argumentos redundantes (ceros inútiles que *si* aparecen en el binario)

Por implementar:
----------------
  * [**IMPORTANTE**] Comentar automáticamente el equipamiento y instrucciones
  * [**IMPORTANTE**] Generar las directivas de variable en lugar de las de ubicación de memoria donde corresponda (*Permitiría ya ser 100% compatible con cualquier binario*)
      PD: _Posiblemente requiera reimplementar parte de la salida de texto del programa_
  * [**IMPORTANTE**] Mejorar soporte de caracteres no-alfanuméricos en el nombre
  * [_ÚTIL_] Mejorar la interfaz de consola agregando más opciones (resolver/no resolver variables, comentar, datos estadísticos, etc)
  * [MENOR] Mejorar el código para mayor simplicidad
  * [MENOR] Comentar y documentar el código
  * [MENOR] Entender mejor el funcionamiento interno de todo ATR3 y documentarlo
  * [MENOR] Traducir la documentación existente con notas marginales explicando pormenores

Largo plazo:
------------
  * Reimplementar *todo* ATR3 con un IDE decente incluso (¡Hey! ¡Es divertido!)
