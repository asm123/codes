/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.sorting;

/**
 *
 * @author asmita
 */
public class CountSort extends Sort {

    private int getLargestNumber(int[] array) {
        int maxIndex = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > array[maxIndex])
                maxIndex = i;
        }
        return array[maxIndex];
    }
    
    @Override
    public void sort(int[] array) {
        int largestNumber = getLargestNumber(array);
        int[] countArray = new int[largestNumber+1];
        for (Integer number: array) {
            countArray[number]++;
        }
        int k = 0;
        for (int i = 0; i < countArray.length; i++) {
            int count = countArray[i];
            for (int j = 0; j < count; j++)
                array[k++] = i;
        }
    }
}
