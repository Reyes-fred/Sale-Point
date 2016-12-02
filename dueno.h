#ifndef DUENO_H
#define DUENO_H
#include "persona.h"
class dueno:public persona
{
public:
    dueno();
    bool buscarEmpleado();
    void eliminarEmpleado();
    void nuevoEmpleado();
};

#endif // DUENO_H
