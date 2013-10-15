at-robots-dissasembler
======================

Transforma archivos .atc (Compilados del Advanced T-Robots 3) en código fuente compatible.

Implementado:
-------------
  * Lee el equipamiento del robot
  * Lee el nombre del robot (**incompleto**)
  * Lee los colores del robot
  * Lee el código del robot
  * Genera los labels correspondientes

Por implementar:
----------------
  * Comentar automáticamente el equipamiento y instrucciones
  * Generar las directivas de variable en lugar de las de ubicación de memoria donde corresponda (*Permitiría ya ser 100% compatible con cualquier binario*).
      Requiere reimplementar parte de la salida de texto del programa.
  * Reparar bugs varios
  * Comentar y documentar el código
  * Mejorar el código para mayor simplicidad
  * Evitar argumentos redundantes (Ceros inútiles)
  * Entender mejor el funcionamiento interno de todo ATR3 y documentarlo
  * Traducir la documentación existente con notas marginales explicando pormentores

Largo plazo:
------------
  * Reimplementar *todo* ATR3 con un IDE decente incluso (¡Hey! ¡Es divertido!)
