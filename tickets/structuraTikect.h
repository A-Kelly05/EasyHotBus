/*Estructura de tikect */
typedef struct
{
    char id[5];
    char origen[50];
    char destino[50];
    float price;
} priceTicket;

typedef struct
{
    int day;
    int month;
    int year;
} Fecha;

typedef struct
{
    char idF[5];
    Fecha dateF;
    char horario[6];
    int cantT;
    char* idD;
    char* destinoF;
    char* origenF;
    float priceDest;
    float total;

} factura;

