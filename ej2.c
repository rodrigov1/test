#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LEN 1000

/*


Arreglos Lea el archivo /proc/version y copie las palabras en un arreglo dinámico. Luego:

[10/10]Imprima la lista de palabras en mayúscula.
[10/10]libere la memoria que haya alocado.


*/
void to_upper(char* string);
int main(){

   char array[MAX_LINES][MAX_LEN];
   FILE *file;
   file= fopen("/proc/version", "r");
   int line=0;


   if (file == NULL){
    printf("Error opening the file");
    return 2;
   }
   
 
   while(!feof(file)){
     if (fgets(array[line],MAX_LEN,file)!=NULL){
        line++;
        
     }
   }
    printf("Lista de palabras en mayuscula: ");
    int i;

    for (i=0; i<line;i++){
       to_upper(array[i]);
       printf("%s", array[i]);
  
    }

   
   fclose(file);

   
  
    
   


   
   return 0;
}

void to_upper(char *string)
{
    const char OFFSET = 'a' - 'A';
    while (*string)
    {
         char string1= (*string >= 'a' && *string <= 'z') ? *string -= OFFSET : *string;
        *string = string1 ;
        string++;
    }
}