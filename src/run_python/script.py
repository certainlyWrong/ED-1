hello = "hello-em-python\n"

# Se o arquivo não existir, então crie
# Se o arquivo exitir, então adicione no final
with open("hello.txt", "+a") as file:
    file.write(hello)
    print(hello)
