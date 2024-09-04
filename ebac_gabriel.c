#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

   //final da cria��o das vari�veis

    printf("Digite o CPF a ser Cadastrado\n"); //coletando informa��es do usu�rio
    scanf("%s", cpf); //salvando na vari�vel, %s refere-se a strings (conjunto de vari�veis)
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // cria o arquvo e o "w" significa escrever.
    fprintf(file,cpf); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //o "a" � porqu� queremos atualizar o arquivo e n�o criar um novo "w"
    fprintf(file,","); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    printf("Digte o Nome a ser Cadastrado:\n"); //solicitando dados do usu�rio
    scanf("%s",nome); // salvando na vari�vel, %s refere-se a strings (conjunto de vari�veis)
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar "a" significa que queremos atualizar um arquivo j� criado
    fprintf(file,nome); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualizando o arquivo j� criado, pois tem o "a"
    fprintf(file, ","); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    printf("Digite o Sobrenome a ser Cadastrado:\n"); //solicitando dados do usu�rio
    scanf("%s",sobrenome); //salvando na vari�vel, %s refere-se a strings (conjunto de vari�veis)
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar, pois tem a letra "a"
    fprintf(file,sobrenome); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar, pois, utilizamos a letra "a"
    fprintf(file, ","); //salvando o valor da vari�vel
    fclose(file); //fechando o arquivo
    
    printf("Digite o Cargo do Funcion�rio Cadastrado:\n"); //solicitando dados do usu�rio
    scanf("%s",cargo); //salvando na vari�vel, %s refere-se a strings (conjunto de vari�veis
    
    file = fopen(arquivo, "a"); //abrindo  o arquivo para atualizar, pois usamos a letra "a"
    fprintf(file,cargo); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar, pois, est� com a letra "a"
    fprintf(file, ","); //salvando o valor da vari�vel
    fclose(file); //fechando o arquivo
    
    system("pause"); //da uma pausa na tela para que digite os dados/op��o escolhida
    
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese"); //definindo idioma a ser utilizado
		//inicio da cria��o de vari�veis/string
    char cpf[40];
	char conteudo[200];
	   //final da cria��o das vari�veis
	   
	printf("Digite o CPF a ser Consultado:\n"); //solicitando dados do usu�rio
	scanf("%s",cpf); //salvando na vari�vel, %s � strings (conjunto de vari�veis)
	
	printf("\n"); //espa�o para n�o ficar feio
	
    FILE *file; //criando ou abrindo o arquivo no banco de dados
    file = fopen(cpf, "r"); //a letra "r" faz ler o arquivo
    
    if(file == NULL) //consultando o arquivo, se n�o existir na pasta aberta apresentar� a mensagem abaixo
    {
    	printf("O CPF n�o foi localizado.\n");  //mensagem apresentada, pois, n�o existe o cpf consultado		
	}

    while(fgets(conteudo, 200, file) != NULL) // consultando usu�rio diferente de NULL ,ou seja, cpfs existentes
    {
    	printf("Essas s�o as Informa��es do Usu�rio:\n"); //passando informa��es
    	printf("%s",conteudo); //salvando informa��es da var�avel para mostrar, %s significa conjunto de vari�veis (string) 
    	printf("\n\n"); // espa�o pra ficar bonito
	} 
	    system("pause"); //para pausar na tela de consulta de dados do usu�rio
}

int deletar()
{
	//inicio da cria��o de vari�veis
	
	char cpf[40];
	
	//final da cria��o das vari�veis
	   
	printf("Digite o CPF a ser deletado:\n"); //solicitando dados do usu�rio
	scanf("%s",cpf); //salvando o valor da var�avel, %s significa strings (conjunto de var�veis)
	
	remove(cpf); //comando para remover o usu�rio selecionado
	
	FILE *file; //abrindo o arquivo
	file = fopen(cpf,"r"); //lendo o arquivo
	
	if (file != NULL) //caso n�o seja localizado, n�o ser� removido. Se localizado, ser� removido.
	{
		printf("O CPF foi deletado com sucesso! \n"); //tela de remo��o conclu�da
		system("pause"); //pausando para demonstrar a mensagem acima
	}
	
}

int main ()
{
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	
	 setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	 printf("### Recursos Humanos EBAC ###\n\n"); //Inicio do Menu
	 printf("Escolha a Op��o Desejada do Menu: \n\n");
	 printf("\t1 - Registrar Nomes\n");
	 printf("\t2 - Consultar Nomes\n");
	 printf("\t3 - Deletar Nomes\n");
	 printf("\t4 - Sair do Sistema\n\n");
	 
	 printf ("Op��o:");//Fim do Menu
	
	 scanf("%d", &opcao); //Armazenando a Escolha do Usu�rio
	
	 system("cls"); //respons�vel por limpar a tela anterior a escolha de op��es.
	 
	 switch(opcao)//inicio da sele��o do menu
	 {
	 	case 1:
	    registro(); //chamada de fun��es
		break;
		
		case 2:	
        consultar(); //chamada de fun��es
 		break;
		
		case 3:
        deletar(); //chamada de fun��es
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema \n");
		return 0;
		break;
		
		default:	
	    printf("Op��o Inv�lida!\n"); //mensagem apresentada caso n�o localizado a op��o selecionada
		system("pause");
		break;
		
	 }// fim da sele��o
 	
    }
}
