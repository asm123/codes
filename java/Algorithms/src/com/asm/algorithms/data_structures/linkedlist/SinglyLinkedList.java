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
public class SinglyLinkedList extends LinkedList {

    @Override
    public void insertAtEnd(int data) {
        if (this.head == null) {
            this.head = new Node(data);
        }
        else {
            Node newNode = new Node(data);
            Node current = head;
            while (current.getNext() != null) {
                current = current.getNext();
            }
            current.setNext(newNode);
        }
        length++;
    }

    @Override
    public void insertAtBeginning(int data) {
        if (this.head == null) {
            this.head = new Node(data);
        }
        else {
            Node newNode = new Node(data, head);
            head = newNode;
        }
        length++;
    }

    @Override
    public void insertAtPosition(int data, int position) {
        if (length + 1 < position) {
            System.out.println("Cannot insert at position " + position + ", length of the list is " + length);
            return;
        }
        int currentPosition = 0;
        Node currentNode = head, previousNode = null;
        
    }
    
    @Override
    public void quickSort() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mergeSort() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
