#ifndef PERSONA_H
#define PERSONA_H
#include <QString>
class persona
{
private:
   QString nombre,apellido,email,password,telefono,usuario,cate;
   int edad;
public:
    persona();
    bool autentificarse(QString,QString);
    void eliminarUsuario(int);
    bool buscarUsuario(QString);
    bool buscarUsuario(QString,QString);
    QString getApellido();
    QString getCorreo();
    int getEdad();
    QString getNombre();
    QString getPassword();
    QString getTelefono();
    QString getUsuario();
    QString getCat();
    void setApellido(QString);
    void setCorreo(QString);
    void setEdad(int);
    void setNombre(QString);
    void setPassword(QString);
    void setTelefono(QString);
    void setUsuario(QString);
    void setCat(QString);
};

#endif // PERSONA_H
