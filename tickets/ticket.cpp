#include <cstdlib>
#include<iostream>
using namespace std;
typedef struct 
{
	int id;
	char origen[50];
	char destino[50];
	float price;
} priceTicket;
typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
 int idF;
 date dateF;
 int idhorario;
 int cantT;
 float price;
 priceTicket ticket;
}factura;

priceTicket pt[14];
 
 /*Funcioces
 1. add destiny
 2. edit destiny
 3. search destiny
 4. add Factura
 5. mostar monto del dia
 6. mostrar monto por fecha*/

void calculadora();

int main(){
	calculadora();
}

void calculadora() {
	int cantidad, sentido = 0, viaje = 0;
	float total;
	do{
		cout << "Asignar pasajes\n";
		cout << "Por favor selecione su ruta " << endl;
		cout << "1. Nagarote-Managua" << endl;
		cout << "2. Managua-Nagarote" << endl;
		cout << "3. Salir" << endl;
		cout << "Digite la Opcion: " << endl;
		cin >> sentido;

		switch (sentido){
			case 1:
				do{
					cout << "Cual es el Destino?" << endl;
					cout << "1. Nagarote - Managua" << endl;
					cout << "2. Nagarote - Cementera Holcim" << endl;
					cout << "3. Nagarote - Zona Franca" << endl;
					cout << "4. Mateare - Zona Franca" << endl;
					cout << "5. Mateare - Managua" << endl;
					cout << "6. Ciudad Sandino - Managua" << endl;
					cout << "7. Origen y Destino Variable" << endl;
					cout << "8. Salir de este menu" <<endl;
					cout << "Digite el destino como se indica en las opciones: " << endl;
					cin >> viaje;
				
					switch(viaje) {
						case 1:
							float costoPasaje;
							cout<<"Ingrese el precio actual del pasaje: ";
							cin>> costoPasaje;
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*costoPasaje;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 2:
							
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*10.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 3:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*16.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 4:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*10.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 5:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*13.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 6:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*8.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 7:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*20.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						default:
							cout<<"Opción incorrecta, vuelve a intentar"<<endl;
							system("pause");
							break;
					}
				}while(viaje!=8);
				break;

			case 2:
				do{
					cout << "Cual es el Destino?" << endl;
					cout << "1. Managua - Nagarote" << endl;
					cout << "2. Managua - Mateare" << endl;
					cout << "3. Managua - Km21" << endl;
					cout << "4. Managua - Ciudad Doral" << endl;
					cout << "5. Managua - Los Brasiles" << endl;
					cout << "6. Ciudad Sandino - Mateare" << endl;
					cout << "7. Origen y Destino Variable" << endl;
					cout << "8. Salir de este menu" <<endl;
					cout << "Digite el destino como se indica en las opciones: " << endl;
					cin >> viaje;
					switch (viaje) {
						case 1:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*23.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 2:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*13.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 3:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*12.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 4:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*10.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 5:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*9.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						case 6:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*8.00;
							cout << "El precio total sera de " << total << endl;
							system("pause"); 
							break;
						case 7:
							cout << "Dime la cantidad de Pasajes: " << endl;
							cin >> cantidad;
							total = cantidad*20.00;
							cout << "El precio total sera de " << total << endl;
							system("pause");
							break;
						default:
							cout<<"Opción incorrecta, vuelve a intentar"<<endl;
							system("pause");
							break;
					}
					
				}while(viaje !=8);
				break;
				
			case 3:
				cout<<"Adios"<<endl;
				break;
			
			default:
				cout<<"Opción incorrecta, vuelve a intentar"<<endl;
				system("pause");
				break;
		}
	}while(sentido != 3);
}