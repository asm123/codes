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
public class MinCostPath {
    int[][] cost;
    
    public MinCostPath(int[][] cost) {
        this.cost = cost;
    }
    
    public int getMinCostDP(int destI, int destJ) {
        int[][] minCost = new int[destI+1][destJ+1];
        
        // Element (0,0)
        minCost[0][0] = cost[0][0];
        
        // 0th row
        for (int j = 1; j <= destJ; j++) {
            minCost[0][j] = cost[0][j] + minCost[0][j-1];
        }
        
        // 0th column
        for (int i = 1; i <= destI; i++) {
            minCost[i][0] = cost[i][0] + minCost[i-1][0];
        }
        
        // fill up the matrix till (destI, destJ)
        for (int i = 1; i <= destI; i++) {
            for (int j = 1; j <= destJ; j++) {
                minCost[i][j] = cost[i][j] + min(minCost[i-1][j], minCost[i][j-1], minCost[i-1][j-1]);
            }
        }
        
        return minCost[destI][destJ];
    }
    
    private int min(int x, int y, int z) {
        return Math.min(Math.min(x, y), z);
    }
    
    public int getMinCostRecursive(int destI, int destJ) {
        if (destI < 0 || destJ < 0) {
            return Integer.MAX_VALUE;
        }
        if (destI == 0 && destJ == 0) {
            return cost[destI][destJ];
        }
        return cost[destI][destJ] + min(getMinCostRecursive(destI-1, destJ), 
                getMinCostRecursive(destI, destJ-1), 
                getMinCostRecursive(destI-1, destJ-1));
    }
    
    public static void main(String[] args) {
        int[][] cost = {{1, 2, 3},
                        {4, 8, 2},
                        {1, 5, 3}};
        MinCostPath minCostPath = new MinCostPath(cost);
        System.out.println("Min cost: " + minCostPath.getMinCostDP(2, 2));
        System.out.println("Min cost: " + minCostPath.getMinCostRecursive(2, 2));
    }
}
