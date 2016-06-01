/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.algorithms.datastructures.linkedlist;

/**
 *
 * @author asmita
 */
public class Node {
    private int data;
    private Node next = null;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
    
    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }
    
    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}