/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.data_structures.linkedlist;

/**
 *
 * @author asmita
 */
public class LinkedListTest {
    
    public static void main (String[] args) {
        int numberOfNodes = 10;
        LinkedList list = new SinglyLinkedList();
        for (int i = 0; i < numberOfNodes/2; i++) {
            list.insertAtEnd(new Node(i));
        }
        /*
        for (int i = numberOfNodes/2; i < numberOfNodes; i++) {
            list.insertAtBeginning(i);
        }
        */
        list.print();
    }
    
}
