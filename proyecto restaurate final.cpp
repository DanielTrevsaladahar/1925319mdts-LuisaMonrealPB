#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Estructura para almacenar los datos de un artículo
struct Articulo {
    string nombre; // Nombre del artículo
    double precio; // Precio del artículo
};

// Estructura para almacenar los datos de una orden
struct Orden {
    int numero; // Número de ticket
    string vendedor; // Nombre del vendedor
    string fecha; // Fecha de la orden
    vector<Articulo> articulos; // Lista de los artículos
    double subtotal; // Subtotal de la orden
    double descuento; // Descuento o promoción aplicada
    double propina; // Propina sobre el subtotal
    double impuesto; // Impuesto sobre el subtotal
    double total; // Total de la orden
    bool cancelada; // Indica si la orden fue cancelada
};

// Constantes para los porcentajes de propina, impuesto y descuento
const double PROPINA_10 = 0.1;
const double PROPINA_15 = 0.15;
const double PROPINA_20 = 0.2;
const double IMPUESTO = 0.16;
const double DESCUENTO = 0.1;

// Función para mostrar el menú de opciones y leer la opción elegida
int menu() {
    int opcion; // Variable para almacenar la opción
    cout << "Simulador de punto de venta de un restaurante\n";
    cout << "Menú de opciones:\n";
    cout << "1. Alta de ordenes\n";
    cout << "2. Modificar orden\n";
    cout << "3. Eliminar o cancelar orden\n";
    cout << "4. Lista de ordenes\n";
    cout << "5. Limpiar pantalla\n";
    cout << "6. Salir\n";
    cout << "Ingrese la opción deseada: ";
    cin >> opcion; // Leer la opción
    return opcion; // Retornar la opción
}

// Función para generar un número de ticket único
int generarNumeroTicket(vector<Orden> &ordenes) {
    int numero = 1; // Inicializar el número en 1
    bool repetido; // Variable para indicar si el número está repetido
    do {
        repetido = false; // Asumir que el número no está repetido
        // Recorrer el vector de ordenes
        for (int i = 0; i < ordenes.size(); i++) {
            // Si el número coincide con el de alguna orden
            if (ordenes[i].numero == numero) {
                repetido = true; // Marcar el número como repetido
                numero++; // Incrementar el número en 1
                break; // Salir del ciclo
            }
        }
    } while (repetido); // Repetir mientras el número esté repetido
    return numero; // Retornar el número
}

// Función para leer los datos de una orden
Orden leerOrden(vector<Orden> &ordenes) {
    Orden orden; // Variable para almacenar la orden
    Articulo articulo; // Variable para almacenar un artículo
    int n; // Variable para almacenar el número de artículos
    double porcentajePropina; // Variable para almacenar el porcentaje de propina
    char respuesta; // Variable para almacenar la respuesta del usuario
    orden.numero = generarNumeroTicket(ordenes); // Generar el número de ticket
    cout << "Ingrese el nombre del vendedor: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, orden.vendedor); // Leer el nombre del vendedor
    cout << "Ingrese la fecha de la orden (dd/mm/aaaa): ";
    getline(cin, orden.fecha); // Leer la fecha de la orden
    cout << "Ingrese el número de artículos: ";
    cin >> n; // Leer el número de artículos
    // Validar que el número de artículos sea positivo
    while (n <= 0) {
        cout << "El número de artículos debe ser mayor que cero. Ingrese de nuevo: ";
        cin >> n; // Leer el número de artículos
    }
    // Inicializar el subtotal en cero
    orden.subtotal = 0;
    // Leer los datos de cada artículo
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del artículo " << i + 1 << ": ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, articulo.nombre); // Leer el nombre del artículo
        cout << "Ingrese el precio del artículo " << i + 1 << ": ";
        cin >> articulo.precio; // Leer el precio del artículo
        // Validar que el precio sea positivo
        while (articulo.precio <= 0) {
            cout << "El precio del artículo debe ser mayor que cero. Ingrese de nuevo: ";
            cin >> articulo.precio; // Leer el precio del artículo
        }
        // Agregar el artículo al vector de artículos de la orden
        orden.articulos.push_back(articulo);
        // Sumar el precio del artículo al subtotal de la orden
        orden.subtotal += articulo.precio;
    }
    // Aplicar el descuento si el subtotal es mayor o igual que 500
    if (orden.subtotal >= 500) {
        orden.descuento = orden.subtotal * DESCUENTO; // Calcular el descuento
    }
    else {
        orden.descuento = 0; // No hay descuento
    }
    // Mostrar las opciones de propina
    cout << "Seleccione el porcentaje de propina:\n";
    cout << "1. 10%\n";
    cout << "2. 15%\n";
    cout << "3. 20%\n";
    cout << "Ingrese la opción deseada: ";
    cin >> n; // Leer la opción
    // Validar que la opción sea válida
    while (n < 1 || n > 3) {
        cout << "Opción inválida. Ingrese de nuevo: ";
        cin >> n; // Leer la opción
    }
    // Asignar el porcentaje de propina según la opción
    switch (n) {
        case 1:
            porcentajePropina = PROPINA_10;
            break;
        case 2:
            porcentajePropina = PROPINA_15;
            break;
        case 3:
            porcentajePropina = PROPINA_20;
            break;
    }
    // Imprimir los datos de los artículos
    cout << "Artículos:\n";
    cout << left << setw(20) << "Nombre" << right << setw(10) << "Precio" << "\n";
    // Recorrer el vector de artículos
    for (int i = 0; i < orden.articulos.size(); i++) {
        // Imprimir el nombre y el precio de cada artículo
        cout << left << setw(20) << orden.articulos[i].nombre << right << setw(10) << fixed << setprecision(2) << orden.articulos[i].precio << "\n";
    }
    cout << "----------------------------------------\n";
    // Imprimir el subtotal, el descuento, la propina, el impuesto y el total de la orden
    cout << left << setw(20) << endl;}
    void Archivos()
{
ofstream archivo; 
    string nombrearchivo;
    nombrearchivo = "Montivirdi Pizza";
    archivo.open(nombrearchivo.c_str(), ios::binary);
    if (archivo.fail())
    {
        cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
        exit(1);
    }
    archivo <<"numero"<< "\t";
    archivo << "vendedor" << "\t";
    archivo << "fecha" << "\t";
    archivo << "articulos" << "\t";
    archivo << "subtotal" << "\t";
    archivo << "descuento" << "\t";
    archivo << "propina" << "\t";
    archivo << "Impuesto" << "\n";
    archivo << "total ventas" << "\n";
	// Calcular la propina sobre el subtotal
    orden.propina = orden.subtotal * porcentajePropina;
    // Calcular el impuesto sobre el subtotal
    orden.impuesto = orden.subtotal * IMPUESTO;
    // Calcular el total de la orden
    orden.total = orden.subtotal - orden.descuento + orden.propina + orden.impuesto;
    // Inicializar la orden como no cancelada
    orden.cancelada = false;
    // Preguntar al usuario si desea imprimir la orden
    cout << "¿Desea imprimir la orden? (S/N): ";
    cin >> respuesta; // Leer la respuesta
    // Si la respuesta es S o s
    if (respuesta == 'S' || respuesta == 's') {
        // Imprimir la orden
    void
	    imprimirOrden(Orden orden);
    }
    return orden; // Retornar la orden
}

// Función para imprimir una orden
void imprimirOrden(Orden orden) {
    // Imprimir los datos generales de la razón social del restaurante
    cout << "Restaurante La Buena Mesa\n";
    cout << "Av. Universidad 123, Col. Centro, Monterrey, N.L.\n";
    cout << "Tel. (81) 1234-5678\n";
    cout << "----------------------------------------\n";
    // Imprimir los datos de la orden
    cout << "Número de ticket: " << orden.numero << "\n";
    cout << "Nombre del vendedor: " << orden.vendedor << "\n";
    cout << "Fecha: " << orden.fecha << "\n";
    cout << "----------------------------------------\n";
    // Imprimir los datos de los artículos
    cout << "Artículos:\n";
    cout << left << setw(20) << "Nombre" << right << setw(10) << "Precio" << "\n";
    // Recorrer el vector de artículos
    for (int i = 0; i < orden.articulos.size(); i++) {
        // Imprimir el nombre y el precio de cada artículo
        cout << left << setw(20) << orden.articulos[i].nombre << right << setw(10) << fixed << setprecision(2) << orden.articulos[i].precio << "\n";
    }
    cout << "----------------------------------------\n";
    // Imprimir el subtotal, el descuento, la propina, el impuesto y el total de la orden
    cout << left << setw(20) << endl;}
    
