# Dicionário

## Compilar
Se estiver em um ambiente GNU/Linux com o cmake instalado, você poderá usar os comandos:

- cmake: para compilar o arquivo normalmente.
```
cmake -H. -Bbuild
cmake --build build -- -j3
```

- caso não esteja com o comando make disponivel, você poderá usar o g++ com o comando dentro da pasta raiz:  
```g++ -Wall -std=c++11 src/driver.cpp -o driver -Iinclude```  

## Executar
Após a compilação, você poderá executar o código com o comando ```./bin/dictionary```, ou ```./driver``` (se não usou make).

### Authorship
- Henrique David de Medeiros	(henriquemed101@gmail.com)
- Pablo Emanuell L. Targino	(pabloemanuell@academico.ufrn.br)