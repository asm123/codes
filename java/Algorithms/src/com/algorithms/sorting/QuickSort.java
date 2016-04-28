/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.algorithms.sorting;

import java.util.Arrays;

/**
 *
 * @author asmita
 */
public class QuickSort extends Sort {

    private int partition (int array[], int low, int high) {
        int pivotPosition = low + (high-low)/2;
        swap(array, pivotPosition, high);
        int pivot = array[high];
        int i = low-1;
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                swap(array, i, j);
            }
        }
        swap(array, i+1, high);
        return i+1;
    }
    
    private void quickSort(int array[], int low, int high) {
        if (low < high) {
            int partitionIndex = partition(array, low, high);
            quickSort(array, low, partitionIndex-1);
            quickSort(array, partitionIndex+1, high);
        }
    }
    
    @Override
    public void sort(int[] array) {
        quickSort(array, 0, array.length-1);
    }
    
}
