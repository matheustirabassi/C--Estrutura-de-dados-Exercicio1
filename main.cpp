#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdexcept>
#include <limits>
using namespace std;
struct Estudante
{
    char nome[200];
    char prontuario[50];
    float media;
};
struct Estudante estudante;
int comparar(const void  *x, const void *y){
    return -strcmp(((struct Estudante *)x)->prontuario, ((struct Estudante *)y)->prontuario);

}

void imprimirEstudantes(Estudante *estudante, int tam){
    for(int i = 0; i < tam; i++){
        cout << "Nome: " << estudante[i].nome << " Prontuário: " << estudante[i].prontuario << " Média: " << estudante[i].media << endl;
    }
}


void escanearEstudantes(Estudante *estudante, int tam){
    char nome[200];
    char prontuario[50];
    float media;
    for(int i = 0; i < tam; i++){
        cout << "nome: " ;
        fflush(stdin);
        gets(nome);
         if(strlen(nome) > 200 ){
            throw invalid_argument("O máximo permitido é 200 caracteres");
         }
         fflush(stdin);
        cout << "prontuário: ";
        fflush(stdin);
        gets(prontuario);
        if(strlen(prontuario) > 50 ){
            throw invalid_argument("O máximo permitido é 50 caracteres");
         }
        cout << "media: ";
        cin >> media;
        strcpy( estudante[i].nome,nome);
        strcpy( estudante[i].prontuario,prontuario);
        estudante[i].media = media;
    }
}
int main()
{
   setlocale(LC_ALL,"Portuguese");
   try{
    Estudante *estudante;
    cout << "Quantos estudantes ?" << endl;
    int n;
    cin >> n;
    estudante = (Estudante *)malloc(n * sizeof(Estudante));
    escanearEstudantes(estudante,n);
    qsort(estudante, n, sizeof(Estudante), comparar);
    imprimirEstudantes(estudante, n);
    free(estudante);

   }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        return -1;
    }

    return 0;
}
