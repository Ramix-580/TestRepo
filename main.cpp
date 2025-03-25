//
//  main.cpp
//  Actividad_12
//
//  Created by Ramiro Preciado Martínez on 15/03/25.
//

#include <iostream>
using namespace std;

//Funciones para ordenamientos
//Función de intercambio
void intercambio(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
//Función de selección
void seleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}
//Función de incerción
void insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Función de Shell Sort
void shellSort(int vector[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = vector[i];
            int j;
            for (j = i; j >= gap && vector[j - gap] > temp; j -= gap) {
                vector[j] = vector[j - gap];
            }
            vector[j] = temp;
        }
    }
}

// Función para particionar el arreglo en QuickSort
int partition(int vector[], int low, int high) {
    int pivot = vector[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (vector[j] < pivot) {
            i++;
            swap(vector[i], vector[j]);
        }
    }
    swap(vector[i + 1], vector[high]);
    return (i + 1);
}

// Función de QuickSort
void quickSort(int vector[], int low, int high) {
    if (low < high) {
        int pi = partition(vector, low, high);
        quickSort(vector, low, pi - 1);
        quickSort(vector, pi + 1, high);
    }
}

void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    
    
    //Declaración de un vector de 10 elementos
    int vector[9], n=10;
    
    cout << "Ingrese 10 números positivos aleatorios de valor entero:\n";
    for( int i=0; i<=9; i++){
        cin >>vector[i];
    }
    cout <<"El arreglo:\n";
    for ( int i=0; i<=9; i++){
        cout << vector[i] << " " <<endl;
    }
    
    int opcion;
        cout << "Ingrese el número correspondiente del ordenamiento que desea:\n";
        cout << "1.- Ordenamiento por intercambio\n";
        cout << "2.- Ordenamiento por selección\n";
        cout << "3.- Ordenamiento por inserción\n";
        cout << "4.- Ordenamiento por Shellsort\n";
        cout << "5.- Ordenamiento por Quicksort\n";
        cin >> opcion;
    

        switch (opcion) {
            case 1:
                intercambio(vector, 10);
                cout << "Vector ordenado por intercambio: ";
                break;
            case 2:
                seleccion(vector, 10);
                cout << "Vector ordenado por selección: ";
                break;
            case 3:
                insercion(vector, 10);
                cout << "Vector ordenado por inserción: ";
                break;
            case 4:
                shellSort(vector, 10);
                cout << "Vector ordenado po Shellsort";
                break;
            case 5:
                quickSort(vector, 0, n-1);
                cout << "Vector ordenado por Quicksort";
                break;
            default:
                cout << "Opción inválida.\n";
                return 1; // Termina el programa con error
        }

        imprimirArreglo(vector, 10);
    
    return 0;
}


