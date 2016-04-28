/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.algorithms.sorting;

import java.util.Arrays;
import java.util.Random;

/**
 *
 * @author asmita
 */
public class QuickSort extends Sort {

    private int partitionMedian (int array[], int low, int high) {
        int pivotPosition = low + (high-low)/2;
        int pivot = array[pivotPosition];
        
        int i = low, j = high;
        while (i <= j) {
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;
            if (i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        return i;
    }
    
    private int partitionClassic(int array[], int low, int high) {
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
    
    private int partitionRandomized(int array[], int low, int high) {
        int pivotPosition = low + new Random().nextInt(high - low);
        swap(array, pivotPosition, high);
        return partitionClassic(array, low, high);
    }
    
    private void quickSort(int array[], int low, int high) {
        if (low < high) {
            int partitionIndex = partitionRandomized(array, low, high);
            if (low < partitionIndex-1)
                quickSort(array, low, partitionIndex-1);
            if (partitionIndex < high)
                quickSort(array, partitionIndex+1, high);
        }
    }
    
    @Override
    public void sort(int[] array) {
        quickSort(array, 0, array.length-1);
    }
    
}
