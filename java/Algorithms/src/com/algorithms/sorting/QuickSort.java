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
    
    private void quickSortRecursive(int[] array, int low, int high) {
        if (low < high) {
            int partitionIndex = partitionRandomized(array, low, high);
            if (low < partitionIndex-1)
                quickSortRecursive(array, low, partitionIndex-1);
            if (partitionIndex < high)
                quickSortRecursive(array, partitionIndex+1, high);
        }
    }
    
    private void quickSortIterative(int[] array, int low, int high) {
        int[] stack = new int[high-low+1];
        int top = -1;
        stack[++top] = low;
        stack[++top] = high;
        
        while (top >= 0) {
            high = stack[top--];
            low = stack[top--];
            
            int pivotPosition = partitionClassic(array, low, high);
            
            if (pivotPosition-1 > low) {
                stack[++top] = low;
                stack[++top] = pivotPosition;
            }
            
            if (pivotPosition+1 < high) {
                stack[++top] = pivotPosition+1;
                stack[++top] = high;
            }
        }
    }
    
    @Override
    public void sort(int[] array) {
//        quickSortRecursive(array, 0, array.length-1);
        quickSortRecursive(array, 0, array.length-1);
    }
    
}
