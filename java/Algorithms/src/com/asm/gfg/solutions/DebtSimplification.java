/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.gfg.solutions;

import java.util.Arrays;

/**
 *
 * @author asmita
 */
public class DebtSimplification {
    int[][] debt;
    
    public DebtSimplification (int[][] debt) {
        this.debt = debt;
    }
    
    public void simplify() {
        int n = debt.length;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) {
                        continue;
                    }
                    if (debt[i][j] > 0 && debt[j][k] > 0) {
                        if (debt[i][j] > debt[j][k]) {
                            debt[i][j] -= debt[j][k];
                            debt[i][k] += debt[j][k];
                            debt[j][k] = 0;
                        }
                        else {
                            debt[i][k] += debt[i][j];
                            debt[j][k] -= debt[i][j];
                            debt[i][j] = 0;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                System.out.println(i + "," + j + " : " + debt[i][j]);
            }
        }
    }
    
    public static void main (String[] args) {
        /*
        int[][]debt = {{0, 6000, 0, 2000}, 
                        {0, 0, 5000, 0},
                        {0, 0, 0, 0},
                        {0, 0, 4000, 0}};
        */
        
        int[][] debt = {{0, 1000, 2000}, {0, 0, 5000}, {2000, 0, 0}};
        
        new DebtSimplification(debt).simplify();
    }
}
