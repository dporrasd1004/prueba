#ifndef FRASE_H 
#define FRASE_H
#include <string>
#include "palabra.h"
class Frase: public Palabra {
public: 
     Frase();
     void iniArchivo();
     void agregarFrases();
     void leerArchivo();
     void cuentaPalabra();
     void buscaPalabra();
     void reemplazar();
     void encriptaFrases();
     void desencriptaFrases();
     void alineaDerecha();
     void alineaIzquierda();
     void alineaCentro();
     void convertirarchivo(); 
     void justificaFrase();      
  
};
#endif

