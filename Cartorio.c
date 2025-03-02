#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se � string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file, ","); //a "," � o que ser� gravado no arquivo, usada para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", nome); //%s refere-se � string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file, ","); //a "," � o que ser� gravado no arquivo, usada para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",sobrenome); //%s refere-se � string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file, ","); //a "," � o que ser� gravado no arquivo, usada para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se � string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause"); //Pausa na tela
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se � string
	
	FILE *file; 
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa leitura
	
	if(file == NULL) //Comando para caso o arquivo procurado seja inv�lido
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Comando para caso o arquivo procurado seja diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa na tela
	
}

int deletar()
{
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se � string
	
	remove(cpf); //Deleta o arquivo
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa leitura
	
	if(file == NULL) //Caso o arquivo n�o esteja mais no sistema, aparecer� a seguinte mensagem...
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause"); //Pausa na tela
	}
	
}

int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls"); 
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: "); // Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); //Respons�vel por limpar a tela
	    
	    switch(opcao) //In�cio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
	    	break;
	    	
	    	case 2:
	    	consulta();
	    	break;
	    	
	    	case 3:
	    	deletar();
		    break;
		    
			
		    default:
		    printf("Essa op��o n�o est� dispon�vel!\n");
		    system("pause");
	    	break;
				
		} //Fim da sele��o
    
	}
}
