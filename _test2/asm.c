#include <stdio.h>

void 
set_fpu (unsigned int mode)
{
  asm ("fldcw %0" : : "m" (*&mode));
}

int
main (void)
{
  double a = 3.0, b = 7.0, c;
#ifdef DOUBLE       /* ActivaciÃ³n de uso */
  set_fpu (0x27F);  /* de redondeo en */
#endif              /* doble precisiÃ³n */
  c = a / b;

  if (c == a / b) {
    printf ("comparaciÃ³n exitosa\n");
  } else {
    printf ("resultado inesperado\n");
  }
  return 0;
}
