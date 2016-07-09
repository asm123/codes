/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.multithreading;

/**
 *
 * @author asmita
 */
public class ManyThreads {
    
    public static void main(String[] args) throws InterruptedException {
        NameRunnable nr = new NameRunnable();
        Thread one = new Thread(nr);
        Thread two = new Thread(nr);
        Thread three = new Thread(nr);
        
        one.setName("Sherlock");
        one.setPriority(Thread.MAX_PRIORITY);
        two.join();
        
        two.setName("Arya");
        three.setName("PiedPiper");
        
        
        
        one.start();
        two.start();
        three.start();
    }
    
}

class NameRunnable implements Runnable {

    @Override
    public void run() {
        for (int i = 0; i < 3; i++) {
            System.out.println("Run by " + Thread.currentThread().getName() 
                    + "," + Thread.currentThread().getId() + ", i: " + i);
        }
    }
    
}
