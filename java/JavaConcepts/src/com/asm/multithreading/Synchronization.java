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
public class Synchronization implements Runnable {

    private Account account = new Account();
    
    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            makeWithdrawal(10);
            if (account.getBalance() < 0) {
                System.out.println("Account is overdrawn!");
            }
        }
    }
    
    private synchronized void makeWithdrawal(int amount) {
        if (account.getBalance() >= amount) {
            System.out.println(Thread.currentThread().getName() + " is going to withdraw.");
            /*
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                
            }
            */
            account.withdraw(amount);
            System.out.println(Thread.currentThread().getName() + " completes the withdrawal.");
        }
        else {
            System.out.println("Not enough in the account for " + Thread.currentThread().getName() 
                    + " to withdraw " + account.getBalance());
        }
    }
    
    public static void main(String[] args) {
        Synchronization sync = new Synchronization();
        Thread one = new Thread(sync);
        Thread two = new Thread(sync);
        
        one.setName("Sherlock");
        two.setName("Watson");
        
        one.start();
        two.start();
    }


    
}

class Account {
    private int balance = 50;
    
    public int getBalance() {
        return balance;
    }
    
    public void withdraw(int amount) {
        balance -= amount;
    }
}
