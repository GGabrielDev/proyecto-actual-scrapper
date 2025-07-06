#ifndef LINK_EXTRACTOR_H
#define LINK_EXTRACTOR_H

#include "LinkedList.h"

// Extrae enlaces del contenido HTML y los almacena en la lista pasada.
// Cada URL agregada a la lista es un nuevo char* (debes liberar luego).
void extractLinks(const char* html, LinkedList* outLinks);

#endif // LINK_EXTRACTOR_H
