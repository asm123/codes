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
public class BinaryTreeConstructor {
    private int[] preorder;
    private int[] postorder;
    private int[] inorder;
    
    static int preIndex = 0;
    static int postIndex;

    public int[] getPreorder() {
        return preorder;
    }

    public void setPreorder(int[] preorder) {
        this.preorder = preorder;
    }

    public int[] getPostorder() {
        return postorder;
    }

    public void setPostorder(int[] postorder) {
        this.postorder = postorder;
        postIndex = postorder.length-1;
    }

    public int[] getInorder() {
        return inorder;
    }

    public void setInorder(int[] inorder) {
        this.inorder = inorder;
    }
    
    private int getInorderIndex(int data, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == data) {
                return i;
            }
        }
        return -1;
    }
    
    public Node constructFromPreorder(int inStartIndex, int inEndIndex) {
        Node node;
        int inorderIndex;
        if (preIndex >= preorder.length || inStartIndex > inEndIndex) {
            return null;
        }
        node = new Node(preorder[preIndex++]);
        
        if (inStartIndex == inEndIndex) {
            return node;
        }
        
        inorderIndex = getInorderIndex(node.getData(), inStartIndex, inEndIndex);
        
        node.setLeft(constructFromPreorder(inStartIndex, inorderIndex-1));
        node.setRight(constructFromPreorder(inorderIndex+1, inEndIndex));
        
        return node;
    }
    
    public Node constructFromPostorder(int inStartIndex, int inEndIndex) {
        Node node;
        int inorderIndex;
        if (postIndex < 0 || inStartIndex > inEndIndex) {
            return null;
        }
        node = new Node(postorder[postIndex--]);
        if (inStartIndex == inEndIndex) {
            return node;
        }
        
        inorderIndex = getInorderIndex(node.getData(), inStartIndex, inEndIndex);
        
        node.setRight(constructFromPostorder(inorderIndex+1, inEndIndex));
        node.setLeft(constructFromPostorder(inStartIndex, inorderIndex-1));
        
        return node;
    }
    
    public static void main(String[] args) {
        Node root;
        BinaryTree tree;
        
        int[] preorder = {1, 2, 4, 5, 3, 6, 7};
        int[] inroder = {4, 2, 5, 1, 6, 3, 7};
        int[] postorder = {4, 5, 2, 6, 7, 3, 1};
        
        BinaryTreeConstructor constructor = new BinaryTreeConstructor();
        constructor.setInorder(inroder);
        constructor.setPreorder(preorder);
        constructor.setPostorder(postorder);
        
        root = constructor.constructFromPostorder(0, inroder.length-1);
        
        tree = new BinaryTree();
        tree.setRoot(root);
        tree.recursiveInorder();
    }
}
