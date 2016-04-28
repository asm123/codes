/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.algorithms.sorting;

/**
 *
 * @author asmita
 */
public class SelectionSort extends Sort {
    
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
}
