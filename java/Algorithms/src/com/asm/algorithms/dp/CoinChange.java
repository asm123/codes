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
public class CoinChange {
    int[] coins;
    int N;
    
    public CoinChange(int[] coins, int N) {
        this.coins = coins;
        this.N = N;
    }
    
    private int getWaysRecursive(int coinIndex, int remaining) {
        if (remaining == 0)
            return 1;
        if (remaining < 0)
            return 0;
        if (coinIndex <= 0 && remaining > 0)
            return 0;
        return getWaysRecursive(coinIndex-1, remaining)
                + getWaysRecursive(coinIndex, remaining-coins[coinIndex-1]);
    }
    
    public int getWaysRecursive() {
        return getWaysRecursive(coins.length, N);
    }
    
    public int getWaysDP() {
        int[][]ways = new int[N+1][coins.length];
        
        for (int j = 0; j < coins.length; j++) {
            ways[0][j] = 1;
        }
        
        for(int i = 1; i <= N; i++) {
            for (int j = 0; j < coins.length; j++) {
                int includingJ = (i-coins[j] >= 0) ? ways[i-coins[j]][j] : 0;
                int excludingJ = (j >= 1) ? ways[i][j-1] : 0;
                ways[i][j] = includingJ + excludingJ;
            }
        }
        
        return ways[N][coins.length-1];
    }
    
    public static void main(String[] args) {
        int[] coins = {2, 5, 3, 6};
        int N = 10;
        CoinChange coinChange = new CoinChange(coins, N);
        System.out.println("Ways: " + coinChange.getWaysRecursive());
        System.out.println("Ways: " + coinChange.getWaysDP());
    }
}
