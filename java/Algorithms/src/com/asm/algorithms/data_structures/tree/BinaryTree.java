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
public class BinaryTree {
    Node root;

    public Node getRoot() {
        return root;
    }

    public void setRoot(Node root) {
        this.root = root;
    }
    
    private void recursiveInorder(Node node) {
        if (node == null) {
            return;
        }
        recursiveInorder(node.getLeft());
        
        System.out.print(node.getData() + " ");
        
        recursiveInorder(node.getRight());
    }
    
    public void recursiveInorder() {
        recursiveInorder(root);
    }
    
    private void recursivePreorder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.getData() + " ");
        
        recursivePreorder(node.getLeft());
        
        recursivePreorder(node.getRight());
    }
    
    public void recursivePreorder() {
        recursivePreorder(root);
    }
    
    private void recursivePostorder(Node node) {
        if (node == null) {
            return;
        }
        recursivePostorder(node.getLeft());
        
        recursivePostorder(node.getRight());
        
        System.out.print(node.getData() + " ");
    }
    
    public void recursivePostorder() {
        recursivePostorder(root);
    }
    
    private int size(Node node) {
        if (node == null) {
            return 0;
        }
        return 1 + size(node.getLeft()) + size(node.getRight());
    }
    
    public int size() {
        return size(root);
    }
    
    
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        
        tree.setRoot(new Node(1));
        tree.getRoot().setLeft(new Node(2));
        tree.getRoot().setRight(new Node(3));
        tree.getRoot().getLeft().setLeft(new Node(4));
        tree.getRoot().getLeft().setRight(new Node(5));
        
        System.out.println("Size: " + tree.size());
        tree.recursiveInorder();
    }
}
