#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*

C-strings Realice las siguientes actividades:

   [✔ 10/10] Obtener la memoria ram total, libre y disponible en Megabytes. A partir del archivo /proc/meminfo.
   [✔ 10/10] Obtener la memoria swap Ocupada. A partir del archivo /proc/meminfo.
    Crear un programa en C que imprima información referida al CPU, a partir del archivo /proc/cpuinfo:
        Modelo de CPU.
        Cantidad de cores
        Cantidad de thread por cores.

*/

int main()
{
    FILE *meminfo = fopen("/proc/meminfo", "r");
    char line[1000];
    while(fgets(line, sizeof(line), meminfo))
    {
        int ram;
        if (sscanf(line, "MemTotal: %d kB", &ram) == 1)
        {
            printf( "MemTotal: %d MB \n",ram/1024);
        }
        if (sscanf(line, "MemAvailable: %d kB", &ram) == 1){
            printf("MemAvailable: %d MB \n", ram/1024);
        }
        if (sscanf(line, "MemFree: %d kB", &ram) == 1){
            printf("MemFree: %d MB\n", ram/1024);
        }
        if (sscanf(line, "SwapCached: %d kB", &ram) == 1){
            printf("SwapCached: %d MB\n", ram/1024);
        }
        
    }

    fclose(meminfo);
    return 0;
}

