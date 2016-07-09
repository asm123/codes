/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.multithreading;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author asmita
 */
public class WaitTest {
    
    public static void main(String[] args) {
        System.out.println("1");
        
        synchronized(args) {
            System.out.println("2");
            try {
                // indefinite waiting
                args.wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(WaitTest.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        System.out.println("3");
    }
}
