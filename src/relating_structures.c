
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pedido
{
  char nome[50];
} Pedido;

typedef struct cliente
{
  char nome[50];
  Pedido **pedidos;
  int quantidadePedidos;
} Cliente;

typedef struct restaurante
{
  char nome[50];
  Pedido **pedidos;
  int quantidadePedidos;
} Restaurante;

/**
 * @brief Cria um pedido
 *
 * @param nome
 * @return Pedido*
 */
Pedido *createPedido(char *nome);

/**
 * @brief Cria um cliente
 *
 * @param nome O nome do cliente
 * @param pedido Um vetor de pedidos
 * @param quantidadePedidos A quantidade de pedidos
 * @return Cliente*
 */
Cliente *createCliente(char *nome, Pedido **pedido, int quantidadePedidos);

/**
 * @brief Cria um restaurante
 *
 * @param nome O nome do restaurante
 * @param pedido Um vetor de pedidos
 * @param quantidadePedidos A quantidade de pedidos
 * @return Restaurante*
 */
Restaurante *createRestaurante(
    char *nome,
    Pedido **pedido,
    int quantidadePedidos);

void printPedido(Pedido *pedido);

/**
 * @brief Faz um pedido. Adiciona o pedido ao vetor de pedidos do
 * cliente e do restaurante
 *
 * @param cliente O cliente que está fazendo o pedido
 * @param pedido O(s) pedido(s) que o cliente deseja fazer
 * @param quantidadePedidos A quantidade de pedidos
 * @param restaurante O restaurante que irá atender o pedido
 */
void fazerPedido(
    Cliente *cliente,
    Pedido **pedido,
    int quantidadePedidos,
    Restaurante *restaurante);

/**
 * @brief Mostra os pedidos de um cliente em um restaurante
 *
 * @param cliente
 * @param restaurante
 */
void showPedidosDeUmClientePorRestaurante(
    Cliente *cliente,
    Restaurante *restaurante);

/**
 * @brief Mostra os pedidos de um cliente
 *
 * @param cliente
 */
void showPedidosDeUmCliente(Cliente *cliente);

/**
 * @brief Mostra os pedidos de um restaurante
 *
 * @param restaurante
 */
void showPedidosDeUmRestaurante(Restaurante *restaurante);

/**
 * @brief Mostra os restaurantes onde um cliente fez pedido.
 * O cliente fez pelo menos um pedido no restaurante
 *
 * @param cliente
 * @param restaurantes
 * @param quantidadeRestaurantes
 */
void showRestaurantesOndeClienteFezPedido(
    Cliente *cliente,
    Restaurante **restaurantes,
    int quantidadeRestaurantes);

int main()
{
  Pedido **pedidos1 = (Pedido **)malloc(4 * sizeof(Pedido));
  Pedido **pedidos2 = (Pedido **)malloc(5 * sizeof(Pedido));
  Pedido **pedidos3 = (Pedido **)malloc(4 * sizeof(Pedido));

  pedidos1[0] = createPedido("Pizza");
  pedidos1[1] = createPedido("Hamburguer");
  pedidos1[2] = createPedido("Sushi");
  pedidos1[3] = createPedido("Salada");

  pedidos2[0] = createPedido("Coxinha");
  pedidos2[1] = createPedido("Pastel");
  pedidos2[2] = createPedido("Bolo");
  pedidos2[3] = createPedido("Poo");
  pedidos2[4] = createPedido("Cafe");

  pedidos3[0] = createPedido("Abacaxi");
  pedidos3[1] = createPedido("Banana");
  pedidos3[2] = createPedido("Coca-Cola");
  pedidos3[3] = createPedido("Suco de Laranja");

  Cliente *cliente1 = createCliente("Joao", NULL, 0),
          *cliente2 = createCliente("Maria", NULL, 0);

  Restaurante *restaurante1 = createRestaurante("Restaurante1", NULL, 0),
              *restaurante2 = createRestaurante("Restaurante2", NULL, 0);

  fazerPedido(cliente1, pedidos1, 4, restaurante1);
  fazerPedido(cliente2, pedidos2, 5, restaurante2);
  fazerPedido(cliente1, pedidos3, 4, restaurante2);

  showPedidosDeUmClientePorRestaurante(cliente1, restaurante1);
  printf("\n\n");
  showPedidosDeUmClientePorRestaurante(cliente2, restaurante2);
  printf("\n\n");
  showPedidosDeUmClientePorRestaurante(cliente1, restaurante2);
  printf("\n\n");
  showPedidosDeUmCliente(cliente1);
  printf("\n\n");
  showPedidosDeUmCliente(cliente2);
  printf("\n\n");

  showPedidosDeUmRestaurante(restaurante1);
  printf("\n\n");
  showPedidosDeUmRestaurante(restaurante2);
  printf("\n\n");

  Restaurante **restaurantes = (Restaurante **)malloc(2 * sizeof(Restaurante));
  restaurantes[0] = restaurante1;
  restaurantes[1] = restaurante2;

  showRestaurantesOndeClienteFezPedido(cliente1, restaurantes, 2);
  printf("\n\n");
  showRestaurantesOndeClienteFezPedido(cliente2, restaurantes, 2);

  return 0;
}

Pedido *createPedido(char *nome)
{
  Pedido *pedido = (Pedido *)malloc(sizeof(Pedido));
  if (pedido == NULL)
  {
    printf("Erro ao alocar memória para o pedido\n");
    exit(1);
  }

  strcpy(pedido->nome, nome);

  return pedido;
}

Cliente *createCliente(char nome[50], Pedido **pedido, int quantidadePedidos)
{
  Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
  if (cliente == NULL)
  {
    printf("Erro ao alocar memória para o cliente\n");
    exit(1);
  }

  strcpy(cliente->nome, nome);
  cliente->pedidos = pedido;
  cliente->quantidadePedidos = quantidadePedidos;

  return cliente;
}

Restaurante *createRestaurante(
    char nome[50],
    Pedido **pedido,
    int quantidadePedidos)
{
  Restaurante *restaurante = (Restaurante *)malloc(sizeof(Restaurante));
  if (restaurante == NULL)
  {
    printf("Erro ao alocar memória para o restaurante\n");
    exit(1);
  }

  strcpy(restaurante->nome, nome);
  restaurante->pedidos = pedido;
  restaurante->quantidadePedidos = quantidadePedidos;

  return restaurante;
}

void printPedido(Pedido *pedido)
{
  printf("Nome: %s\n", pedido->nome);
}

void fazerPedido(
    Cliente *cliente,
    Pedido **pedido,
    int quantidadePedidos,
    Restaurante *restaurante)
{
  // Realoca a memória para o vetor de pedidos do cliente
  Pedido **newCLientPedidos = (Pedido **)realloc(
      cliente->pedidos,
      (cliente->quantidadePedidos + quantidadePedidos) * sizeof(Pedido *));

  if (newCLientPedidos == NULL)
  {
    printf("Erro ao alocar memória para o pedido\n");
    exit(1);
  }

  // Adiciona os novos pedidos ao vetor de pedidos do cliente
  int count = 0;
  for (int i = 0; i < quantidadePedidos; i++)
  {
    newCLientPedidos[cliente->quantidadePedidos + i] = pedido[i];
    count++;
  }

  // Atualiza a quantidade de pedidos do cliente
  cliente->pedidos = newCLientPedidos;
  cliente->quantidadePedidos += count;

  // Realoca a memória para o vetor de pedidos do restaurante
  Pedido **newRestaurantePedidos = (Pedido **)realloc(
      restaurante->pedidos,
      (restaurante->quantidadePedidos + quantidadePedidos) * sizeof(Pedido *));

  if (newRestaurantePedidos == NULL)
  {
    printf("Erro ao alocar memória para o pedido\n");
    exit(1);
  }

  // Adiciona os novos pedidos ao vetor de pedidos do restaurante
  count = 0;
  for (int i = 0; i < quantidadePedidos; i++)
  {
    newRestaurantePedidos[restaurante->quantidadePedidos + i] = pedido[i];
    count++;
  }

  // Atualiza a quantidade de pedidos do restaurante
  restaurante->pedidos = newRestaurantePedidos;
  restaurante->quantidadePedidos += count;
}

void showPedidosDeUmClientePorRestaurante(Cliente *cliente, Restaurante *restaurante)
{
  printf("Cliente: %s\n", cliente->nome);
  printf("Restaurante: %s\n", restaurante->nome);

  int countPedidos = 0;
  for (int i = 0; i < cliente->quantidadePedidos; i++)
  {
    for (size_t j = 0; j < restaurante->quantidadePedidos; j++)
    {
      if (cliente->pedidos[i] == restaurante->pedidos[j])
      {
        printf("Pedido %d ", countPedidos++);
        printPedido(cliente->pedidos[i]);
      }
    }
  }
}

void showPedidosDeUmCliente(Cliente *cliente)
{
  printf("Cliente: %s\n", cliente->nome);

  for (int i = 0; i < cliente->quantidadePedidos; i++)
  {
    printf("Pedido %d ", i);
    printPedido(cliente->pedidos[i]);
  }
}

void showPedidosDeUmRestaurante(Restaurante *restaurante)
{
  printf("Restaurante: %s\n", restaurante->nome);

  for (int i = 0; i < restaurante->quantidadePedidos; i++)
  {
    printf("Pedido %d ", i);
    printPedido(restaurante->pedidos[i]);
  }
}

void showRestaurantesOndeClienteFezPedido(
    Cliente *cliente,
    Restaurante **restaurantes,
    int quantidadeRestaurantes)
{
  printf("Cliente: %s\n", cliente->nome);

  for (size_t i = 0; i < cliente->quantidadePedidos; i++)
  {
    for (size_t j = 0; j < quantidadeRestaurantes; j++)
    {
      for (size_t k = 0; k < restaurantes[j]->quantidadePedidos; k++)
      {
        if (cliente->pedidos[i] == restaurantes[j]->pedidos[k])
        {
          printf("Restaurante %ld ", j);
          printPedido(restaurantes[j]->pedidos[k]);
        }
      }
    }
  }
}
