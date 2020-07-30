#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdexcept>
#include <limits>
#include <ctype.h>
using namespace std;

struct Estudante
{
    char nome[200];
    char prontuario[50];
    float media;
};
struct Estudante estudante;
int compararProntuario(const void  *x, const void *y){
    return strcmp(strupr(((struct Estudante *)x)->prontuario), strupr(((struct Estudante *)y)->prontuario));

}
int compararMediaCrescente(const void *x, const void *y){
return (((struct Estudante *)x) -> media) - (((struct Estudante *)y) ->media);
}
int compararMediaDecrescente(const void *x, const void *y){
return -((((struct Estudante *)x) -> media) - (((struct Estudante *)y) ->media));
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
            throw runtime_error("O máximo permitido é 200 caracteres");
         }
         fflush(stdin);
        cout << "prontuário: ";
        fflush(stdin);
        gets(prontuario);
        if(strlen(prontuario) > 50 ){
            throw runtime_error("O máximo permitido é 50 caracteres");
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
    cout << "Comparando pelo prontuário!" << endl;
    qsort(estudante, n, sizeof(Estudante),compararProntuario);
    imprimirEstudantes(estudante, n);
    cout << "Comparando pela média em ordem crescente!" << endl;
    qsort(estudante, n, sizeof(Estudante),compararMediaCrescente);
    imprimirEstudantes(estudante, n);
    cout << "Comparando pela média em ordem decrescente!" << endl;
    qsort(estudante, n, sizeof(Estudante), compararMediaDecrescente);
    imprimirEstudantes(estudante, n);
    free(estudante);

   }
    catch(invalid_argument &e){
        cout << e.what() << endl;
        return -1;
    }
    catch(runtime_error &e){
    cout << e.what() << endl;
    }
    return 0;
}
