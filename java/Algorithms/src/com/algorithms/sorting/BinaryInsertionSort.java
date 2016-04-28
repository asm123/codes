/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.algorithms.sorting;

import com.algorithms.searching.BinarySearch;

/**
 *
 * @author asmita
 */
public class BinaryInsertionSort extends Sort {
    
    
    @Override
    public void sort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i];
            int insertionLocation = BinarySearch.findInsertionLocation(array, key);
            int j;
            for (j = i-1; j >= insertionLocation; j--) {
                array[j+1] = array[j];
            }
            array[j+1] = key;
        }
    }
    
}
