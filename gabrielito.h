#ifndef GABRIELITO_H
#define GABRIELITO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Registro {
    bool status;
    int matricula;
    std::string ApPat;
    std::string ApMat;
    std::string Nombre;
    int Edad;
    char sexo;
};

void CargarArchivo(std::vector<Registro>& registros);
void AgregarRegistro(std::vector<Registro>& registros);
void EliminarRegistro(std::vector<Registro>& registros);
void BuscarRegistro(const std::vector<Registro>& registros);
void OrdenarRegistros(std::vector<Registro>& registros);
void MostrarRegistros(const std::vector<Registro>& registros);
void GenerarArchivo(const std::vector<Registro>& registros);

#endif // GABRIELITO_H
