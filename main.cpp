#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& arr){
    //si el arreglo tiene 0 o 1 elementos, ya está ordenado
    if (arr.size() <= 1) return;
    //se escoge el pivote como el elemento del medio, arbitrariamente
    int pivot = arr[arr.size() / 2];
    //se crean dos arreglos para guardar los elementos menores y mayores al pivote
    std::vector<int> left, right;
    for (int i = 0; i < arr.size(); i++){
        //se salta el pivote, ya que no se necesita comparar consigo mismo
        if (i == arr.size() / 2) continue;
        //si el elemento es menor al pivote, se agrega al arreglo de la izquierda
        //si es mayor, se agrega al de la derecha
        if (arr[i] < pivot) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    //se aplica lo mismo a los dos arreglos
    quick_sort(left);
    quick_sort(right);
    //cuando solo quede un elemento en cada arreglo, el stack de llamadas recursivas se desapila
    //y se concatenan los arreglos
    //primero el arreglo de la izquierda, luego el pivote, y finalmente el arreglo de la derecha
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());

    // Actualizar el vector original
    arr = left;
}

int main() {
    std::vector<int> arr = {1, 5, 3, 2, 4, 6, 7, 8, 9, 0};
    quick_sort(arr);
    std::cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}