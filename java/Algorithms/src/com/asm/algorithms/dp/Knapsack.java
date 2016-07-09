/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.dp;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author asmita
 */
class Item {
    private int value;
    private int weight;

    public Item(int value, int weight) {
        this.value = value;
        this.weight = weight;
    }

    public int getValue() {
        return value;
    }

    public int getWeight() {
        return weight;
    }
}

public class Knapsack {
    private final Item[] items;
    private final int capacity;
    
    
    public Knapsack(Item[] items, int capacity) {
        this.items = items;
        this.capacity = capacity;
    }
    
    private int solveRecursive(int w, int n) {
        if (n == 0 || w == 0) {
            return 0;
        }
        if (items[n-1].getWeight() > w) {
            return solveRecursive(w, n-1);
        }
        return Math.max(items[n-1].getValue() + solveRecursive(w-items[n-1].getWeight(), n-1),
                solveRecursive(w, n-1));
    }
    
    public int solveRecursive() {
        return solveRecursive(capacity, items.length);
    }
    
    public int solveDP() {
        int[][] dp = new int[items.length+1][capacity+1];
        
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if (items[i-1].getWeight() > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = Math.max(items[i-1].getValue() + dp[i-1][j-items[i-1].getWeight()], dp[i-1][j]);
                }
            }
        }
        
        return dp[items.length][capacity];
    }
    
    
    public static void main(String[] args) {
        List<Item> items = new ArrayList<>();
        int[] val = {60, 100, 120};
        int[] w = {10, 20, 30};
        int W = 50;
        for (int i = 0; i < val.length; i++) {
            items.add(new Item(val[i], w[i]));
        }
        Knapsack knapsack = new Knapsack(items.toArray(new Item[items.size()]), W);
        System.out.println("Recursive: " + knapsack.solveRecursive());
        System.out.println("DP: " + knapsack.solveDP());
    }
}

