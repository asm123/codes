/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.gfg.solutions;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Given an unsorted array arr[0..n-1] of size n, find the minimum length
 * subarray arr[s..e] such that sorting this subarray makes the whole array
 * sorted.
 *
 * @author asmita
 */
public class SmallestUnsortedSubarray {

    public void find(int[] array) {
        int begin, end, foundIndex = -1;
        for (int i = 1; i < array.length; i++) {
            if (array[i] < array[i - 1]) {
                foundIndex = i - 1;
                break;
            }
        }
        if (foundIndex == -1) {
            System.out.println("0 0");
            return;
        }
            
        begin = foundIndex;
        while (begin > 0 && array[foundIndex] < array[begin]) {
            begin--;
        }
        end = array.length - 1;
        while (end > 0 && array[end] > array[end - 1]) {
            end--;
        }
        
        int max = array[begin];
        int min = array[begin];
        for (int i = begin + 1; i <= end; i++) {
            if (array[i] > max) {
                max = array[i];
            }
            if (array[i] < min) {
                min = array[i];
            }
        }

        while (begin > 0 && array[begin-1] > min) {
            begin--;
        }
        
        for (int i = end+1; i < array.length; i++) {
            if (array[i] < max)
                end++;
            else
                max = array[i];
        }
        
        System.out.println(begin + " " + end);
    }

    public static void main(String[] args) {
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
            new SmallestUnsortedSubarray().find(array);
        }
    }
}
