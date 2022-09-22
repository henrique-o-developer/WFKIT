# just in time compiler

digamos que esse seja o code: 

```wfkit

:main: function arg1 arg2;

:var1: var "string";
:var2: var -124.0f;

:func2: run 1, 73;

end-of function :main:;

:func2: function;

:arg3: arg 1;
:arg4: arg 2;

:var3: var 'c';
:var4: var {1, 2, 3, 4, 5};

end-of function :func2:;

:func3: function arg3 arg4;

:var3: var 'c';
:var4: var {1, 2, 3, 4, 5};

end-of function :func3:;

```

nesse caso que o programa fará é o seguinte:

* definir a função main
* passar os arg
* declarar as variaveis
* definir a funcção func2
* rodar o função func3 com os parametros (1, 73)

neste caso ela NUNCA ira tocar na função func3
assim não disperdiçando tempo e memoria :)

como eu vou fazer isso
eu não sei .-.

# teoria

* separar por ";"
* separar por spaços (":main:", "function", "arg1", "arg2") tokenizar (detectar a palavra token "function" e ";")
* compilar
* caso um run seja detectado ele vai procurar pela função e então rodala

# tipos
Não tem tipos, eu acho

{} -> array, keys etc...
var -> declare var

# ideias

* separar por ";"
* separar por " "
* procurar por tokens (QUE NÃO PRECISEM DE ESPAÇOS [ como: { + - / * } ]) e se ouver separar
* procurar pela func main compilar e remover da task principal e adicionar a uma secundária
* rodar linha por linha (separadas por ";")
* procurar antes nessa linha um run caso ache procurar na task principal por uma função com o mesmo nome caso não achar disparar um erro
* caso a flag (--generate-executable) seja encontrada criar uma nova task com todo o codigo ja executado e compilar pra um exe 

Vai ser bem-parecido com lua

Caso seja passado o parametro --generate-executable o programa ira compilar de um jeito que eu ainda não sei um executavel... se bem que ele meio que ja faz isso

 
