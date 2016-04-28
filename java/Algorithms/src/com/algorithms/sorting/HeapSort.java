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
public class HeapSort implements Sort {

    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    private void buildMaxHeap(int[] array) {
        int n = array.length;
        for (int i = n/2-1; i >= 0; i--)
            maxHeapify(array, i, n);
    }
    
    private void maxHeapify(int[] array, int i, int length) {
        int left = 2*i + 1;
        int right = left + 1;
        int largest = i;
        if (left < length && array[left] > array[largest])
            largest = left;
        if (right < length && array[right] > array[largest])
            largest = right;
        if (largest != i) {
            swap(array, i, largest);
            maxHeapify(array, largest, length);
        }
    }
    
    @Override
    public void sort(int[] array) {
        buildMaxHeap(array);
        int length = array.length;
        for (int i = length-1; i >= 0; i--) {
            swap(array, i, 0);
            length--;
            maxHeapify(array, 0, length);
        }
    }
    
}
