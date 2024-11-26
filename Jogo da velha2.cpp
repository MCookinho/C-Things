#include <stdio.h>
#include <string.h>
inicializamatriz(char jogo[3][3]){
	int j,i;
	for( j=0; j<3; j++){
			for( i=0; i<3; i++){
				jogo[i][j] = ' ';
			}
		}
	
}

imprimematriz(char jogo[3][3]){
	printf("  0   1   2\n");
		printf("0 %c | %c | %c\n", jogo[0][0], jogo[1][0], jogo[2][0]);
		printf("------------\n");
		printf("1 %c | %c | %c\n", jogo[0][1], jogo[1][1], jogo[2][1]);
		printf("------------\n");
		printf("2 %c | %c | %c\n", jogo[0][2], jogo[1][2], jogo[2][2]);
		printf("\n\n\n");
	
}

int cordenadavalida(char jogo[3][3], int i, int j){
	if(jogo[i][j]== ' '){
			return 1;}
			else{
				printf("Valor invalido, tente novamente\n");
				return 0;
			}
}

int main(){
	char p1[50], p2[50], jogo[3][3];
	int ganhou=0, rodadas=0, i, j, boolean;
	
		inicializamatriz(jogo);
		printf("***J O G O   D A   V E L H A***\n");
		printf("*******************************\n");
		printf("Nome do jogador 1: ");
		scanf("%s",&p1);
		printf("Nome do jogador 2: ");
		scanf("%s",&p2);
		printf("\nBoa sorte jogadores %s e %s !\n", p1,p2);
		printf("*******************************\n\n\n\n");

	while(rodadas<9 && ganhou==0){
		imprimematriz(jogo);
		boolean = 0;
		if(rodadas%2==0){
			while(boolean==0){
			printf("%s, digite a linha e a coluna que voce quer colocar: ", p1);
			scanf("%d %d", &i, &j);
			boolean=cordenadavalida(jogo, i, j);
			if(boolean == 1)
				jogo[i][j]='X';
			}
			
		}
		if(rodadas%2!=0){
			while(boolean==0){
			printf("%s, digite a linha e a coluna que voce quer colocar: ", p2);
			scanf("%d %d", &i, &j);
			boolean=cordenadavalida(jogo, i, j);
			if(boolean == 1)
				jogo[i][j]='0';
			}
			
			
		}
		
		rodadas++;
	}
	
		
}
