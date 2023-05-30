#include <iostream>
#include <stdio.h>
#include <string.h>
#include "auxiliaruser.h"
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
    gotoxy4(60,5);
    cout << "ID: " << Users[pos].idUse << endl;
    gotoxy4(60,6);
    cout << "NOMBRE: " << Users[pos].name << endl;
    gotoxy4(60,7);
    cout << "APELLIDOS: " << Users[pos].lastname << endl;
    gotoxy4(60,8);
    cout << "FECHA DE NACIMIENTO: " << Users[pos].birth.day << "/" << Users[pos].birth.month << "/" << Users[pos].birth.year << endl;
    gotoxy4(60,9);
    cout << "CEDULA: " << Users[pos].idCard << endl;
    gotoxy4(60,10);
    cout << "BUS: " << Users[pos].Bus << endl;
    gotoxy4(60,11);
    cout << "TRABAJO: " << Users[pos].job << endl;
    gotoxy4(60,12);
    cout << "SALARIO: " << Users[pos].Salary << endl;
    gotoxy4(60,13);
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
        gotoxy4(60,4);
        cout << "No hay registros\n";
        return;
    }
    for (int i = 0; i < lastReg; i++)
    {
        gotoxy4(60,4);
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

    gotoxy4(60, 5);
    cout << " Informacion Usuario - Transporte David\n";
    gotoxy4(70, 6);
    cout << "Cantidad de registros: " << lastReg << endl;
    gotoxy4(60, 9);
    cout << " 1. Agregar Usuario \n";
    gotoxy4(60, 10);
    cout << " 2. Editar Usuario \n";
    gotoxy4(60, 11);
    cout << " 3. Eliminar Usuario \n";
    gotoxy4(60, 12);
    cout << " 4. Buscar Usuario \n";
    gotoxy4(60, 13);
    cout << " 5. Mostrar todos los Usuarios \n";
    gotoxy4(60, 14);
    cout << " 6. Salir \n";
    gotoxy4(60, 15);
    cout << " Digite la opcion: ";
    gotoxy4(79, 15);
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
                gotoxy4(60, 5);
                cout << "ID: ";
                gotoxy4(60, 6);
                cout << "NOMBRE: ";
                gotoxy4(60, 7);
                cout << "APELLIDOS: ";
                gotoxy4(60, 8);
                cout << "FECHA DE NACIMIENTO dd/MM/yyyy: ";
                gotoxy4(60, 9);
                cout << "CEDULA: ";
                gotoxy4(60, 10);
                cout << "BUS: ";
                gotoxy4(60, 11);
                cout << "TRABAJO: ";
                gotoxy4(60, 12);
                cout << "SALARIO: ";
                gotoxy4(65, 5);
                scanf(" %[^\n]", Use.idUse);
                gotoxy4(69, 6);
                scanf(" %[^\n]", Use.name);
                gotoxy4(72, 7);
                scanf(" %[^\n]", Use.lastname);
                gotoxy4(92, 8);
                scanf("%d/%d/%d", &Use.birth.day, &Use.birth.month, &Use.birth.year);
                gotoxy4(70, 9);
                scanf(" %[^\n]", Use.idCard);
                gotoxy4(66, 10);
                scanf("%d", &Use.Bus);
                gotoxy4(70, 11);
                scanf(" %[^\n]", Use.job);
                gotoxy4(70, 12);
                scanf("%f", &Use.Salary);
                addUser(Use);
                system("pause");

                break;
            case 2:
                system("cls||clear");
                gotoxy4(60,4);
                cout << "Escribe el ID a buscar: ";
                gotoxy4(85,4);
                scanf(" %[^\n]", id);
                pos = isUser(id);
                showUser(pos);
                gotoxy4(60,13);
                cout << "DATOS A EDITAR\n";
                gotoxy4(60,14);
                cout << "ID: ";
                gotoxy4(60,15);
                cout << "NOMBRE: ";
                gotoxy4(60,16);
                cout << "APELLIDOS: ";
                gotoxy4(60,17);
                cout << "FECHA DE NACIMIENTO: ";
                gotoxy4(60,18);
                cout << "CEDULA: ";
                gotoxy4(60,19);
                cout << "BUS: ";
                gotoxy4(60,20);
                cout << "TRABAJO: ";
                gotoxy4(60,21);
                cout << "SALARIO: ";
                gotoxy4(65,14);
                scanf(" %[^\n]", Use.idUse);
                gotoxy4(68,15);
                scanf(" %[^\n]", Use.name);
                gotoxy4(72,16);
                scanf(" %[^\n]", Use.lastname);
                gotoxy4(82,17);
                scanf("%d/%d/%d", &Use.birth.day, &Use.birth.month, &Use.birth.year);
                gotoxy4(69,18);
                scanf(" %[^\n]", Use.idCard);
                gotoxy4(66,19);
                scanf("%d", &Use.Bus);
                gotoxy4(70,20);
                scanf(" %[^\n]", Use.job);
                gotoxy4(70,21);
                scanf("%f", &Use.Salary);
                updateUser(Use, pos);
                gotoxy4(60,24);
                cout << "Registro actualizado...\n";
                system("pause");
                break;
            case 3:
                system("cls||clear");
                if (lastReg == 0)
                {
                    gotoxy4(60, 5);
                    cout << "No hay nada que eliminar\n";
                    break;
                }
                gotoxy4(60, 5);
                cout << "Escribe el ID del usuario: ";
                gotoxy4(89, 5);
                cin >> id;
                pos = isUser(id);
                Use = getUser(pos);
                gotoxy4(60, 7);
                cout << "¿Realmente deseas eliminar el usuario: " << Use.name << " " << Use.lastname << "?\n";
                gotoxy4(60, 8);
                cout << "Escribe 1 para SI o 2 para NO: ";
                gotoxy4(92, 8);
                cin >> resp;
                if (resp == 1)
                {
                    deleteUser(pos);
                    gotoxy4(60, 10);
                    cout << "Registro Eliminado... \n";
                }
                else
                {
                    gotoxy4(60, 10);
                    cout << "Operaciòn cancelada.... \n";
                }
                system("pause");
                break;
            case 4:
                system("cls||clear");
                gotoxy4(60, 4);
                cout << "Escribe el ID a buscar: ";
                gotoxy4(84, 4);
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
                gotoxy4(60, 4);
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
    fseek(archivo, 0, SEEK_END);
    tam_archivo = ftell(archivo);
    rewind(archivo);

    num_usuarios = tam_archivo / sizeof(Username);
    return num_usuarios;
}