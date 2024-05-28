#include <stdio.h>
#include <string.h>
#include <python3.10/Python.h>

int main(int argc, char const *argv[])
{

  Py_Initialize();

  // Verifica se o interpretador foi iniciado
  if (!Py_IsInitialized())
  {
    printf("Erro na inicialização do Python\n");
    return 1;
  }

  FILE *script = fopen("script.py", "r");

  if (!script)
  {
    perror("Falha ao abrir o arquivo");
    Py_Finalize();
    return 1;
  }

  // Executa o script Python
  PyRun_SimpleFile(script, "script.py");

  // Fecha o arquivo
  fclose(script);

  Py_Finalize();

  FILE *pythonOutput = fopen("hello.txt", "r");

  if (!pythonOutput)
  {
    perror("Falha ao abrir o arquivo");
    Py_Finalize();
    return 1;
  }

  char line[50];
  while (fscanf(pythonOutput, "%s", line) != EOF)
  {
    printf("Executando em C: %s\n", line);
  }

  return 0;
}
