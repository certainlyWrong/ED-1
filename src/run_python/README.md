# Tutorial
Executando um script Python a partir de um programa em C.

## Requisitos
Usar o Ubuntu ou sistemas baseados em Debian.
Ter o Python instalado na máquina e também a biblioteca Python.h. Para isso é necessário instalar o pacote python3-dev, que fornece os arquivos de cabeçalho necessários para compilar módulos Python.

```bash
sudo apt-get install python3-dev
```

## Como Compilar
O comando abaixo compila o arquivo execute_python.c e cria um arquivo executável chamado main. Preste atenção na versão do Python que você está usando, pois o nome da biblioteca pode mudar.


```bash
gcc execute_python.c -o main -lpython3.10
```

## Como Executar

```bash
./main
```
