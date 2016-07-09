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
public class EggDropping {

    public int solveRecursive(int remainingEggs, int remainingFloors) {
        if (remainingFloors == 0 || remainingFloors == 1) {
            return remainingFloors;
        }
        if (remainingEggs == 1) {
            return remainingFloors;
        }
        int minimumNumberOfTrials = Integer.MAX_VALUE;
        for (int floor = 1; floor <= remainingFloors; floor++) {
            int trials = Math.max(solveRecursive(remainingEggs-1, floor-1),
                    solveRecursive(remainingEggs, remainingFloors-floor));
            minimumNumberOfTrials = Math.min(trials, minimumNumberOfTrials);
        }
        return 1 + minimumNumberOfTrials;
    }
    
    public int solveDP(int eggs, int floors) {
        int[][] dp = new int[eggs+1][floors+1];
        
        for (int egg = 1; egg <= eggs; egg++) {
            dp[egg][0] = 0;
            dp[egg][1] = 1;
        }
        
        for (int floor = 1; floor <= floors; floor++) {
            dp[1][floor] = floor;
        }
        
        for (int egg = 2; egg <= eggs; egg++) {
            for (int floor = 2; floor <= floors; floor++) {
                dp[egg][floor] = Integer.MAX_VALUE;
                for (int i = 1; i <= floor; i++) {
                    dp[egg][floor] = Math.min(dp[egg][floor], 1+Math.max(dp[egg-1][i-1], dp[egg][floor-i]));
                }
            }
        }
        
        return dp[eggs][floors];
    }

    public static void main(String[] args) {
        int eggs = 3;
        int floors = 24;
        System.out.println("Recursive: " + new EggDropping().solveRecursive(eggs, floors));
        System.out.println("Recursive: " + new EggDropping().solveDP(eggs, floors));
    }
}
