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
public class DoublyLinkedListNode extends Node {
    private Node previous;

    public DoublyLinkedListNode(int data) {
        super(data);
    }

    public Node getPrevious() {
        return previous;
    }

    public void setPrevious(Node previous) {
        this.previous = previous;
    }
}
