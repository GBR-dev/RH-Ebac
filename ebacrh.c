#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

   //final da criação das variáveis

    printf("Digite o CPF a ser Cadastrado\n"); //coletando informações do usuário
    scanf("%s", cpf); //salvando na variável, %s refere-se a strings (conjunto de variáveis)
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // cria o arquvo e o "w" significa escrever.
    fprintf(file,cpf); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //o "a" é porquê queremos atualizar o arquivo e não criar um novo "w"
    fprintf(file,","); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    printf("Digte o Nome a ser Cadastrado:\n"); //solicitando dados do usuário
    scanf("%s",nome); // salvando na variável, %s refere-se a strings (conjunto de variáveis)
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar "a" significa que queremos atualizar um arquivo já criado
    fprintf(file,nome); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualizando o arquivo já criado, pois tem o "a"
    fprintf(file, ","); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    printf("Digite o Sobrenome a ser Cadastrado:\n"); //solicitando dados do usuário
    scanf("%s",sobrenome); //salvando na variável, %s refere-se a strings (conjunto de variáveis)
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar, pois tem a letra "a"
    fprintf(file,sobrenome); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar, pois, utilizamos a letra "a"
    fprintf(file, ","); //salvando o valor da variável
    fclose(file); //fechando o arquivo
    
    printf("Digite o Cargo do Funcionário Cadastrado:\n"); //solicitando dados do usuário
    scanf("%s",cargo); //salvando na variável, %s refere-se a strings (conjunto de variáveis
    
    file = fopen(arquivo, "a"); //abrindo  o arquivo para atualizar, pois usamos a letra "a"
    fprintf(file,cargo); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar, pois, está com a letra "a"
    fprintf(file, ","); //salvando o valor da variável
    fclose(file); //fechando o arquivo
    
    system("pause"); //da uma pausa na tela para que digite os dados/opção escolhida
    
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese"); //definindo idioma a ser utilizado
		//inicio da criação de variáveis/string
    char cpf[40];
	char conteudo[200];
	   //final da criação das variáveis
	   
	printf("Digite o CPF a ser Consultado:\n"); //solicitando dados do usuário
	scanf("%s",cpf); //salvando na variável, %s é strings (conjunto de variáveis)
	
	printf("\n"); //espaço para não ficar feio
	
    FILE *file; //criando ou abrindo o arquivo no banco de dados
    file = fopen(cpf, "r"); //a letra "r" faz ler o arquivo
    
    if(file == NULL) //consultando o arquivo, se não existir na pasta aberta apresentará a mensagem abaixo
    {
    	printf("O CPF não foi localizado.\n");  //mensagem apresentada, pois, não existe o cpf consultado		
	}

    while(fgets(conteudo, 200, file) != NULL) // consultando usuário diferente de NULL ,ou seja, cpfs existentes
    {
    	printf("Essas são as Informações do Usuário:\n"); //passando informações
    	printf("%s",conteudo); //salvando informações da varíavel para mostrar, %s significa conjunto de variáveis (string) 
    	printf("\n\n"); // espaço pra ficar bonito
	} 
	    system("pause"); //para pausar na tela de consulta de dados do usuário
}

int deletar()
{
	//inicio da criação de variáveis
	
	char cpf[40];
	
	//final da criação das variáveis
	   
	printf("Digite o CPF a ser deletado:\n"); //solicitando dados do usuário
	scanf("%s",cpf); //salvando o valor da varíavel, %s significa strings (conjunto de varáveis)
	
	remove(cpf); //comando para remover o usuário selecionado
	
	FILE *file; //abrindo o arquivo
	file = fopen(cpf,"r"); //lendo o arquivo
	
	if (file != NULL) //caso não seja localizado, não será removido. Se localizado, será removido.
	{
		printf("O CPF foi deletado com sucesso! \n"); //tela de remoção concluída
		system("pause"); //pausando para demonstrar a mensagem acima
	}
	
}

int main ()
{
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	
	 setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	 printf("### Recursos Humanos EBAC ###\n\n"); //Inicio do Menu
	 printf("Escolha a Opção Desejada do Menu: \n\n");
	 printf("\t1 - Registrar Nomes\n");
	 printf("\t2 - Consultar Nomes\n");
	 printf("\t3 - Deletar Nomes\n");
	 printf("\t4 - Sair do Sistema\n\n");
	 
	 printf ("Opção:");//Fim do Menu
	
	 scanf("%d", &opcao); //Armazenando a Escolha do Usuário
	
	 system("cls"); //responsável por limpar a tela anterior a escolha de opções.
	 
	 switch(opcao)//inicio da seleção do menu
	 {
	 	case 1:
	    registro(); //chamada de funções
		break;
		
		case 2:	
        consultar(); //chamada de funções
 		break;
		
		case 3:
        deletar(); //chamada de funções
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema \n");
		return 0;
		break;
		
		default:	
	    printf("Opção Inválida!\n"); //mensagem apresentada caso não localizado a opção selecionada
		system("pause");
		break;
		
	 }// fim da seleção
 	
    }
}
