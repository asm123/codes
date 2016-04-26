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
public class SortTest {
    
    public static void main (String[] args) {
        int[] array = {12, 20, 13, 5, 6};
        System.out.println("Unsorted: " + Arrays.toString(array));
        Sort sorter = new MergeSort();
        sorter.sort(array);
        System.out.println("Sorted: " + Arrays.toString(array));
    }
    
}
