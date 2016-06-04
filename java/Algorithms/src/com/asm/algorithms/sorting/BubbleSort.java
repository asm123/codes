/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.sorting;

import java.util.Arrays;

/**
 *
 * @author asmita
 */
public class BubbleSort extends Sort {

    
    @Override
    public void sort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = i+1; j < array.length; j++) {
                if (array[i] > array[j])
                    swap(array, i, j);
            }
        }
    }
}
