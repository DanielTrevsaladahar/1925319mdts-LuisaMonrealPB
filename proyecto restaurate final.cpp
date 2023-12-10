#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Estructura para almacenar los datos de un art�culo
struct Articulo {
    string nombre; // Nombre del art�culo
    double precio; // Precio del art�culo
};

// Estructura para almacenar los datos de una orden
struct Orden {
    int numero; // N�mero de ticket
    string vendedor; // Nombre del vendedor
    string fecha; // Fecha de la orden
    vector<Articulo> articulos; // Lista de los art�culos
    double subtotal; // Subtotal de la orden
    double descuento; // Descuento o promoci�n aplicada
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

// Funci�n para mostrar el men� de opciones y leer la opci�n elegida
int menu() {
    int opcion; // Variable para almacenar la opci�n
    cout << "Simulador de punto de venta de un restaurante\n";
    cout << "Men� de opciones:\n";
    cout << "1. Alta de ordenes\n";
    cout << "2. Modificar orden\n";
    cout << "3. Eliminar o cancelar orden\n";
    cout << "4. Lista de ordenes\n";
    cout << "5. Limpiar pantalla\n";
    cout << "6. Salir\n";
    cout << "Ingrese la opci�n deseada: ";
    cin >> opcion; // Leer la opci�n
    return opcion; // Retornar la opci�n
}

// Funci�n para generar un n�mero de ticket �nico
int generarNumeroTicket(vector<Orden> &ordenes) {
    int numero = 1; // Inicializar el n�mero en 1
    bool repetido; // Variable para indicar si el n�mero est� repetido
    do {
        repetido = false; // Asumir que el n�mero no est� repetido
        // Recorrer el vector de ordenes
        for (int i = 0; i < ordenes.size(); i++) {
            // Si el n�mero coincide con el de alguna orden
            if (ordenes[i].numero == numero) {
                repetido = true; // Marcar el n�mero como repetido
                numero++; // Incrementar el n�mero en 1
                break; // Salir del ciclo
            }
        }
    } while (repetido); // Repetir mientras el n�mero est� repetido
    return numero; // Retornar el n�mero
}

// Funci�n para leer los datos de una orden
Orden leerOrden(vector<Orden> &ordenes) {
    Orden orden; // Variable para almacenar la orden
    Articulo articulo; // Variable para almacenar un art�culo
    int n; // Variable para almacenar el n�mero de art�culos
    double porcentajePropina; // Variable para almacenar el porcentaje de propina
    char respuesta; // Variable para almacenar la respuesta del usuario
    orden.numero = generarNumeroTicket(ordenes); // Generar el n�mero de ticket
    cout << "Ingrese el nombre del vendedor: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, orden.vendedor); // Leer el nombre del vendedor
    cout << "Ingrese la fecha de la orden (dd/mm/aaaa): ";
    getline(cin, orden.fecha); // Leer la fecha de la orden
    cout << "Ingrese el n�mero de art�culos: ";
    cin >> n; // Leer el n�mero de art�culos
    // Validar que el n�mero de art�culos sea positivo
    while (n <= 0) {
        cout << "El n�mero de art�culos debe ser mayor que cero. Ingrese de nuevo: ";
        cin >> n; // Leer el n�mero de art�culos
    }
    // Inicializar el subtotal en cero
    orden.subtotal = 0;
    // Leer los datos de cada art�culo
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del art�culo " << i + 1 << ": ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, articulo.nombre); // Leer el nombre del art�culo
        cout << "Ingrese el precio del art�culo " << i + 1 << ": ";
        cin >> articulo.precio; // Leer el precio del art�culo
        // Validar que el precio sea positivo
        while (articulo.precio <= 0) {
            cout << "El precio del art�culo debe ser mayor que cero. Ingrese de nuevo: ";
            cin >> articulo.precio; // Leer el precio del art�culo
        }
        // Agregar el art�culo al vector de art�culos de la orden
        orden.articulos.push_back(articulo);
        // Sumar el precio del art�culo al subtotal de la orden
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
    cout << "Ingrese la opci�n deseada: ";
    cin >> n; // Leer la opci�n
    // Validar que la opci�n sea v�lida
    while (n < 1 || n > 3) {
        cout << "Opci�n inv�lida. Ingrese de nuevo: ";
        cin >> n; // Leer la opci�n
    }
    // Asignar el porcentaje de propina seg�n la opci�n
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
    // Imprimir los datos de los art�culos
    cout << "Art�culos:\n";
    cout << left << setw(20) << "Nombre" << right << setw(10) << "Precio" << "\n";
    // Recorrer el vector de art�culos
    for (int i = 0; i < orden.articulos.size(); i++) {
        // Imprimir el nombre y el precio de cada art�culo
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
    cout << "�Desea imprimir la orden? (S/N): ";
    cin >> respuesta; // Leer la respuesta
    // Si la respuesta es S o s
    if (respuesta == 'S' || respuesta == 's') {
        // Imprimir la orden
    void
	    imprimirOrden(Orden orden);
    }
    return orden; // Retornar la orden
}

// Funci�n para imprimir una orden
void imprimirOrden(Orden orden) {
    // Imprimir los datos generales de la raz�n social del restaurante
    cout << "Restaurante La Buena Mesa\n";
    cout << "Av. Universidad 123, Col. Centro, Monterrey, N.L.\n";
    cout << "Tel. (81) 1234-5678\n";
    cout << "----------------------------------------\n";
    // Imprimir los datos de la orden
    cout << "N�mero de ticket: " << orden.numero << "\n";
    cout << "Nombre del vendedor: " << orden.vendedor << "\n";
    cout << "Fecha: " << orden.fecha << "\n";
    cout << "----------------------------------------\n";
    // Imprimir los datos de los art�culos
    cout << "Art�culos:\n";
    cout << left << setw(20) << "Nombre" << right << setw(10) << "Precio" << "\n";
    // Recorrer el vector de art�culos
    for (int i = 0; i < orden.articulos.size(); i++) {
        // Imprimir el nombre y el precio de cada art�culo
        cout << left << setw(20) << orden.articulos[i].nombre << right << setw(10) << fixed << setprecision(2) << orden.articulos[i].precio << "\n";
    }
    cout << "----------------------------------------\n";
    // Imprimir el subtotal, el descuento, la propina, el impuesto y el total de la orden
    cout << left << setw(20) << endl;}
    
