#include "entidades.h"
#include <stdio.h>
#include <stdlib.h>

void msg_MENU_inicial() {
  printf(
      "\n----------- PROGRAMA DE GERENCIAMENTO DE SUPERMERCADO -----------\n");
  printf("OBS.: Todas as informacoes serao armazenadas em arquivos.\nBASES "
         "DISPONIVEIS:\n");
  printf("1 - Funcionarios\n2 - Clientes\n3 - Fornecedores\n4 - Prateleiras\n5 "
         "- Encomendas\n6 - Produtos\n7 - Estoque\n8 - Sair\n");
  printf("RESPOSTA: ");
}

void msg_MENU(char *tipo) {
  printf("\n----------- PROGRAMA DE GERENCIAMENTO DE %s -----------\n", tipo);
  printf("OBS.: Todas as informacoes serao armazenadas em "
         "arquivos.\n\nOPERACOES DISPONIVEIS:\n");
  printf("1 - Criar base\n2 - Ordenar\n3 - Imprimir\n4 - Pesquisar "
         "(Sequencial)\n5 - Pesquisar (Binaria)\n6 - Sair\n");
  printf("RESPOSTA: ");
}

void menu_funcionario() {
  FILE *out;
  if ((out = fopen(FUNCIONARIOS_FILE, "w+b")) == NULL) {
    printf("Erro ao abrir arquivo\n");
    exit(1);
  } else {
    int escolha = -1;
    int cod;

    while (escolha != 6) {
      msg_MENU("FUNCIONARIO");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("\nInforme quantos registros tera a base: ");
        int num;
        scanf("%d", &num);
        initializeBaseDesorder_funcionario(out, num);
      } else if (escolha == 2) {
        insertion_sort_disco_funcionario(out, tamanho_arquivo_funcionario(out));
        printf("\n-----------------------------Base "
               "ordenada-----------------------");
        le_funcionarios(out);
      } else if (escolha == 3) {
        le_funcionarios(out);

      } else if (escolha == 4) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n-----------------------------Busca "
               "sequencial-----------------------");
        TFunc *func1 = busca_sequencial_funcionario(cod, out);
        printf("\n");
        imprime_funcionario(func1);

      } else if (escolha == 5) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n\n-----------------------------Busca "
               "binaria-----------------------");
        TFunc *func = busca_binaria_funcionario(
            cod, out, tamanho_arquivo_funcionario(out));
        printf("\n");
        imprime_funcionario(func);
      } else if (escolha == 6) {
        system("cls");
        break;
      } else {
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");
        break;
      }
    }
    fclose(out);
  }
}

void menu_cliente() {
  FILE *out_cli;
  if ((out_cli = fopen(CLIENTES_FILE, "w+b")) == NULL) {
    printf("Erro ao abrir arquivo\n");
    exit(1);
  } else {
    int escolha = -1;
    int cod;

    while (escolha != 6) {
      msg_MENU("CLIENTE");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("\nInforme quantos registros tera a base: ");
        int num;
        scanf("%d", &num);
        initializeBaseDesorder_cliente(out_cli, num);
      } else if (escolha == 2) {
        insertion_sort_disco_cliente(out_cli, tamanho_arquivo_cliente(out_cli));
        printf("\n-----------------------------Base "
               "ordenada-----------------------");
        le_clientes(out_cli);
      } else if (escolha == 3) {
        le_clientes(out_cli);

      } else if (escolha == 4) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n-----------------------------Busca "
               "sequencial-----------------------");
        TCliente *func1 = busca_sequencial_cliente(cod, out_cli);
        printf("\n");
        imprime_cliente(func1);

      } else if (escolha == 5) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n\n-----------------------------Busca "
               "binaria-----------------------");
        TCliente *func = busca_binaria_cliente(
            cod, out_cli, tamanho_arquivo_cliente(out_cli));
        printf("\n");
        imprime_cliente(func);
      } else if (escolha == 6) {
        system("cls");
        break;
      } else {
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");
        break;
      }
    }
    fclose(out_cli);
  }
}

void menu_fornecedor() {
  FILE *out;
  if ((out = fopen(FORNECEDORES_FILE, "w+b")) == NULL) {
    printf("Erro ao abrir arquivo\n");
    exit(1);
  } else {
    int escolha = -1;
    int cod;

    while (escolha != 6) {
      msg_MENU("FORNECEDORES");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("\nInforme quantos registros tera a base: ");
        int num;
        scanf("%d", &num);
        initializeBaseDesorder_fornecedor(out, num);
      } else if (escolha == 2) {
        insertion_sort_disco_fornecedor(out, tamanho_arquivo_fornecedor(out));
        printf("\n-----------------------------Base "
               "ordenada-----------------------");
        le_fornecedores(out);
      } else if (escolha == 3) {
        le_fornecedores(out);
      } else if (escolha == 4) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n-----------------------------Busca "
               "sequencial-----------------------");
        TForn forn = busca_sequencial_fornecedor(cod, out);
        printf("\n");
        imprime_fornecedor(&forn);

      } else if (escolha == 5) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n\n-----------------------------Busca "
               "binaria-----------------------");
        TForn forn =
            busca_binaria_fornecedor(cod, out, tamanho_arquivo_fornecedor(out));
        printf("\n");
        imprime_fornecedor(&forn);
      } else if (escolha == 6) {
        system("cls");
        break;
      } else {
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");
        break;
      }
    }
    fclose(out);
  }
}

void menu_encomenda() {
  FILE *out;
  if ((out = fopen(ENCOMENDAS_FILE, "w+b")) == NULL) {
    printf("Erro ao abrir arquivo\n");
    exit(1);
  } else {
    int escolha = -1;
    int cod;

    while (escolha != 6) {
      msg_MENU("ENCOMENDAS");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("\nInforme quantos registros tera a base (encomendas): ");
        int num;
        scanf("%d", &num);
        initializeBaseDesorder_encomenda(out, num);
      } else if (escolha == 2) {
        insertion_sort_disco_encomenda(out, tamanho_arquivo_encomenda(out));
        printf("\n-----------------------------Base "
               "ordenada-----------------------");
        le_encomendas(out);
      } else if (escolha == 3) {
        le_encomendas(out);
      } else if (escolha == 4) {
        printf("\nInforme o codigo a ser buscado: ");
        scanf("%d", &cod);

        printf("\n-----------------------------Busca "
               "sequencial-----------------------");
        TEncomenda encomenda = busca_sequencial_encomenda(cod, out);
        printf("\n");
        imprime_encomenda(&encomenda);

      } else if (escolha == 5) {
        printf("\nInforme o codigo a ser buscado: ");
        scanf("%d", &cod);

        printf("\n\n-----------------------------Busca "
               "binaria-----------------------");
        TEncomenda encomenda =
            busca_binaria_encomenda(cod, out, tamanho_arquivo_encomenda(out));
        printf("\n");
        imprime_encomenda(&encomenda);
      } else if (escolha == 6) {
        system("cls");
        break;
      } else {
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");
        break;
      }
    }
    fclose(out);
  }
}

void menu_produto() {
  FILE *out_cli;
  if ((out_cli = fopen(PRODUTOS_FILE, "w+b")) == NULL) {
    printf("Erro ao abrir arquivo\n");
    exit(1);
  } else {
    int escolha = -1;
    int cod;

    while (escolha != 6) {
      msg_MENU("PRODUTO");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("\nInforme quantos registros tera a base: ");
        int num;
        scanf("%d", &num);
        initializeBaseDesorder_produto(out_cli, num);
      } else if (escolha == 2) {
        insertion_sort_disco_produto(out_cli, tamanho_arquivo_produto(out_cli));
        printf("\n-----------------------------Base "
               "ordenada-----------------------");
        le_produtos(out_cli);
      } else if (escolha == 3) {
        le_produtos(out_cli);

      } else if (escolha == 4) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n-----------------------------Busca "
               "sequencial-----------------------");
        TProd prod = busca_sequencial_produto(cod, out_cli);
        printf("\n");
        imprime_produto(&prod);

      } else if (escolha == 5) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n\n-----------------------------Busca "
               "binaria-----------------------");
        TProd prod = busca_binaria_produto(cod, out_cli,
                                           tamanho_arquivo_produto(out_cli));
        printf("\n");
        imprime_produto(&prod);
      } else if (escolha == 6) {
        system("cls");
        break;
      } else {
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");
        break;
      }
    }
    fclose(out_cli);
  }
}

void menu_prateleira() {
  FILE *out_cli;
  if ((out_cli = fopen(PRATELEIRA_FILE, "w+b")) == NULL) {
    printf("Erro ao abrir arquivo\n");
    exit(1);
  } else {
    int escolha = -1;
    int cod;

    while (escolha != 6) {
      msg_MENU("PRATELEIRAS");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("\nInforme quantos registros tera a base: ");
        int num;
        scanf("%d", &num);
        initializeBaseDesorder_prateleira(out_cli, num);
      } else if (escolha == 2) {
        insertion_sort_disco_prateleira(out_cli,
                                        tamanho_arquivo_prateleira(out_cli));
        printf("\n-----------------------------Base "
               "ordenada-----------------------");
        le_prateleiras(out_cli);
      } else if (escolha == 3) {
        le_prateleiras(out_cli);

      } else if (escolha == 4) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n-----------------------------Busca "
               "sequencial-----------------------");
        TPrat prateleira = busca_sequencial_prateleira(cod, out_cli);
        printf("\n");
        imprime_prateleira(&prateleira);

      } else if (escolha == 5) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n\n-----------------------------Busca "
               "binaria-----------------------");
        TPrat prateleira = busca_binaria_prateleira(
            cod, out_cli, tamanho_arquivo_prateleira(out_cli));
        printf("\n");
        imprime_prateleira(&prateleira);
      } else if (escolha == 6) {
        system("cls");
        break;
      } else {
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");
        break;
      }
    }
    fclose(out_cli);
  }
}

void menu_estoque() {
  FILE *out_cli;
  if ((out_cli = fopen(ESTOQUE_FILE, "w+b")) == NULL) {
    printf("Erro ao abrir arquivo\n");
    exit(1);
  } else {
    int escolha = -1;
    int cod;

    while (escolha != 6) {
      msg_MENU("ESTOQUE");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("\nInforme quantos registros tera a base: ");
        int num;
        scanf("%d", &num);
        initializeBaseDesorder_estoque(out_cli, num);
      } else if (escolha == 2) {
        insertion_sort_disco_estoque(out_cli, tamanho_arquivo_estoque(out_cli));
        printf("\n-----------------------------Base "
               "ordenada-----------------------");
        le_estoques(out_cli);
      } else if (escolha == 3) {
        le_estoques(out_cli);

      } else if (escolha == 4) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n-----------------------------Busca "
               "sequencial-----------------------");
        TEstoque estoque = busca_sequencial_estoque(cod, out_cli);
        printf("\n");
        imprime_estoque(&estoque);

      } else if (escolha == 5) {
        printf("\nInforme o codigo a ser buscado: ");

        scanf("%d", &cod);

        printf("\n\n-----------------------------Busca "
               "binaria-----------------------");
        TEstoque estoque = busca_binaria_estoque(
            cod, out_cli, tamanho_arquivo_estoque(out_cli));
        printf("\n");
        imprime_estoque(&estoque);
      } else if (escolha == 6) {
        system("cls");
        break;
      } else {
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");
        break;
      }
    }
    fclose(out_cli);
  }
}

int main(int argc, char **argv) {
  int option = -1;

  while (option != 8) {
    msg_MENU_inicial();
    scanf("%d", &option);

    if (option == 1) {
      menu_funcionario();

    } else if (option == 2) {
      menu_cliente();

    } else if (option == 3) {
      menu_fornecedor();

    } else if (option == 4) {
      menu_prateleira();

    } else if (option == 5) {
      menu_encomenda();

    } else if (option == 6) {
      menu_produto();

    } else if (option == 7) {
      menu_estoque();

    } else if (option == 8) {
      printf("\nFIM DO PROGRAMA!\n");
      system("cls");
      break;
    } else {
      printf("\nESCOLHA UMA OPCAO VALIDA!\n");
      break;
    }
  }
}