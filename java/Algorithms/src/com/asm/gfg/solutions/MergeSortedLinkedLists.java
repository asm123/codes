/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.gfg.solutions;

import com.asm.algorithms.data_structures.linkedlist.LinkedList;
import com.asm.algorithms.data_structures.linkedlist.SinglyLinkedList;

/**
 *
 * @author asmita
 */
public class MergeSortedLinkedLists {
    
    public static LinkedList mergeSortedLists(LinkedList l1, LinkedList l2) {
        if (l1 == null || l1.isEmpty()) {
            return l2;
        }
        if (l2 == null || l2.isEmpty()) {
            return l1;
        }
        LinkedList merged = new SinglyLinkedList();
        
        while (!l1.isEmpty() && !l2.isEmpty()) {
            if (l1.getHead().getData() < l2.getHead().getData()) {
                merged.insertAtEnd(l1.getHead());
                l1.shiftHead();
            }
            else if (l1.getHead().getData() > l2.getHead().getData()) {
                merged.insertAtEnd(l2.getHead());
                l2.shiftHead();
            }
            else {
                merged.insertAtEnd(l1.getHead());
                l1.shiftHead();
                
                merged.insertAtEnd(l2.getHead());
                l2.shiftHead();
            }
        }
        while (!l1.isEmpty()) {
            merged.insertAtEnd(l1.getHead());
            l1.shiftHead();
        }
        while (!l2.isEmpty()) {
            merged.insertAtEnd(l2.getHead());
            l2.shiftHead();
        }
        
        return merged;
    }
    
    public static void main(String[] args) {
        LinkedList l1 = new SinglyLinkedList();
        l1.insertAtEnd(2);
        l1.insertAtEnd(3);
        l1.insertAtEnd(20);
        l1.print();
        
        LinkedList l2 = new SinglyLinkedList();
        l2.insertAtEnd(6);
        l2.insertAtEnd(21);
        l2.insertAtEnd(40);
        l2.print();
        
        LinkedList merged = mergeSortedLists(l1, l2);
        merged.print();
        l1.print();
        l2.print();
    }
    
}
