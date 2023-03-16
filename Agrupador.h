#ifndef _AGRUPADOR
#define _AGRUPADOR
#include "Grupo.h"

class Agrupador {
   public:
      virtual ~Agrupador(){};
      virtual Grupo * agrupar(const Grupo&) = 0;
};
#endif
