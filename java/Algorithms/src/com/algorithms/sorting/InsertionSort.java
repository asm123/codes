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
public class InsertionSort implements Sort {

    @Override
    public void sort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i];
            int j = i-1;
            for (j = i-1; j >= 0 && array[j] > key; j--) {
                array[j+1] = array[j];
            }
            array[j+1] = key;
        }
    }
}
