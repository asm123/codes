/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.dp;

/**
 *
 * @author asmita
 */
public class MatrixChainMultiplication {
    private int[] dimensions;
    
    public MatrixChainMultiplication(int[] dimensions) {
        this.dimensions = dimensions;
        
    }
    
    public int getMultiplicationCostRecursive(int i, int j) {
        if (i == j) {
            return 0;
        }
        int minCost = Integer.MAX_VALUE;
        for (int k = i; k < j; k++) {
            int currentCost = getMultiplicationCostRecursive(i, k) 
                    + getMultiplicationCostRecursive(k+1, j)
                    + dimensions[i-1] * dimensions[k] * dimensions[j];
            minCost = Math.min(minCost, currentCost);
        }
        
        return minCost;
    }
    
    public int getMultiplicationCostDP() {
        int[][] cost = new int[dimensions.length][dimensions.length];
        
        for (int i = 1; i < cost.length; i++) {
            cost[i][i] = 0;
        }
        
        // chain length
        for (int chainLength = 2; chainLength < dimensions.length; chainLength++) {
            // start of chain
            for (int i = 1; i <= dimensions.length-chainLength+1; i++) {
                // end of chain
                int j = i + chainLength - 1;
                if (j == dimensions.length) {
                    continue;
                }
                cost[i][j] = Integer.MAX_VALUE;

                // index at which chain is split
                for (int k = i; k < j; k++) {
                    cost[i][j] = Math.min(cost[i][j], cost[i][k] + cost[k+1][j] 
                            + dimensions[i-1] * dimensions[k] * dimensions[j]);
                }
            }
        }
        
        return cost[1][dimensions.length-1];
    }
    
    public static void main(String[] args) {
        int[] dimensions = {40, 20, 30, 10, 30};
        MatrixChainMultiplication m = new MatrixChainMultiplication(dimensions);
        System.out.println("Recursive cost: " + m.getMultiplicationCostRecursive(1, dimensions.length-1));
        System.out.println("DP cost: " + m.getMultiplicationCostDP());
    }
    
}
