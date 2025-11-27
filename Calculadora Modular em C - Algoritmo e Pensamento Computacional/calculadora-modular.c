#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Especificação dos tamanhos de array para o teste de desempenho
#define NUM_SIZES 3
const int BENCHMARK_SIZES[NUM_SIZES] = {100, 1000, 10000};
#define MAX_SIZE 10000 
#define RGM_SIZE 8

// Variáveis globais para contabilizar comparações e deslocamentos
long long comp_bubble = 0, mov_bubble = 0;
long long comp_merge = 0, mov_merge = 0;
long long comp_quick = 0, mov_quick = 0;

// ================= Funções de Apoio =================

// Função para criar um array de números inteiros aleatórios
void generateRandomArray(int arr[], int n) {
    
    srand(time(NULL)); 
    for(int i=0; i<n; i++) {
        
        arr[i] = rand() % 100000; 
    }
}

// Função para exibir o array
void printArray(int arr[], int size) {
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função para reinicializar as métricas antes de cada teste de algoritmo
void resetMetrics() {
    comp_bubble = 0; mov_bubble = 0;
    comp_merge = 0; mov_merge = 0;
    comp_quick = 0; mov_quick = 0;
}

// ================= Bubble Sort =================
void bubbleSort(int arr[], int n, int print_steps) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            comp_bubble++;
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                mov_bubble += 3;
            }
        }
        if (print_steps) {
            printf("Passo %d: ", i+1);
            printArray(arr, n);
        }
    }
}

// ================= Merge Sort =================
// A função merge agora aceita 'print_steps'
void merge(int arr[], int l, int m, int r, int N, int print_steps) {
    int n1 = m-l+1;
    int n2 = r-m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    if (!L || !R) {
        free(L); free(R);
        return; 
    }

    for(int i=0; i<n1; i++) L[i] = arr[l+i];
    for(int i=0; i<n2; i++) R[i] = arr[m+1+i];

    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        comp_merge++;
        if(L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        mov_merge++;
        k++;
    }
    while(i<n1) { arr[k++] = L[i++]; mov_merge++; }
    while(j<n2) { arr[k++] = R[j++]; mov_merge++; }

    free(L);
    free(R);

    if (print_steps) {
        
        printf("Merge: arr[%d..%d] -> ", l, r);
       
        printArray(arr, N);
    }
}

// A função mergeSort agora aceita 'print_steps'
void mergeSort(int arr[], int l, int r, int N, int print_steps) {
    if(l < r) {
        int m = l + (r-l)/2;
        
        mergeSort(arr, l, m, N, print_steps);
        mergeSort(arr, m+1, r, N, print_steps);
        merge(arr, l, m, r, N, print_steps);
    }
}

// ================= Quick Sort =================
// A função partition agora aceita 'print_steps'
int partition(int arr[], int low, int high, int N, int print_steps) {
    int pivot = arr[high]; 
    int i = low - 1;

    for(int j=low; j<high; j++) {
        comp_quick++;
        if(arr[j] <= pivot) {
            i++;
          
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            mov_quick += 3;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    mov_quick += 3;

    if (print_steps) {
       
        printf("Partition: arr[%d..%d], Pivot = %d -> ", low, high, arr[i+1]);
        printArray(arr, N);
    }

    return i+1;
}

// A função quickSort agora aceita 'print_steps'
void quickSort(int arr[], int low, int high, int N, int print_steps) {
    if(low < high) {
        int pi = partition(arr, low, high, N, print_steps);
        quickSort(arr, low, pi-1, N, print_steps);
        quickSort(arr, pi+1, high, N, print_steps);
    }
}

// ================= Teste de Desempenho e Saída em CSV =================


typedef struct {
    char algorithm[20];
    int size;
    long long comparisons;
    long long movements;
    double time_ms;
} Result;

// Array para guardar todos os resultados
Result results[NUM_SIZES * 3]; 
int result_count = 0;

// Função para executar os algoritmos sem mostrar etapas
void runBenchmark(int N, int* original_arr) {
    // Utilizamos alocação dinâmica para o array no teste de desempenho com N elevado
    int *arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) return; 

    clock_t start, end;
    double time_taken;

    // Bubble Sort 
    resetMetrics();
    memcpy(arr, original_arr, N * sizeof(int));
    start = clock();
    bubbleSort(arr, N, 0); 
    end = clock();
    time_taken = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC; 
    results[result_count++] = (Result){"BubbleSort", N, comp_bubble, mov_bubble, time_taken};

    // Merge Sort 
    resetMetrics();
    memcpy(arr, original_arr, N * sizeof(int));
    start = clock();
    mergeSort(arr, 0, N-1, N, 0); 
    end = clock();
    time_taken = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
    results[result_count++] = (Result){"MergeSort", N, comp_merge, mov_merge, time_taken};

    // Quick Sort 
    resetMetrics();
    memcpy(arr, original_arr, N * sizeof(int));
    start = clock();
    quickSort(arr, 0, N-1, N, 0); 
    end = clock();
    time_taken = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
    results[result_count++] = (Result){"QuickSort", N, comp_quick, mov_quick, time_taken};
    
    free(arr);
}

// Função para exibir os resultados no formato CSV
void printCSVResults() {
    printf("\n--- Resultados do Benchmark (CSV) ---\n");
    printf("Algoritmo,N,Comparações,Movimentos,Tempo (ms)\n");
    for(int i = 0; i < result_count; i++) {
        printf("%s,%d,%lld,%lld,%.6f\n", 
               results[i].algorithm, 
               results[i].size, 
               results[i].comparisons, 
               results[i].movements, 
               results[i].time_ms);
    }
}

// PRINCIPAL 
int main() {
    int rgm[RGM_SIZE] = {4,5,4,7,2,4,0,8};
    int arr_small[RGM_SIZE];
    
    // Execução do Exemplo Pequeno (N=8) 
    printf("============================================\n");
    printf("=== Exemplo com Vetor {4,5,4,7,2,4,0,8} (N=%d) ===\n", RGM_SIZE);
    printf("============================================\n\n");

    // Bubble Sort
    printf("--- Bubble Sort ---\n");
    resetMetrics();
    memcpy(arr_small, rgm, RGM_SIZE * sizeof(int));
    clock_t start = clock();
    bubbleSort(arr_small, RGM_SIZE, 1); 
    clock_t end = clock();
    printf("Comparaçoes: %lld, Movimentos: %lld, Tempo: %.6lf s\n\n",
           comp_bubble, mov_bubble, (double)(end-start)/CLOCKS_PER_SEC);
    
    // Merge Sort
    printf("--- Merge Sort (Passo a Passo de Fusão) ---\n");
    resetMetrics();
    memcpy(arr_small, rgm, RGM_SIZE * sizeof(int));
    start = clock();
    mergeSort(arr_small, 0, RGM_SIZE-1, RGM_SIZE, 1); 
    end = clock();
    printf("Comparaçoes: %lld, Movimentos: %lld, Tempo: %.6lf s\n\n",
           comp_merge, mov_merge, (double)(end-start)/CLOCKS_PER_SEC);

    // Quick Sort
    printf("--- Quick Sort (Passo a Passo de Partição) ---\n");
    resetMetrics();
    memcpy(arr_small, rgm, RGM_SIZE * sizeof(int));
    start = clock();
    quickSort(arr_small, 0, RGM_SIZE-1, RGM_SIZE, 1); 
    end = clock();
    printf("Comparaçoes: %lld, Movimentos: %lld, Tempo: %.6lf s\n\n",
           comp_quick, mov_quick, (double)(end-start)/CLOCKS_PER_SEC);


    // Execução do Teste de Desempenho com Arrays Aleatórios 
    printf("==================================================\n");
    printf("=== Execuçao do Benchmark com Vetores Aleatórios ===\n");
    printf("==================================================\n");
    printf("(Impressão de passos desativada para N > %d)\n\n", RGM_SIZE);

    int *temp_array = (int*)malloc(MAX_SIZE * sizeof(int));
    if (temp_array == NULL) {
        fprintf(stderr, "Erro de alocação de memória para o benchmark.\n");
        return 1;
    }

    for(int i = 0; i < NUM_SIZES; i++) {
        int N = BENCHMARK_SIZES[i];
        printf("Rodando N = %d...\n", N);

       
        generateRandomArray(temp_array, N); 

        
        runBenchmark(N, temp_array);
    }
    
    free(temp_array);

    // Exibe os resultados no formato CSV
    printCSVResults();

    return 0;
}
