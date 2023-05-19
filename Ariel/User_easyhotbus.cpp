#include <iostream>
#include <stdio.h>
#include <string.h>
#include "auxiliar.h"
#define MAX 100
using namespace std;

typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    char idUse[9];
    char name[30];
    char lastname[30];
    date birth;
    char idCard[16];
    int Bus;
    char job[15];
    float Salary;
} Username;

Username Users[MAX];
int lastReg = 0;

/*USER*/
    /*Create*/
    void addUser(Username use);
    /*Read*/
    void showUser(int pos);
    int isUser(char id[]);
    void showUsers();
    void startUser(int pos);
    Username getUser(int pos);
    /*Update*/
    void updateUser(Username use, int pos);
    /*Delete*/
    void deleteUser(int pos);
    /*Menu User*/
    int menuUser();
    void startUse();
    /*Archivos User*/
    FILE *UserRegistration;
    void saveUser();
    void readUser();
    int calcUltReg(FILE *archivo);

void addUser(Username use){
    Users[lastReg] = use;
    lastReg++;
}

void showUser(int pos)
{
    gotoxy(10,5);
    cout << "ID: " << Users[pos].idUse << endl;
    gotoxy(10,6);
    cout << "NOMBRE: " << Users[pos].name << endl;
    gotoxy(10,7);
    cout << "APELLIDOS: " << Users[pos].lastname << endl;
    gotoxy(10,8);
    cout << "FECHA DE NACIMIENTO: " << Users[pos].birth.day << "/" << Users[pos].birth.month << "/" << Users[pos].birth.year << endl;
    gotoxy(10,9);
    cout << "CEDULA: " << Users[pos].idCard << endl;
    gotoxy(10,10);
    cout << "BUS: " << Users[pos].Bus << endl;
    gotoxy(10,11);
    cout << "TRABAJO: " << Users[pos].job << endl;
    gotoxy(10,12);
    cout << "SALARIO: " << Users[pos].Salary << endl;
    gotoxy(10,13);
}

Username getUser(int pos)
{
    return Users[pos];
}

int isUser(char id[])
{
    int posicion = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(id, Users[i].idUse) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void showUsers()
{
    system("cls||clear");
    if (lastReg == 0)
    {
        cout << "No hay registros\n";
        return;
    }
    for (int i = 0; i < lastReg; i++)
    {
        cout<< "=========================\n";
        showUser(i);
    }
    cout<< "Ultimo registro...\n";
}

void updateUser(Username use, int pos)
{
    Users[pos] = use;
}

void deleteUser(int pos)
{
    if (pos == lastReg)
    {
        cout << "No hay registro\n";
        return;
    }
    for (int i = pos; i < lastReg - 1; i++)
    {
        Users[i] = Users[i + 1];
    }
    lastReg--;
    startUser(lastReg);
}

void startUser(int pos)
{
    strcpy(Users[pos].idUse, "");
    strcpy(Users[pos].name, "");
    strcpy(Users[pos].lastname, "");
    Users[pos].birth.day = 0;
    Users[pos].birth.month = 0;
    Users[pos].birth.year = 0;
    strcpy(Users[pos].idCard, "");
    Users[pos].Bus = 0;
    strcpy(Users[pos].job, "");
    Users[pos].Salary = 0.0;
}

int menuUser()
{
    int op;

    gotoxy(10, 5);
    cout << " Informacion administrativa - Transporte David\n";
    gotoxy(15, 6);
    cout << "Cantidad de registros: " << lastReg << endl;
    gotoxy(10, 9);
    cout << " 1. Agregar Usuario \n";
    gotoxy(10, 10);
    cout << " 2. Editar Usuario \n";
    gotoxy(10, 11);
    cout << " 3. Eliminar Usuario \n";
    gotoxy(10, 12);
    cout << " 4. Buscar Usuario \n";
    gotoxy(10, 13);
    cout << " 5. Mostrar todos los Usuarios \n";
    gotoxy(10, 14);
    cout << " 6. Salir \n";
    gotoxy(10, 15);
    cout << " Digite la opcion: ";
    gotoxy(29, 15);
    cin >> op;
    return op;
}

 void startUse(){
    int op, pos, resp;
    char id[9];
    Username Use;
    readUser();
    do{
        system("cls||clear");
        
        op = menuUser();
        switch (op){
            case 1:
                system("cls || clear");
                gotoxy(10, 5);
                cout << "ID: ";
                gotoxy(10, 6);
                cout << "NOMBRE: ";
                gotoxy(10, 7);
                cout << "APELLIDOS: ";
                gotoxy(10, 8);
                cout << "FECHA DE NACIMIENTO dd/MM/yyyy: ";
                gotoxy(10, 9);
                cout << "CEDULA: ";
                gotoxy(10, 10);
                cout << "BUS: ";
                gotoxy(10, 11);
                cout << "TRABAJO: ";
                gotoxy(10, 12);
                cout << "SALARIO: ";
                gotoxy(13, 5);
                scanf(" %[^\n]", Use.idUse);
                gotoxy(17, 6);
                scanf(" %[^\n]", Use.name);
                gotoxy(20, 7);
                scanf(" %[^\n]", Use.lastname);
                gotoxy(41, 8);
                cin >> Use.birth.day >> Use.birth.month >> Use.birth.year;
                gotoxy(41, 8);
                scanf("%d/%d/%d", &Use.birth.day, &Use.birth.month, &Use.birth.year);
                gotoxy(17, 9);
                scanf(" %[^\n]", Use.idCard);
                gotoxy(14, 10);
                scanf("%d", &Use.Bus);
                gotoxy(18, 11);
                scanf(" %[^\n]", Use.job);
                gotoxy(18, 12);
                scanf("%f", &Use.Salary);
                addUser(Use);
                system("pause");

                break;
            case 2:
                system("cls||clear");
                gotoxy(10,4);
                cout << "Escribe el ID a buscar: ";
                scanf(" %[^\n]", id);
                pos = isUser(id);
                showUser(pos);
                gotoxy(10,13);
                cout << "DATOS A EDITAR\n";
                gotoxy(10,14);
                cout << "ID: ";
                gotoxy(10,15);
                cout << "NOMBRE: ";
                gotoxy(10,16);
                cout << "APELLIDOS: ";
                gotoxy(10,17);
                cout << "FECHA DE NACIMIENTO: ";
                gotoxy(10,18);
                cout << "CEDULA: ";
                gotoxy(10,19);
                cout << "BUS: ";
                gotoxy(10,20);
                cout << "TRABAJO: ";
                gotoxy(10,21);
                cout << "SALARIO: ";
                gotoxy(13,14);
                scanf(" %[^\n]", Use.idUse);
                gotoxy(17,15);
                scanf(" %[^\n]", Use.name);
                gotoxy(20,16);
                scanf(" %[^\n]", Use.lastname);
                gotoxy(30,17);
                cin >> Use.birth.day >> Use.birth.month >> Use.birth.year;
                gotoxy(17,18);
                scanf("%d/%d/%d", &Use.birth.day, &Use.birth.month, &Use.birth.year);
                gotoxy(17,20);
                scanf(" %[^\n]", Use.idCard);
                gotoxy(14, 21);
                scanf("%d", &Use.Bus);
                gotoxy(19, 22);
                scanf(" %[^\n]", Use.job);
                gotoxy(19, 23);
                scanf("%f", &Use.Salary);
                updateUser(Use, pos);
                gotoxy(14,21);
                cout << "Registro actualizado...\n";
                system("pause");
                break;
            case 3:
                system("cls||clear");
                if (lastReg == 0)
                {
                    cout << "No hay nada que eliminar\n";
                    break;
                }
                cout << "Escribe el ID del usuario: ";
                cin >> id;
                pos = isUser(id);
                Use = getUser(pos);
                cout << "¿Realmente deseas eliminar el usuario: " << Use.name << " " << Use.lastname << "?\n";
                cout << "Escribe 1 para SI o 2 para NO: ";
                cin >> resp;
                if (resp == 1)
                {
                    deleteUser(pos);
                    cout << "Registro Eliminado... \n";
                }
                else
                {
                    cout << "Operaciòn cancelada.... \n";
                }
                system("pause");
                break;
            case 4:
                system("cls||clear");
                cout << "Escribe el ID a buscar: ";
                scanf(" %[^\n]", id);
                pos = isUser(id);
                showUser(pos);
                system("pause");
                break;
            case 5:
                system("cls||clear");
                showUsers();
                system("pause");
                break;
            case 6:
                 break;
            default:
                system("clear||cls");
                cout << "Opcion invalida \n";
                system("pause");
                break;
        }

    }while (op != 6);
    saveUser();
 }

 void saveUser()
{
    UserRegistration = fopen("datos.bin", "wb");
    fwrite(Users, sizeof(Username), lastReg, UserRegistration);
    fclose(UserRegistration);
}

void readUser()
{
    UserRegistration = fopen("datos.bin", "rb");
    if (UserRegistration == NULL)
    {
        return;
    }
    lastReg = calcUltReg(UserRegistration);
    fread(Users, sizeof(Username), MAX, UserRegistration);
    fclose(UserRegistration);
}


int calcUltReg(FILE *archivo)
{
    int tam_archivo, num_usuarios;
    // Obtener el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    tam_archivo = ftell(archivo);
    rewind(archivo);

    // Calcular el número de alumnos
    num_usuarios = tam_archivo / sizeof(Username);
    return num_usuarios;
}
