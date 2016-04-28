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
    
    private void quickSort(int array[], int low, int high) {
        int partitionIndex = partition(array, low, high);
        if (low < partitionIndex-1)
            quickSort(array, low, partitionIndex-1);
        if (partitionIndex < high)
            quickSort(array, partitionIndex, high);
    }
    
    @Override
    public void sort(int[] array) {
        quickSort(array, 0, array.length-1);
    }
    
}
