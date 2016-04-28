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
        int[] array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//        int[] array = {2, 8, 7, 1, 3, 5, 6, 4};
        System.out.println("Unsorted: " + Arrays.toString(array));
        Sort sorter = new QuickSort();
        sorter.sort(array);
        System.out.println("Sorted: " + Arrays.toString(array));
    }
    
}
