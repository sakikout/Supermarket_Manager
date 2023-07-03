#include "produto.h"
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void imprime_produto(TProd *prod) {
  printf("**********************************************");
  printf("\nProduto de codigo ");
  printf("%d", prod->cod);
  printf("\nNome: ");
  printf("%s", prod->nome);
  printf("\nValor: R$");
  printf("%s", prod->valor);
  printf("\n**********************************************");
}
TProd *produto(int cod, char *nome, char *valor) {
  TProd *prod = (TProd *)malloc(sizeof(TProd));
  if (prod)
    memset(prod, 0, sizeof(TProd));
  prod->cod = cod;
  strcpy(prod->nome, nome);
  strcpy(prod->valor, valor);
  return prod;
}

void salva_produto(TProd *prod, FILE *out) {
  fwrite(&prod->cod, sizeof(int), 1, out);
  fwrite(prod->nome, sizeof(char), sizeof(prod->nome), out);
  fwrite(prod->valor, sizeof(char), sizeof(prod->valor), out);
}

TProd *le_produto(FILE *in) {
  TProd *prod = (TProd *)malloc(sizeof(TProd));
  if (0 >= fread(&prod->cod, sizeof(int), 1, in)) {
    free(prod);
    return NULL;
  }
  fread(prod->nome, sizeof(char), sizeof(prod->nome), in);
  fread(prod->valor, sizeof(char), sizeof(prod->valor), in);
  return prod;
}

void le_produtos(FILE *in) {
  printf("\n\nLendo produtos do arquivo...\n\n");
  rewind(in);
  TProd prod;

  while (fread(&prod, sizeof(TProd), 1, in) == 1) {
    imprime_produto(&prod);
  }
}

int tamanho_produto() {
  return sizeof(int)           // cod
         + (sizeof(char) * 50) // nome
         + sizeof(char) * 50;     // valor
}

int tamanho_arquivo_produto(FILE *arq) {
  fseek(arq, 0, SEEK_END);
  int tam = trunc(ftell(arq) / tamanho_registro_produto());
  return tam;
}

int tamanho_registro_produto() { return sizeof(TProd); }

void initializeBaseDesorder_produto(FILE *file, int numberRecords) {
  int f[numberRecords];
  for (int i = 0; i < numberRecords; i++) {
    f[i] = i + 1;
  }
  embaralhar(f, numberRecords);
  fseek(file, 0, SEEK_SET);

  for (int i = 0; i < numberRecords; i++) {
    TProd prod;
    prod.cod = f[i];
    sprintf(prod.nome, "Produto %d", f[i]);
    sprintf(prod.valor, "%.2f", (2.5 * (i + 1)));
    fseek(file, (i)*tamanho_registro_produto(), SEEK_SET);
    salva_produto(&prod, file);
  }
}

TProd busca_sequencial_produto(int cod, FILE *arq) {
  double tempoTotal = 0;
  int comp = 0;
  int i = 0;
  clock_t inicio = clock();

  rewind(arq);
  TProd prod;

  while (fread(&prod, sizeof(TProd), 1, arq) == 1) {
    if (cod == prod.cod) {
      clock_t fim = clock();
      tempoTotal += (double)(fim - inicio) / CLOCKS_PER_SEC;
      printf("\nTempo da busca sequencial = %f segundos\n", tempoTotal);
      printf("\nComparacoes = %d\n", comp);
      return prod;
      break;
    } else {
      comp++;
    }
  }
}

TProd busca_binaria_produto(int cod, FILE *arq, int tam) {
  int left = 0, right = tam - 1, comp = 0;
  double tempoTotal = 0;
  TProd prod;

  rewind(arq);
  clock_t inicio = clock();

  while (left <= right) {
    int middle = (left + right) / 2;
    fseek(arq, middle * tamanho_registro_produto(), SEEK_SET);
    fread(&prod, sizeof(TProd), 1, arq);
    if (cod == prod.cod) {
      clock_t fim = clock();
      tempoTotal += (double)(fim - inicio) / CLOCKS_PER_SEC;
      printf("\nTempo da busca sequencial = %f segundos\n", tempoTotal);
      printf("\nComparacoes = %d\n", comp);
      return prod;
    } else if (prod.cod < cod) {
      left = middle + 1;
      comp++;
    } else {
      right = middle - 1;
      comp++;
    }
  }
}

void insertion_sort_disco_produto(FILE *arq, int tam) {
  int i;
  for (int j = 2; j <= tam; j++) {
    fseek(arq, (j - 1) * tamanho_registro_produto(), SEEK_SET);
    TProd *cli = le_produto(arq);
    // printf("\n********* Funcionario atual: %d\n", fj->cod);
    i = j - 1;
    fseek(arq, (i - 1) * tamanho_registro_produto(), SEEK_SET);
    TProd *cli1 = le_produto(arq);
    // printf("fi = %d\n", fi->cod);
    while ((i > 0) && (cli1->cod > cli->cod)) {
      fseek(arq, i * tamanho_registro_produto(), SEEK_SET);
      // printf("Salvando funcionario %d na posicao %d\n", fi->cod, i+1);
      salva_produto(cli1, arq);
      i = i - 1;
      fseek(arq, (i - 1) * tamanho_registro_produto(), SEEK_SET);
      cli1 = le_produto(arq);
      // printf("fi = %d; i = %d\n", fi->cod, i);
    }
    fseek(arq, (i)*tamanho_registro_produto(), SEEK_SET);
    // printf("*** Salvando funcionario %d na posicao %d\n", fj->cod, i+1);
    salva_produto(cli, arq);
  }
  fflush(arq);
}

