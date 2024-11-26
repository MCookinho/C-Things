#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define LETRAS 26
 
typedef struct tp_no {
    char letra;
    struct tp_no* filhos[LETRAS];
    int eh_folha;
} tp_no;
 
tp_no* cria_no(char letra) {
    tp_no* no = (tp_no*) malloc (sizeof(tp_no));
    int i;
    if (no != NULL) {
    	no->eh_folha = 0;
    	no->letra = letra;
	    for (i=0; i<LETRAS; i++)
    	    no->filhos[i] = NULL;
	}
    return no;
}

tp_no* insere_no_trie(tp_no* raiz, char* palavra) {
    tp_no* no = raiz;
 	int tam = strlen(palavra);
    int i;
    for (i=0; i < tam; i++) {
    	//palavras estão em minúsculo
        int ind = (int) palavra[i] - 'a';
        if (no->filhos[ind] == NULL) {
            no->filhos[ind] = cria_no(palavra[i]);
        }
        no = no->filhos[ind];
    }
    no->eh_folha = 1;
    return raiz;
}
 
int busca_no_trie(tp_no* raiz, char* palavra)
{
    tp_no* no = raiz;
 	int tam = strlen(palavra); 
 	int i;
    for(i=0; i < tam; i++)
    {
        int pos = palavra[i] - 'a';
        if (no->filhos[pos] == NULL)
            return 0;
        no = no->filhos[pos];
    }
    if (no != NULL && no->eh_folha == 1)
        return 1;
    return 0;
}
 
void imprime_arv_trie(tp_no* raiz) {
    if (!raiz)
        return;
    tp_no* no = raiz;
    printf("%c -> ", no->letra);
    int i;
	for (i=0; i<LETRAS; i++) {
        imprime_arv_trie(no->filhos[i]); 
    }
}

int remove_no_trie(tp_no **raiz, char* palavra)
{
	if (*raiz == NULL)
		return 0;

	if (*palavra)
	{
		if (*raiz != NULL && (*raiz)->filhos[*palavra - 'a'] != NULL &&
			remove_no_trie(&((*raiz)->filhos[*palavra - 'a']), palavra + 1) &&
			(*raiz)->eh_folha == 0)
		{
			free(*raiz);
			(*raiz) = NULL;
			return 1;
		}
	}


	if (*palavra == '\0' && (*raiz)->eh_folha)
	{
		free(*raiz); 
		(*raiz) = NULL;
		return 1; 
	}

	return 0;
}


