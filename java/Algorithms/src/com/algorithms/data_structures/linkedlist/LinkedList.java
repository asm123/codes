/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.algorithms.data_structures.linkedlist;

/**
 *
 * @author asmita
 */
public abstract class LinkedList {
    protected Node head;
    protected int length = 0;

    public Node getHead() {
        return head;
    }

    public void setHead(Node head) {
        this.head = head;
    }
    
    public abstract void insertAtEnd(int data);
    public abstract void insertAtBeginning(int data);
    
    /**
     * 
     * @param data
     * @param position 0-based position
     */
    public abstract void insertAtPosition(int data, int position);
    
    public void print() {
        Node currentNode = head;
        while (currentNode != null) {
            System.out.print(currentNode.getData() + " ");
            currentNode = currentNode.getNext();
        }
        System.out.println("");
    }
    
    public abstract void quickSort();
    public abstract void mergeSort();
}
