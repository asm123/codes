/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.searching;

/**
 * Binary search for integer array
 * @author asmita
 */
public class BinarySearch {
    
    private static int searchRecursive(int[] array, int low, int high, int x) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            if (array[mid] == x)
                return mid;
            if (x < array[mid])
                return searchRecursive(array, low, mid-1, x);
            return searchRecursive(array, mid+1, high, x);
        }
        return -1;
    }
    
    private static int searchIterative(int[] array, int x) {
        int low = 0;
        int high = array.length-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (array[mid] == x)
                return mid;
            if (x < array[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    
    private static int findInsertionLocation(int[] array, int key, int low, int high) {
        if (high <= low)
            return (array[low] < key ? (low+1) : low);
        int mid = low + (high-low)/2;
        if (key == array[mid])
            return mid+1;
        if (key < array[mid])
            return findInsertionLocation(array, key, low, mid-1);
        return findInsertionLocation(array, key, mid+1, high);
    }
    
    public static int findInsertionLocation(int[] array, int key) {
        return findInsertionLocation(array, key, 0, array.length-1);
    }
    
    public static int search (int[] array, int x) {
        return searchRecursive(array, 0, array.length-1, x);
//        return searchIterative(array, x);
    }
    
    public static void main (String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int x = 45;
        System.out.println("Found x at " + search(array, x));
    }
}
