/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode OddEvenList(ListNode head) {
        if (head == null) return head;
        ListNode current = head; 
        ListNode final = new ListNode(head.val, null);
        ListNode auxFinal = final;
        
        for (int i = 0; current != null; current = current.next, i++) 
        {
            if (i % 2 == 0 && i != 0) {
                auxFinal.next = new ListNode(current.val, null);
                auxFinal = auxFinal.next;
            }
        }
        current = head;
        
        for (int i = 0; current != null; current = current.next, i++) 
        {
            if (i % 2 != 0 && i != 0) {
                auxFinal.next = new ListNode(current.val, null);
                auxFinal = auxFinal.next;
            }
        }
        
        return final;
    }
}