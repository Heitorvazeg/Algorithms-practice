/*Merge Sort:
Divide and Conquer algoritmo. Função recursiva (chama ela em si mesma).
Divide o array com o MergeSort várias vezes até sobrar 1 elemento em cada array. Depois, 
Merge pega os subarrays e os coloca nos antigos arrays, mas em ordem, até sobrar apenas 1, ordenado.
Quando divide o array em vários, pega primeiro o lado esquerdo e faz td, e dps pega o direito e faz td. Segura
até o último, onde pega os 2 últimos arrays ordenados e ordena. O(n log n): Mais rápido do que selection e 
bubble. Usa mais espaço de memória.*/