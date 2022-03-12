%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void crear_token();
void crear_token_iden();
void crear_token_cadena();
void crear_token_num_real();
int val_token();
int cont_ident = 0;
int cont_num_real = 0;
int cont_cadena = 0;
int contador_lista = 0;
int posicion_simbolo_repetida = 0;
char sim_entero[10];
void insertarNodo(int a,char *s);
int buscarNodo(char *s);
int check_octal(char *s);
void crear_token_num(char *s);

FILE *archSalTok;
FILE *archSalTS;
FILE *archSalLC;
FILE *archSalLNR;
%}


pal_res cadena|devuelve|entero|flotante|hacer|mientras|nulo|para|si|sino|vacio
op_arit sum|res|mult|div|mod|pow
op_asig i_i|M_i|m_i|a_i|d_i|p_i|A_i|P_i|B_i
op_rela <M>|<m>|<=>|<M=>|<m=>|<$=>
const_num_real ([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)
const_num_ent_oct 0[0-7]*
const_num_ent_dec [1-9][0-9]*
const_num_ent_hex 0[Xx][0-9a-fA-F]+
ident ([a-zA-Z_][a-zA-Z_0-9]*|[0-9]+(_|[a-zA-Z])+[0-9]*)
sim_especial [\.:\(\){}]
const_cadenas \"(?:[^"\\]|\\.)*\"
char return_char(char* s);

%%
{pal_res} {crear_token(4,yytext);}
{op_arit} {crear_token(6,yytext);}
{op_asig} {crear_token(3,yytext);}
{op_rela} {crear_token(2,yytext);}
{const_num_real} {crear_token_num_real(yytext);}
{const_num_ent_oct} {crear_token_num(yytext);}
{const_num_ent_dec} {crear_token_num(yytext);}
{const_num_ent_hex} {crear_token_num(yytext);}
{ident} {crear_token_iden(yytext);}
{sim_especial} {fprintf(archSalTok," 5     | %s\n",yytext);}
{const_cadenas} {crear_token_cadena(yytext);}
%%

//Estructura nodo
typedef struct nodo
{
    int dato;               //Tipo de dato de la lista
    char s[100][40+1];
    struct nodo* siguiente; //Apuntador al siguiente nodo o nulo
}nodo;

//Apuntadores para hacer referencias al primero y al ultimo elemento de la lista
nodo* primero = NULL;
nodo* ultimmo = NULL;

//Inserta un nodo en la lista el cual contienen la posicion y el valor de nuestro identificador
void insertarNodo(int a, char*s){
    //Creamos un nodo del temaño dinamico
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = a;
    strcpy(nuevo->s[contador_lista],s);
    //Revisamos si la lista ha sido creada
    if (primero == NULL)
    {
        primero = nuevo;
        primero->siguiente = NULL;
        ultimmo = nuevo;
    }else{
        ultimmo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimmo = nuevo;
    }
    contador_lista = contador_lista + 1;
}

//Buscamos los identifiacdores que ya estan en nuestra lista,
//Si encontramos un identificador que ya este en la lista se devuelve 1
//Si no se encuentra nada se devuelve 0
int buscarNodo(char* s){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int encontrado = 0; //Cuando "encontrado" es 0, el nodo no se encontro, cuando "encontrado" es 1 el nodo fue encontrado
    char * nodoBuscado = s;
    //Comprobamos si la lista esta vacia
    if(primero != NULL){
        int i = 0;
        while (actual != NULL && encontrado != 1)
        {
            //Vamos comparando cual de los datos es el buscado
            if(strcmp(actual->s[i],nodoBuscado)==0){
                posicion_simbolo_repetida = actual->dato;
                encontrado = 1;
                return 1;
            }   
            i = i + 1;
            actual = actual->siguiente;
        }
        //Si no encrontramos el nodo
        if(encontrado == 0){
            return 0;
        }
        
    }else{
        //printf("\n La lista esta vacia.");
    }
}


//Escribimos en el archivo de tokens la clase y la posicion de nuestros catalogos ya definidos
void crear_token(int c,char *s){
    fprintf(archSalTok," %d     | %d\n", c,val_token(s));    
}

//Escribimos los tokens de los identificadores y con ayuda de las funciones buscar nodo y crear nodo
//nos aseguramos que no haya identificadores repetidos en la lista
//si no es asi, escribirmos la posicion, valor y tipo en el archivo de la tabla de simbolos
void crear_token_iden(char* s){
    if(buscarNodo(s) != 1){
        fprintf(archSalTok," 0     | %d\n",cont_ident);
        fprintf(archSalTS," %-5d | %-20s | -1\n",cont_ident,s);
        insertarNodo(cont_ident,s);
        cont_ident = cont_ident + 1; 
    }else{
        fprintf(archSalTok," 0     | %d\n",posicion_simbolo_repetida);
    }
     
}

//Escribimos el valor del token de la cadena en el archivo de tokens
//Tambien escribimos la tabla de tokens con posicion y valor 
//Si la cadena tiene mas de 40 elementos contando las comillas regresamos un mensaje de error y no añadimos la cadena
void crear_token_cadena(char *s){
    if(strlen(s) <= 40){
        fprintf(archSalTok," 7     | %d\n",cont_cadena);
        fprintf(archSalLC," %d   | %s\n",cont_cadena,s);
        cont_cadena = cont_cadena + 1;
    }else{
        printf("\nCadena demasiado grande %s\n", s);
    }
    
    
}

//Escribimos los tokens de los numeros enteros (decimal,octal y hexadecimal)
//con su respectiva clase y valor
void crear_token_num(char *s){
    if(check_octal(s) == 0 && strcmp(sim_entero,"1") == 0){
        fprintf(archSalTok," 1     | %s\n",s);
    }
}

//Utilizamos la funcion check octal para verificar que los numeros ingresados son octales y evitar los casos como:
// 08 u 09
int check_octal(char *s){
    char str[10][10];
    strcpy(str[0],s);
    char sr;
    sr = str[0][0];
    if(strcmp(s,"0") == 0){
        strcpy(sim_entero,s);
    }
    else if(strcmp(sim_entero,"0")== 0 && sr == '8'){
        printf("\nEl numero no es octal\n");
        strcpy(sim_entero,"1");
        return 1;
    }else if(strcmp(sim_entero,"0")== 0 && sr =='9'){
        printf("\nEl numero no es octal\n");
        strcpy(sim_entero,"1");
        return 1;
    }else if(strcmp(sim_entero,"0")== 0 && sr !='9' && sr !='8'){
        fprintf(archSalTok," 1     | 0\n");
        strcpy(sim_entero,"1");
        return 0;
    }else{
        return 0;
    }
}


//Escribimos los tokens para los numeros reales con su respectiva clase y posicion
//Ademas escribimos la tabla de estos numeros con su posicion y valor
void crear_token_num_real(char* s){
    fprintf(archSalTok," 8     | %d\n",cont_num_real);
    fprintf(archSalLNR," %d   | %s\n", cont_num_real, s);
    cont_num_real = cont_num_real + 1;
}

//DEfinimos los catalogos acorados en clase y regresamos el valor de su clase dependeindo del simbolo dado
int val_token(char *s){
    if(strcmp(s,"cadena") == 0 || strcmp(s,"<M>") == 0 || strcmp(s,"i_i") == 0 || strcmp(s,"sum") == 0){
        return 0;
    }else if(strcmp(s,"devuelve") == 0|| strcmp(s,"<m>") == 0 || strcmp(s,"M_i") == 0 || strcmp(s,"res") == 0){
        return 1;
    }else if(strcmp(s,"entero") == 0 || strcmp(s,"<=>") == 0 || strcmp(s,"m_i") == 0 || strcmp(s,"mult") == 0){
        return 2;
    }else if(strcmp(s,"flotante") == 0 || strcmp(s,"<M=>") == 0 || strcmp(s,"a_i") == 0 || strcmp(s,"div") == 0){
        return 3;
    }else if(strcmp(s,"hacer") == 0 || strcmp(s,"<m=>") == 0 || strcmp(s,"d_i") == 0 || strcmp(s,"mod") == 0){
        return 4;
    }else if(strcmp(s,"mientras") == 0 || strcmp(s,"<$=>") == 0 || strcmp(s,"p_i") == 0 || strcmp(s,"pow") == 0){
        return 5;  
    }else if(strcmp(s,"nulo") == 0 || strcmp(s,"A_i") == 0){
        return 6;  
    }else if(strcmp(s,"para") == 0 || strcmp(s,"P_i") == 0){
        return 7;
    }else if(strcmp(s,"si") == 0 || strcmp(s,"B_i") == 0){
        return 8;
    }else if(strcmp(s,"sino") == 0){
        return 9;
    }else if(strcmp(s,"vacio") == 0){
        return 10;
    }

}

void main(int argc, char *argv[]){
    yyin = fopen(argv[1],"r");
    archSalTok = fopen("salida_tokens.txt","w");
    fprintf(archSalTok," Clase | valor\n");
    archSalTS = fopen("salida_tabla_simbolos.txt","w");
    fprintf(archSalTS," Pos   | Nombre               | Tipo\n");
    archSalLC = fopen("salida_literales_constantes.txt","w");
    fprintf(archSalLC," Pos | Cadena\n");
    archSalLNR = fopen("salida_literales_numericas_reales.txt","w");
    fprintf(archSalLNR," Pos | Constante\n");

    yylex();


    fclose(archSalTok);
    fclose(archSalTS);
    fclose(archSalLC);
    fclose(archSalLNR);
}

