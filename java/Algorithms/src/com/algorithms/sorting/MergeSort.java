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
public class MergeSort extends Sort {

    private void mergeSort(int[] array, int left, int right) {
        if (left < right) {
            int mid = left + (right-left)/2;
            mergeSort(array, left, mid);
            mergeSort(array, mid+1, right);
            merge(array, left, mid, right);
        }
    }
    
    private void merge(int[] array, int left, int mid, int right) {
        int leftLength = mid-left+1;
        int rightLength = right-mid;
        
        int[] leftArray = new int[leftLength];
        int[] rightArray = new int[rightLength];
        
        int k = left;
        for (int i = 0; i < leftLength; i++) {
            leftArray[i] = array[k];
            k++;
        }
        for (int i = 0; i < rightLength; i++) {
            rightArray[i] = array[k];
            k++;
        }
        
        int l = 0, r = 0;
        k = left;
        
        while (l < leftLength && r < rightLength) {
            if (leftArray[l] <= rightArray[r]) {
                array[k] = leftArray[l];
                l++;
            }
            else {
                array[k] = rightArray[r];
                r++;
            }
            k++;
        }
        while (l < leftLength) {
            array[k] = leftArray[l];
            l++;
            k++;
        }
        while (r < rightLength) {
            array[k] = rightArray[r];
            r++;
            k++;
        }
    }
    
    @Override
    public void sort(int[] array) {
        mergeSort(array, 0, array.length-1);
    }
    
}
