#include <stdio.h>
int calcvet(int *p, int max){
	if (max == 0)
	return 0;
	return  *p + calcvet(p+1, max-1);
}

int invertevet(int vet[], int max){
	if(max <= 0)
	return 1;
	int aux;
	aux = vet[0];
	vet[0] = vet[max-1];
	vet[max-1] = aux;
	invertevet(vet+1, max-2);  
}

int analizavet(int *p, int max, int k, int *res){
	if(max == 0)
	return 0;
	if (*p == k)
	*res+=1;
	analizavet(p+1, max-1, k, res);
}


int main(){
	int res, vet[50], k;
	int i, max, *freq;
	*freq = 0;
	printf("Digite quantos elementos voce quer por no vetor: ");
	scanf("%d", &max);
	for(i=0;i<max;i++){
	printf("Escolha o %d elemento do vetor: ", i+1);
	scanf("%d", &vet[i]);
	}
	printf("Digite o numero que o senhor quer analizar do vetor: ");
	scanf("%d", &k);
	printf("\n\n\n\nOs valores do vetor normal sao: ");
	for(i=0;i<max;i++){
	printf("%d ", vet[i]);
	}
	res = calcvet(vet,max);
	analizavet(vet, max, k, freq);
	invertevet(vet, max);
	printf("\nOs valores do vetor invertido sao: ");
	for(i=0;i<max;i++){
	printf("%d ", vet[i]);
	}
	printf("\nO digito %d se repete %d vezes", k, *freq);
	printf("\nA soma dos elementos do vetor e: %d\n", res);
	return 0;
}