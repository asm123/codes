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
public class SelectionSort implements Sort {
    
    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    @Override
    public void sort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int minIndex = i;
            for (int j = i+1; j < array.length; j++) {
                if (array[j] < array[minIndex]) 
                    minIndex = j;
            }
            swap(array, i, minIndex);
        }
    }
    
    
    public static void main (String[] args) {
        int[] array = {64, 25, 12, 22, 11};
        System.out.println("Unsorted: " + Arrays.toString(array));
        Sort sorter = new SelectionSort();
        sorter.sort(array);
        System.out.println("Sorted: " + Arrays.toString(array));
    }
}
