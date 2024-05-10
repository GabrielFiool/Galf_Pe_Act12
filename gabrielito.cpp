#include "gabrielito.h"

void CargarArchivo(std::vector<Registro>& registros) {
    std::ifstream archivo("datos.txt");
    if (!archivo) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    registros.clear(); // Limpiar registros actuales

    Registro temp;
    while (archivo >> temp.status >> temp.matricula >> temp.ApPat >> temp.ApMat >> temp.Nombre >> temp.Edad >> temp.sexo) {
        registros.push_back(temp);
    }

    archivo.close();
    std::cout << "Archivo cargado correctamente." << std::endl;
}

void AgregarRegistro(std::vector<Registro>& registros) {
    if (registros.size() >= 1500) {
        std::cout << "No se pueden agregar más registros, el límite de 1500 se ha alcanzado." << std::endl;
        return;
    }

    Registro nuevoRegistro;
    std::cout << "Ingrese los datos del nuevo registro:" << std::endl;
    std::cout << "Status (0 o 1): ";
    std::cin >> nuevoRegistro.status;
    std::cout << "Matrícula: ";
    std::cin >> nuevoRegistro.matricula;
    std::cout << "Apellido Paterno: ";
    std::cin >> nuevoRegistro.ApPat;
    std::cout << "Apellido Materno: ";
    std::cin >> nuevoRegistro.ApMat;
    std::cout << "Nombre: ";
    std::cin >> nuevoRegistro.Nombre;
    std::cout << "Edad: ";
    std::cin >> nuevoRegistro.Edad;
    std::cout << "Sexo (M o F): ";
    std::cin >> nuevoRegistro.sexo;

    registros.push_back(nuevoRegistro);
    std::cout << "Registro agregado correctamente." << std::endl;
}

void EliminarRegistro(std::vector<Registro>& registros) {
    int matricula;
    std::cout << "Ingrese la matrícula del registro a eliminar: ";
    std::cin >> matricula;

    auto it = std::find_if(registros.begin(), registros.end(), [matricula](const Registro& reg) {
        return reg.matricula == matricula;
    });

    if (it != registros.end()) {
        registros.erase(it);
        std::cout << "Registro eliminado correctamente." << std::endl;
    } else {
        std::cout << "No se encontró ningún registro con esa matrícula." << std::endl;
    }
}

void BuscarRegistro(const std::vector<Registro>& registros) {
    int matricula;
    std::cout << "Ingrese la matrícula a buscar: ";
    std::cin >> matricula;

    auto it = std::find_if(registros.begin(), registros.end(), [matricula](const Registro& reg) {
        return reg.matricula == matricula;
    });

    if (it != registros.end()) {
        std::cout << "Registro encontrado:" << std::endl;
        std::cout << "Status: " << it->status << std::endl;
        std::cout << "Matrícula: " << it->matricula << std::endl;
        std::cout << "Apellido Paterno: " << it->ApPat << std::endl;
        std::cout << "Apellido Materno: " << it->ApMat << std::endl;
        std::cout << "Nombre: " << it->Nombre << std::endl;
        std::cout << "Edad: " << it->Edad << std::endl;
        std::cout << "Sexo: " << it->sexo << std::endl;
    } else {
        std::cout << "No se encontró ningún registro con esa matrícula." << std::endl;
    }
}

void OrdenarRegistros(std::vector<Registro>& registros) {
    std::sort(registros.begin(), registros.end(), [](const Registro& a, const Registro& b) {
        return a.matricula < b.matricula;
    });
    std::cout << "Registros ordenados por matrícula." << std::endl;
}

void MostrarRegistros(const std::vector<Registro>& registros) {
    std::cout << "Mostrando todos los registros:" << std::endl;
    for (const auto& reg : registros) {
        std::cout << "Status: " << reg.status << std::endl;
        std::cout << "Matrícula: " << reg.matricula << std::endl;
        std::cout << "Apellido Paterno: " << reg.ApPat << std::endl;
        std::cout << "Apellido Materno: " << reg.ApMat << std::endl;
        std::cout << "Nombre: " << reg.Nombre << std::endl;
        std::cout << "Edad: " << reg.Edad << std::endl;
        std::cout << "Sexo: " << reg.sexo << std::endl;
    }
}

void GenerarArchivo(const std::vector<Registro>& registros) {
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo (sin extensión): ";
    std::cin >> nombreArchivo;

    std::ofstream archivo(nombreArchivo + ".txt");
    if (!archivo) {
        std::cout << "Error al crear el archivo." << std::endl;
        return;
    }

    for (const auto& reg : registros) {
        archivo << reg.status << " " << reg.matricula << " " << reg.ApPat << " " << reg.ApMat << " "
                << reg.Nombre << " " << reg.Edad << " " << reg.sexo << std::endl;
    }

    archivo.close();
    std::cout << "Archivo generado correctamente." << std::endl;
}
