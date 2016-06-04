/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.gfg.solutions;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author asmita
 */
public class SortInWaveForm {
    
    public void sortSimple(int[] array) {
        Arrays.sort(array);
        for (int i = 0; i < array.length; i += 2) {
            if (i+1 < array.length) {
                swap(array, i, i+1);
            }
        }
        for (int i = 0; i < array.length; i++)
            System.out.print(array[i] + " ");
        System.out.println();
    }
    
    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    public void sortSwap(int[] array) {
        for (int i = 0; i < array.length; i += 2) {
            if (i+1 < array.length && array[i] < array[i+1])
                swap(array, i, i+1);
            if (i+2 < array.length && array[i+1] > array[i+2])
                swap(array, i+1, i+2);
        }
        for (int i = 0; i < array.length; i++)
            System.out.print(array[i] + " ");
        System.out.println();
    }
    
    public static void main (String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String line = scanner.next().trim();
        int testCases = Integer.parseInt(line);
        for (int t = 0; t < testCases; t++) {
            line = scanner.next().trim();
            int length = Integer.parseInt(line);
            int[] array = new int[length];
            for (int i = 0; i < array.length; i++) {
                array[i] = Integer.parseInt(scanner.next());
            }
            new SortInWaveForm().sortSwap(array);
        }
    }
}
