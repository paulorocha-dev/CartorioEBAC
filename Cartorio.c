#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se à string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file, ","); //a "," é o que será gravado no arquivo, usada para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", nome); //%s refere-se à string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,nome); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file, ","); //a "," é o que será gravado no arquivo, usada para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",sobrenome); //%s refere-se à string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file, ","); //a "," é o que será gravado no arquivo, usada para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",cargo); //%s refere-se à string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	system("pause"); //Pausa na tela
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informações do usuário
	scanf("%s",cpf); //%s refere-se à string
	
	FILE *file; 
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa leitura
	
	if(file == NULL) //Comando para caso o arquivo procurado seja inválido
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Comando para caso o arquivo procurado seja diferente de nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa na tela
	
}

int deletar()
{
	//Início da criação de variáveis/string
	char cpf[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informações do usuário
	scanf("%s",cpf); //%s refere-se à string
	
	remove(cpf); //Deleta o arquivo
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa leitura
	
	if(file == NULL) //Caso o arquivo nõo esteja mais no sistema, aparecerá a seguinte mensagem...
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause"); //Pausa na tela
	}
	
}

int main()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls"); 
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: "); // Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls"); //Responsável por limpar a tela
	    
	    switch(opcao) //Início da seleção do menu
	    {
	    	case 1:
	    	registro(); //chamada de funções
	    	break;
	    	
	    	case 2:
	    	consulta();
	    	break;
	    	
	    	case 3:
	    	deletar();
		    break;
		    
			
		    default:
		    printf("Essa opção não está disponível!\n");
		    system("pause");
	    	break;
				
		} //Fim da seleção
    
	}
}
