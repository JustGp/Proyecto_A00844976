# Ejercicio - Hello World


# Mermaid class

```mermaid
classDiagram
class Unidad {
    - int vida
    - int hpoints
    - int ataque
    - int nivel

    + Unidad()
    + Unidad(int, int, int, int)

    + int getVida() const
    + int getHpoints() const
    + int getAtaque() const
    + int getNivel() const

    + void setVida(int)
    + void setHpoints(int)
    + void setAtaque(int)
    + void setNivel(int)

    + int porcentajeSalud()
    + void imprimirBarra()
    + int calculaAtaque(Unidad&)
    + void recibeAtaque(int)
    + void atacar(Unidad&)
    + void imprimir()

    + void vidaInicial()
}

```






Este proyecto tiene la estructura básica para cualquier proyecto C++. 

La carpeta contiene el código fuente y el archivo de construcción ```make```.

La carpeta `build` contiene el codigo binario generado por el archivo de construcción ```make```.

Consulta el archivo assignments/README.md para instrucciones sobre la compilación y ejecución del proyecto.