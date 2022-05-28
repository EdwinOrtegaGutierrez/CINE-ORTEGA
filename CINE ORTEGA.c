#include <stdio.h> //ESTANDAR DE ENTRADA Y SALIDA
#include <conio.h> //CONSOLA DE ENTRADA Y SALIDA
#include <stdlib.h> //GESTION DE MEMORIA Y CONTROL DE PROCESOS 
#include <windows.h> //FUNCIONES Y ESTRUCTURAS
#include <string.h> //MANIPULACION DE MEMORIA

int xS, xI, y, seleccion, pelicula;
char ID[200], Nombre[50], Genero[50], Duracion[50], Clasificacion[50], Horario[50];
int MostrarCartelera, resenas, info;
int venta;
char NomBoleto[50], ClaBoleto[50], HorBoleto[50], AsientoBoleto[50], PrecioBoleto[50];

COORD coord= {0,0}; 

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void interfaz()
{
    //COLUMNAS LATERALES
    for(y=1; y<17; y++)
    {
        gotoxy(10,y);
        printf("%c                                                                            %c", 186, 186);
    }
    //ESQUINAS DE LA PARTE IZQUIERDA
    gotoxy(10,1);
    printf("%c", 201);
    gotoxy(10,17);
    printf("%c", 200);
    //COLUMNA SUPERIOR 
    for(xS=11; xS<87; xS++)
    {
        gotoxy(xS,1);
        printf("%c", 205);
    }
    //COLUMNA INFERIOR 
    for(xI=11; xI<87; xI++)
    {
        gotoxy(xI,17);
        printf("%c", 205);
    }

    //ESQUINAS DE LA PARTE DERECHA
    gotoxy(87,1);
    printf("%c", 187);
    gotoxy(87,17);
    printf("%c", 188);
}

void nueva_pared()
{
    gotoxy(10, 2); printf("%c", 186);
    gotoxy(10, 3); printf("%c", 186);
    gotoxy(10, 4); printf("%c", 186);
    gotoxy(10, 5); printf("%c", 186);
    gotoxy(10, 6); printf("%c", 186);
    gotoxy(10, 7); printf("%c", 186);
    gotoxy(10, 8); printf("%c", 186);
    gotoxy(10, 9); printf("%c", 186);
    gotoxy(10, 10); printf("%c", 186);
    gotoxy(10, 11); printf("%c", 186);
    gotoxy(10, 12); printf("%c", 186);
    gotoxy(10, 13); printf("%c", 186);
    gotoxy(10, 14); printf("%c", 186);
    gotoxy(10, 15); printf("%c", 186);
    gotoxy(10, 16); printf("%c", 186);
}

void menu()
{
    gotoxy(35, 2); printf("Bienvenido al %cCINE ORTEGA%c", 173, 33);
    
    gotoxy(37, 4); printf("Precios de los boletos:");

    gotoxy(34, 6); printf("Adulto - %c200 | Infantil - %c75", 36, 36);

    gotoxy(29.9, 8); printf("Tercera edad - %c75 | Estudiante - %c100", 36, 36);

    gotoxy(37, 11); printf("OPCIONES DEL PROGRAMA");

    gotoxy(16, 13); printf("1- Agregar peliculas. 2- Mostrar cartelera. 3- Venta de boletos.");

    gotoxy(34, 15); printf("Escoge una opci%cn para continuar: ", 162);
    scanf("%d", &seleccion);

}

void borrar_menu()
{
    if(seleccion>=1 && seleccion<=3)
    {
        gotoxy(35, 2); printf("                                                ");
    
        gotoxy(37, 4); printf("                                                ");

        gotoxy(34, 6); printf("                                                 ");

        gotoxy(29.9, 8); printf("                                                     ");

        gotoxy(37, 11); printf("                                         ");

        gotoxy(16, 13); printf("                                                                   ");

        gotoxy(34, 15); printf("                                                   ");
    }
}

void fin()
{
    gotoxy(30, 30); printf("                                                      ");
}

void generar_pelicula()
{
   FILE *archivo;
   char Nuevo[20]="nueva pelicula.txt";

   archivo=fopen(Nuevo,"w");
   if(archivo==NULL)
   {
      printf(" Error al generar una pel%ccula.", 161);
      exit(1);
   }
    gotoxy(35, 2); printf("INGRESA LOS DATOS DE LA PEL%cCULA", 214);
    gets(ID);

    gotoxy(12, 4); printf("Introduce la %cID%c de la pel%ccula: ", 34, 34, 161);
    fgets(ID, sizeof ID, stdin);
    fprintf(archivo,"ID: %s\n",ID);

    gotoxy(12, 6); printf("Introduce el nombre de la pel%ccula: ", 161);
    fgets(Nombre, sizeof Nombre, stdin);
    fprintf(archivo,"Nombre: %s\n",Nombre);

    gotoxy(12, 8); printf("Introduce el genero: ");
    fgets(Genero, sizeof Genero, stdin);
    fprintf(archivo,"Genero: %s\n",Genero);

    gotoxy(12, 10); printf("Introduce la duraci%cn: ", 162);
    fgets(Duracion, sizeof Duracion, stdin);
    fprintf(archivo,"Duracion: %s\n",Duracion);   

    gotoxy(12, 12); printf("Introduce la clasificaci%cn: ", 162);
    fgets(Clasificacion, sizeof Clasificacion, stdin);
    fprintf(archivo,"Clasificacion: %s\n", Clasificacion);

    gotoxy(12, 14); printf("Introduce el horario: ");
    fgets(Horario, sizeof Horario, stdin);
    fprintf(archivo,"Horario: %s", Horario);

    fclose(archivo);
    gotoxy(12, 16); printf("El archivo de la pel%ccula se ha creado satisfactoriamente", 161);
}

void mostrar_cartelera()
{
    gotoxy(12, 2); printf("CARTELERA DISPONIBLE; te mostraremos la informaci%cn o las rese%cas.", 162, 164);
    gotoxy(12, 6); printf("Opci%cn %c1%c para leer las rese%cas.", 162, 34, 34, 164);
    gotoxy(12, 8); printf("Opci%cn %c2%c para ver la informaci%cn.", 162, 34, 34, 162);
    gotoxy(12, 10); printf("Opci%cn %c3%c para volver al inicio.", 162, 34, 34);
    gotoxy(12, 12); printf("Elige una opci%cn: ", 162);
    scanf("%d", &MostrarCartelera); 
}

void borrar_resenas()
{
        gotoxy(28, 2); printf("                                                      ");
        gotoxy(12, 6); printf("                                                      ");
        gotoxy(12, 8); printf("                                                      ");
        gotoxy(12, 10); printf("                                                     ");
        gotoxy(12, 12); printf("                                                     ");
        gotoxy(12, 14); printf("                                                     ");
        gotoxy(12, 16); printf("                                                     ");
}

void resenas_cartelera()
{
    if (resenas == 1)
    {
    borrar_resenas();

    gotoxy(35, 2); printf("BATMAN - EL CABALLERO DE LA NOCHE."); 

        FILE *fichero = fopen("texto1.txt", "r");
        char batman;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        batman = fgetc(fichero);
        while (batman != EOF)
        {
            printf("%c", batman);
            batman = fgetc(fichero);
        }
        fclose(fichero);
        nueva_pared();
    }
    else if (resenas == 2)
    {
    borrar_resenas();

    gotoxy(35, 2); printf("EL LOBO DE WALL STREET."); 

        FILE *fichero = fopen("texto2.txt", "r");
        char loboWS;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        loboWS = fgetc(fichero);
        while (loboWS != EOF)
        {
            printf("%c", loboWS);
            loboWS = fgetc(fichero);
        }
        
        fclose(fichero);
        nueva_pared();
    }
    else if (resenas == 3)
    {
    borrar_resenas();

    gotoxy(45, 2); printf("INTERSTELLAR."); 

        FILE *fichero = fopen("texto3.txt", "r");
        char loboWS;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        loboWS = fgetc(fichero);
        while (loboWS != EOF)
        {
            printf("%c", loboWS);
            loboWS = fgetc(fichero);
        }
        
        fclose(fichero);
        nueva_pared();
    }
    else if (resenas == 4)
    {
    borrar_resenas();

    gotoxy(45, 2); printf("THE JOKER."); 

        FILE *fichero = fopen("texto4.txt", "r");
        char loboWS;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        loboWS = fgetc(fichero);
        while (loboWS != EOF)
        {
            printf("%c", loboWS);
            loboWS = fgetc(fichero);
        }
        
        fclose(fichero);
        nueva_pared();
    }
    else if (resenas == 5)
    {
    borrar_resenas();

    gotoxy(45, 2); printf("SOUL."); 

        FILE *fichero = fopen("texto5.txt", "r");
        char loboWS;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        loboWS = fgetc(fichero);
        while (loboWS != EOF)
        {
            printf("%c", loboWS);
            loboWS = fgetc(fichero);
        }

        fclose(fichero);
        nueva_pared();
    }
}

void borrar_cartelera()
{
    gotoxy(12, 2); printf("                                                                      ");
    gotoxy(12, 6); printf("                                                   ");
    gotoxy(12, 8); printf("                                                        ");
    gotoxy(12, 10); printf("                                                    ");
    gotoxy(12, 12); printf("                                ");
}

void info_seleccion_cartelera()
{
    if (info == 1)
    {
        borrar_resenas();
        
        gotoxy(25, 2); printf("BATMAN - EL CABALLERO DE LA NOCHE."); 

        FILE *fichero = fopen("info1.txt", "r");
        char batman;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        batman = fgetc(fichero);
        while (batman != EOF)
        {
            printf("%c", batman);
            batman = fgetc(fichero);
        }
        fclose(fichero);
        nueva_pared();
        gotoxy(30,30); system("pause");
    }
    else if (info == 2)
    {
        borrar_resenas();
        
        gotoxy(25, 2); printf("EL LOBO DE WALL STREET."); 

        FILE *fichero = fopen("info2.txt", "r");
        char loboWS;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        loboWS = fgetc(fichero);
        while (loboWS != EOF)
        {
            printf("%c", loboWS);
            loboWS = fgetc(fichero);
        }
        fclose(fichero);
        nueva_pared();
    }
    else if (info == 3)
    {
        borrar_resenas();
        
        gotoxy(25, 2); printf("INTERSTELLAR."); 

        FILE *fichero = fopen("info3.txt", "r");
        char interstellar;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        interstellar = fgetc(fichero);
        while (interstellar != EOF)
        {
            printf("%c", interstellar);
            interstellar = fgetc(fichero);
        }
        fclose(fichero);
        nueva_pared();
    }
    else if (info == 4)
    {
        borrar_resenas();
        
        gotoxy(25, 2); printf("THE JOKER"); 

        FILE *fichero = fopen("info4.txt", "r");
        char JOKER;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        JOKER = fgetc(fichero);
        while (JOKER != EOF)
        {
            printf("%c", JOKER);
            JOKER = fgetc(fichero);
        }
        fclose(fichero);
        nueva_pared();
    }
        else if (info == 5)
    {
        borrar_resenas();
        
        gotoxy(25, 2); printf("SOUL."); 

        FILE *fichero = fopen("info5.txt", "r");
        char SOUL;
        if (fichero == NULL)
        {
            gotoxy(12, 4); printf("ERROR, la pel%ccula no existe o hubo un error de apertura.", 161);
        }
        SOUL = fgetc(fichero);
        while (SOUL != EOF)
        {
            printf("%c", SOUL);
            SOUL = fgetc(fichero);
        }
        fclose(fichero);
        nueva_pared();
    }
}

void venta_boletos()
{
    gotoxy(40, 2); printf("VENTA DE BOLETOS:");
    gotoxy(12, 6); printf("1. Batman - El caballero de la noche.");
    gotoxy(12, 8); printf("2. El lobo de wall street.");
    gotoxy(12, 10); printf("3. Interstellar.");
    gotoxy(12, 12); printf("4. El joker.");
    gotoxy(12, 14); printf("5. Soul.");
    gotoxy(12, 16); printf("Escoge una pel%ccula: ", 161);
    scanf("%d", &venta);
}

void borrar_venta_boletos()
{
    gotoxy(40, 2); printf("                            ");
    gotoxy(12, 6); printf("                                       ");
    gotoxy(12, 8); printf("                                  ");
    gotoxy(12, 10); printf("                            ");
    gotoxy(12, 12); printf("                      ");
    gotoxy(12, 14); printf("                 ");
    gotoxy(12, 16); printf("                                    ");
}

void generar_boleto()
{
    FILE *archivo;
   char Nuevo[20]="Boleto.txt";

   archivo=fopen(Nuevo,"w");
   if(archivo==NULL)
   {
      printf(" Error al generar una boleto");
      exit(1);
   }
    gotoxy(35, 2); printf("INGRESA LOS DATOS DE LA PEL%cCULA", 214);
    gets(ID);

    gotoxy(12, 4); printf("Nombre de la pel%ccula: ", 161);
    fgets(NomBoleto, sizeof NomBoleto, stdin);
    fprintf(archivo,"Filme: %s\n", NomBoleto);

    gotoxy(12, 6); printf("Clasificaci%cn: ", 162);
    fgets(ClaBoleto, sizeof ClaBoleto, stdin);
    fprintf(archivo,"Clasificacion del filme: %s\n", ClaBoleto);

    gotoxy(12, 8); printf("Horario: ");
    fgets(HorBoleto, sizeof HorBoleto, stdin);
    fprintf(archivo,"Horario del filme: %s\n", HorBoleto);

    gotoxy(12, 10); printf("N%cmero de asiento: ", 163);
    fgets(AsientoBoleto, sizeof AsientoBoleto, stdin);
    fprintf(archivo,"Asiento asignado: %s\n", AsientoBoleto);   

    gotoxy(12, 14); printf("Agrega el precio del boleto: ");
    fgets(PrecioBoleto, sizeof PrecioBoleto, stdin);
    fprintf(archivo,"Precio del Boleto: %c%s \n", 36, PrecioBoleto);

    fclose(archivo);
    gotoxy(12, 16); printf("EL BOLETO ESTA LISTO PARA IMPRIMIR");
}

void borrar_generar_boleto()
{
    gotoxy(35, 2); printf("                                          ");
    gotoxy(12, 4); printf("                                             ");
    gotoxy(12, 6); printf("                                             ");
    gotoxy(12, 8); printf("                                                   ");
    gotoxy(12, 10); printf("                                               ");
    gotoxy(12, 14); printf("                                           ");
    gotoxy(12, 16); printf("                                          ");
}

void seleccion_opcion()
{
    switch (seleccion)
    {
    case 1:
           pelicula = 1;
        break;
    case 2:
           pelicula = 2;
        break;
    case 3:
           pelicula = 3;
        break;
    }
    if (pelicula == 1)
    {
        generar_pelicula();
    }
    else if (pelicula == 2)
    {
        mostrar_cartelera();
    }
    else if (pelicula == 3)
    {
        venta_boletos();
    }
}

void seleccion_cartelera()
{
    switch (MostrarCartelera)
    {
    case 1:
        borrar_cartelera();

        gotoxy(28, 2); printf("ELIJE LA PEL%cCULA PARA LEER SU RESE%cA:", 214, 165);
        gotoxy(12, 6); printf("1. Batman - El caballero de la noche.");
        gotoxy(12, 8); printf("2. El lobo de wall street.");
        gotoxy(12, 10); printf("3. Interstellar.");
        gotoxy(12, 12); printf("4. The joker.");
        gotoxy(12, 14); printf("5. Soul.");
        gotoxy(12, 16); printf("Escoge una pel%ccula: ", 161);
        scanf("%d", &resenas);

        resenas_cartelera();
        break;
    case 2:
        borrar_cartelera();
                
        gotoxy(25, 2); printf("ELIJE LA PEL%cCULA PARA VER LA INFORMACI%cN:", 214, 224);
        gotoxy(12, 6); printf("1. Batman - El caballero de la noche.");
        gotoxy(12, 8); printf("2. El lobo de wall street.");
        gotoxy(12, 10); printf("3. Interstellar.");
        gotoxy(12, 12); printf("4. The joker.");
        gotoxy(12, 14); printf("5. Soul.");
        gotoxy(12, 16); printf("Escoge una pel%ccula: ", 161);
        scanf("%d", &info);
        break;
    case 3:
        borrar_cartelera();
    }
    
}

void asientos()
{
    gotoxy(15, 6); printf("A - B - C - D - E - F - G - H - I - J - K - L - M - N - %c - O - P - Q", 165);
    gotoxy(12, 8); printf("1");
    gotoxy(12, 10); printf("2");
    gotoxy(12, 12); printf("3");
    gotoxy(12, 14); printf("4");
    gotoxy(12, 16); printf("5");
    //ASIENTOS
    gotoxy(15, 8); printf("  - X - X -   -   -   - X -   - X - X -   -   -   -   - X - X - X - X");
    gotoxy(15, 10); printf("X - X -   - X - X -   - X - X -   -   - X - X -   -   -   - X - X - ");
    gotoxy(15, 12); printf("  - X - X - X -   - X - X -   - X - X -   -   -   - X - X - X - X - X");
    gotoxy(15, 14); printf("  - X - X -   -   -   - X -   - X - X -   -   -   -   - X - X - X - X");
    gotoxy(15, 16); printf("  - X - X -   -   -   - X -   - X - X -   - X - X -   -   -   - X - X");
}

void borrar_asientos()
{
    gotoxy(30, 2); printf("                                        ");
    gotoxy(38, 4); printf("                     ");
    gotoxy(15, 6); printf("                                                                      ");
    gotoxy(12, 8); printf("  ");
    gotoxy(12, 10); printf("  ");
    gotoxy(12, 12); printf("  ");
    gotoxy(12, 14); printf("  ");
    gotoxy(12, 16); printf("  ");
    //ASIENTOS
    gotoxy(15, 8); printf("                                                                      ");
    gotoxy(15, 10); printf("                                                                      ");
    gotoxy(15, 12); printf("                                                                      ");
    gotoxy(15, 14); printf("                                                                      ");
    gotoxy(15, 16); printf("                                                                      ");
}

void seleccion_venta_boletos()
{
    switch (venta)
    {
    case 1:
        borrar_venta_boletos();

        gotoxy(30, 2); printf("Voletos: BATMAN EL CABALLERO DE LA NOCHE");
        gotoxy(38, 4); printf("ASIENTOS DISPONIBLES:");
        asientos();
        gotoxy(30, 30); system("pause");
        borrar_asientos();
        generar_boleto();
        break;
    case 2:
        borrar_venta_boletos();

        gotoxy(30, 2); printf("Voletos: EL LOBO DE WALL STREET");
        gotoxy(38, 4); printf("ASIENTOS DISPONIBLES:");
        asientos();
        gotoxy(30, 30); system("pause");
        borrar_asientos();
        generar_boleto();
        break;
    case 3:
        borrar_venta_boletos();

        gotoxy(38, 2); printf("Voletos: INTERSTELLAR");
        gotoxy(38, 4); printf("ASIENTOS DISPONIBLES:");
        asientos();
        gotoxy(30, 30); system("pause");
        borrar_asientos();
        generar_boleto();
        break;
    case 4:
        borrar_venta_boletos();

        gotoxy(40, 2); printf("Voletos: THE JOKER");
        gotoxy(38, 4); printf("ASIENTOS DISPONIBLES:");
        asientos();
        gotoxy(30, 30); system("pause");
        borrar_asientos();
        generar_boleto();
        break;
    case 5:
        borrar_venta_boletos();

        gotoxy(40, 2); printf("Voletos: SOUL");
        gotoxy(38, 4); printf("ASIENTOS DISPONIBLES:");
        asientos();
        gotoxy(30, 30); system("pause");
        borrar_asientos();
        generar_boleto();
        break;
    }
}

int main()
{
    interfaz(); 
    
    menu();
    borrar_menu();

    seleccion_opcion();
    seleccion_cartelera();
    info_seleccion_cartelera();
    seleccion_venta_boletos();


    //RETORNO AL MENU PRINCIPAL
    gotoxy(30,30); system("pause");
    fin();

return main();
}