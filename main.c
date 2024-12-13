#include "include/TRIE.h"
#include "include/AVL.h"
#include <time.h>

/*
//função de busca que vai receber:
//TrieNode *root: primeiro nó "raiz"
//name: variavel da arvore trie que busca o usuario
//int A: variavel de inicio de intervalo
//int B: variavel de fim de intervalo
*/

void search_chuiter(TrieNode *root,const char *name, long long int a, long long int b){
    TrieNode *aux = search_trie(root,name);
    if(aux){
        printf("%s ", name);
        inorder_avl(aux->root_avl, a, b);    
    }else{
        printf("usuario não encontrado");
    }
}

int main() {
    char name[25] = ""; // Para o primeiro elemento (char até espaço)
    long long int date; // Para o número inteiro
    char chuiter[MAX_LINHA]; //Para o restante da linha (char seguido pela frase)                                
    
    TrieNode *root = create_node_trie(); //criando o primeiro nodo da trie (vazio)
    FILE *arquivo;
    long long int a = 0; //data de inicio de intervalo
    long long int b = 999999999999999; //data de fim de intervalo
    int menu = 1; //criterio de parada do programa
    int Qtd = 0; //contador de chutiters
    
    //variaveis de entrada do usuario
    char input[55];
    char start_date[10] = "";  
    char end_date[10] = "";
    char start_time[8] = "";
    char end_time[8] = "";

    arquivo = fopen("chuiter.txt", "r"); //abre o arquivo
        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(chuiter, MAX_LINHA, arquivo) != NULL) { //leitura do arquivo e inserção de dados
        if (sscanf(chuiter, "%s %lld %[^\n]", name, &date, chuiter) == 3) {
            insert_trie(root,name,date,chuiter);
        } else {
            fprintf(stderr, "Erro para ler a linha: %s\n", chuiter);
        }
    }

    search_chuiter(root,"globo",0,9399994999959);
    
    fclose(arquivo); //fecha o arquivo
    return 0;
}