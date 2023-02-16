#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *AdicionarNome(char *nomes);
char *RemoveNome(char *nomes);
void Listar(char *nomes);
void Menu();


int main(void) {

    int escolha = 0;
    char *nomes = NULL;




    for(;;) {
        Menu();
        scanf("%d", &escolha);

    switch(escolha){

        case 1:
        nomes = AdicionarNome(nomes);
        break;

        case 2:
        nomes = RemoveNome(nomes);
        break;

        case 3:
        Listar(nomes);
        break;

        case 4:
        exit(0);
        break;
        }

    }
    return 0;
}

char *AdicionarNome( char *nomes ){
	
int tamanho = 0;
char novoNome[100];

printf("Digite o nome a ser adicionado: ");
scanf("%s", novoNome);

if ( nomes == NULL ) {

    tamanho = strlen( novoNome );
    nomes =( char * )malloc( tamanho + 1 );

        if ( nomes == NULL ) {
            printf("Não foi possível alocar memória\n");
            return NULL;
        }

    strcpy( nomes, novoNome );

    return nomes;
} else {

    tamanho = strlen( nomes ) + strlen( novoNome ) + 1;
    nomes = ( char * )realloc( nomes, tamanho );

    if ( nomes == NULL ) {
        printf("Não foi possível realocar memória\n");
        return NULL;
    }

    strcat( nomes, "\n" );
    strcat( nomes, novoNome );
    }

return nomes;
}

char *RemoveNome ( char *nomes ) {
    char *match;
    char removeNome[100];

    printf("\nDigite o nome a ser removido: ");
    scanf("%s", removeNome);
    
    int tamanho = strlen( removeNome );

        if ( strstr( nomes, removeNome ) != NULL ) {

            while ( ( match = strstr ( nomes, removeNome ) ) != NULL ) {
                
                memmove( match, match + tamanho, strlen ( match + tamanho ) + 1 );
                }

int novo_tamanho = strlen( nomes );
char *novo_nome = ( char * )malloc( novo_tamanho + 1 );
            
    if ( novo_nome == NULL ) {

        printf("Não foi possível alocar memória\n");

return nomes;
    }
            
        strcpy( novo_nome, nomes );
        free( nomes );
        nomes = novo_nome;

  }  else {

        printf("\nNome nao encontrado.");
        return nomes;
    }
        
}

void Listar( char *nomes ) {

    printf("Nomes: \n%s\n", nomes);
}

void Menu() {

    printf("\n1. Adicionar Nome");
    printf("\n2. Remover Nome");
    printf("\n3. Listar Nomes");
    printf("\n4. Sair");
    printf("\nSua escolha: ");

}