#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

#define PRODUTOS_FILE "produtos.dat"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

typedef struct Produto {
  int cod;
  char nome[50];
  double valor;
} TProd;

void imprime_produto(TProd *prod);

TProd *produto(int cod, char *nome, double valor);

void salva_produto(TProd *prod, FILE *out);

TProd *le_produto(FILE *in);

void le_produtos(FILE *in);

int tamanho_produto();

int tamanho_arquivo_produto(FILE *arq);

int tamanho_registro_produto();

void initializeBaseDesorder_produto(FILE *file, int numberRecords);

TProd busca_sequencial_produto(int cod, FILE *arq);

TProd busca_binaria_produto(int cod, FILE *arq, int tam);

void insertion_sort_disco_produto(FILE *arq, int tam);

#endif // PRODUTO_H_INCLUDED
