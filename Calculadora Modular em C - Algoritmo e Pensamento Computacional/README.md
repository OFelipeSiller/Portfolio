# Projeto: Calculadora Modular em C

Este projeto implementa uma **calculadora científica e estatística modular** em linguagem **C**, com suporte a operações básicas, avançadas, estatísticas, manipulação de matrizes, além de armazenamento de histórico em arquivo CSV.

## Funcionalidades

A calculadora oferece uma ampla gama de operações, divididas nas seguintes categorias:

### **Operações Básicas**

* **Soma**
* **Subtração**
* **Multiplicação**
* **Divisão** (com tratamento de erro para divisão por zero)

### **Operações Avançadas**

* **Potência**
* **Raiz quadrada**
* **Fatorial** (até 20!)
* **Logaritmo** (base 10)
* **Seno, Cosseno e Tangente**

### **Operações Estatísticas**

* **Média**
* **Mediana**
* **Desvio padrão**
* **Máximo e mínimo**

### **Operações Inteiras**

* **MDC (Máximo Divisor Comum)**
* **MMC (Mínimo Múltiplo Comum)**

### **Matrizes (2x2 e 3x3)**

* Leitura de matrizes
* Impressão formatada
* **Soma de matrizes**
* **Multiplicação de matrizes**

### **Histórico de Operações**

* Registro automático de todas as operações realizadas
* **Visualização** no terminal
* **Exportação** em formato CSV (`historico.csv`)

## Estrutura do Código

O projeto é dividido em seções bem organizadas e comentadas, facilitando a manutenção e futuras expansões:

* `// ===== FUNÇÕES BÁSICAS =====`
* `// ===== FUNÇÕES AVANÇADAS =====`
* `// ===== FUNÇÕES ESTATÍSTICAS =====`
* `// ===== FUNÇÕES DE MATRIZES =====`
* `// ===== HISTÓRICO =====`
* `// ===== ENTRADA =====`
* `// ===== MENU =====`

Cada grupo contém funções específicas para modularizar o código, o que torna o programa fácil de entender e expandir.

## Histórico e Exportação

Todas as operações realizadas são armazenadas no vetor global `historico[]`, que tem um limite de 50 entradas (definido por `MAX_HIST = 50`).

Exemplo de exportação do histórico para CSV:

```
ID,Tipo,A,B,Resultado
1,Soma,5.00,2.00,7.00
2,Divisão,10.00,2.00,5.00
3,Potência,2.00,3.00,8.00
```

Para salvar o histórico, o usuário pode escolher a opção **21 - Salvar Histórico**, e o arquivo `historico.csv` será criado no diretório atual do programa.

## Tecnologias Utilizadas

* **Linguagem**: C (padrão ANSI)

### Bibliotecas:

* `stdio.h` – Entrada/Saída
* `stdlib.h` – Funções utilitárias
* `string.h` – Manipulação de strings
* `math.h` – Funções matemáticas
