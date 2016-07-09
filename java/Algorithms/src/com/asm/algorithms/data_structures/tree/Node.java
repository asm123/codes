/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.data_structures.tree;

/**
 *
 * @author asmita
 */
public class Node {
    private int data;
    private Node left;
    private Node right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public Node getLeft() {
        return left;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public Node getRight() {
        return right;
    }

    public void setRight(Node right) {
        this.right = right;
    }
    
    
}
