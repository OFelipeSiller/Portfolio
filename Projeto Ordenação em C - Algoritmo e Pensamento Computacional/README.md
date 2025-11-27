Este repositório apresenta um programa escrito em C que executa testes de desempenho para três algoritmos tradicionais de ordenação: Bubble Sort, Merge Sort e Quick Sort. O software avalia o rendimento desses métodos em arrays de diversos tamanhos gerados aleatoriamente, registrando o total de comparações, deslocamentos e duração da execução.

## Algoritmos Implementados

#### 1. Bubble Sort

O Bubble Sort representa um método de ordenação básico que percorre repetidamente o array, trocando elementos adjacentes se estiverem na ordem incorreta. Sua eficiência é de O(n²) no cenário mais desfavorável, o que o torna inadequado para arrays extensos. Contudo, para arrays reduzidos ou parcialmente organizados, pode apresentar resultados aceitáveis.

#### 2. Merge Sort

O Merge Sort constitui um método de ordenação eficaz que emprega a estratégia de dividir para conquistar. Ele fragmenta o array em subarrays menores, organiza-os individualmente e depois os combina. Apresenta eficiência de O(n log n) no pior caso, sendo particularmente útil para arrays volumosos.

#### 3. Quick Sort

O Quick Sort é um algoritmo de ordenação que também se baseia em divisão e conquista. Seleciona um elemento como pivô e divide o array em partes com elementos menores e maiores que o pivô, ordenando recursivamente cada seção. Sua performance média é O(n log n), mas pode degradar para O(n²) no pior cenário, embora isso seja infrequente com uma seleção adequada do pivô.

Esses três algoritmos foram desenvolvidos para organizar arrays de variados tamanhos e para quantificar comparações, deslocamentos e tempo gasto.

### Como Compilar e Executar

Para compilar o código, utilize o compilador gcc:

```
gcc -O1 -std=c11 src/*.c -o ordena
```

Para executar o programa:

```
./ordena
```

O software executará os algoritmos de ordenação tanto em arrays pequenos, exibindo etapas detalhadas, quanto em arrays maiores, com resumos consolidados.

## Critérios de Contagem de Operações

A quantificação de operações (comparações e deslocamentos) segue estes princípios:

- **Comparações**: Cada verificação entre dois elementos durante o processo de ordenação (por exemplo, verificar se um item é superior a outro).
- **Deslocamentos**: Cada transferência ou permuta de um elemento dentro do array.

Essas medidas são reunidas para cada um dos três algoritmos e exibidas tanto ao término da execução quanto durante o processamento de arrays pequenos (para uma avaliação etapa por etapa).

## Técnica de Avaliação Temporal

A duração da execução é determinada empregando a função `clock()` da biblioteca padrão do C. O tempo é expresso em milissegundos e é anotado para cada rodada de algoritmo. A avaliação temporal ocorre em três fases para cada método:

1. #### Antes da execução do algoritmo.
2. #### Durante o processamento do algoritmo.
3. #### Após o fim da execução do algoritmo.

Os dados temporais são fornecidos em milissegundos (ms).

### Resultados

Os dados são produzidos para três dimensões distintas de array (100, 1000 e 10000) e são formatados em CSV. Um modelo de como a saída será estruturada:

```
Algoritmo,N,Comparações,Movimentos,Tempo (ms)
BubbleSort,100,234,123,0.234567
MergeSort,100,567,234,0.345678
QuickSort,100,123,456,0.123456
```

### Visualização Opcional

É possível criar gráficos dos resultados importando o CSV em ferramentas como Excel ou Python para traçar curvas de tempo, comparações e deslocamentos em relação ao tamanho do array.

### Análise Comparativa

#### Eficiência Computacional vs. Capacidade de Expansão

- O Bubble Sort é direto, mas sua complexidade de O(n²) o torna impróprio para arrays extensos.
- O Merge Sort possui uma complexidade mais otimizada de O(n log n) e se sai bem com arrays grandes, embora a necessidade de memória extra possa ser uma restrição.
- O Quick Sort costuma ser mais veloz que o Merge Sort na média devido ao melhor aproveitamento do cache de memória, mas pode regredir para O(n²) no pior caso se o pivô for mal escolhido.

### Restrições Identificadas

Para arrays pequenos (até 1000 itens), todos os algoritmos funcionam de maneira satisfatória. Porém, conforme o array cresce (exemplo: 10.000 elementos), o Quick Sort e o Merge Sort demonstram superioridade clara sobre o Bubble Sort.

### Considerações Finais

- Merge Sort e Quick Sort são as opções mais viáveis para arrays grandes graças à sua eficiência de O(n log n).
- Bubble Sort deve ser evitado em contextos com grandes quantidades de dados devido à sua natureza quadrática.
- O Quick Sort geralmente é o mais rápido em termos de tempo para arrays de médio porte, enquanto o Merge Sort garante maior previsibilidade em estabilidade e rendimento.

## Observações Adicionais

Este repositório proporciona uma avaliação prática do rendimento de diversos algoritmos de ordenação conforme o tamanho do array. A realização e a coleta de métricas asseguram resultados uniformes e comparáveis entre os métodos. O exemplo pequeno utiliza o array {4,5,4,7,2,4,0,8} para demonstrações passo a passo.
