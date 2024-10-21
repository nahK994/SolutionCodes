/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func swap(a *ListNode, b *ListNode) {
	a.Val = a.Val + b.Val
	b.Val = a.Val - b.Val
	a.Val = a.Val - b.Val
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	prev := make(map[*ListNode]*ListNode)
	h := head
	len := 1
	for h.Next != nil {
		prev[h.Next] = h
		h = h.Next
		len++
	}

	h = head
	t := head
	tail := head
	counter := 0
	for counter == 0 || (len-counter) >= k {
		for i := 1; i < k; i++ {
			t = t.Next
		}
		counter += k
		tail = t

		for i := (k / 2); i >= 1; i-- {
			swap(h, t)
			h = h.Next
			t = prev[t]
		}

		h = tail.Next
		t = h
	}

	return head
}

// Helper function to create a linked list from a slice
func createLinkedList(values []int) *ListNode {
	if len(values) == 0 {
		return nil
	}
	head := &ListNode{Val: values[0]}
	current := head
	for _, val := range values[1:] {
		current.Next = &ListNode{Val: val}
		current = current.Next
	}
	return head
}

// Helper function to print the linked list
func printLinkedList(head *ListNode) {
	current := head
	for current != nil {
		fmt.Printf("%d ", current.Val)
		current = current.Next
	}
	fmt.Println()
}

func main() {
	// Create a linked list [1, 2, 3, 4, 5]
	head := createLinkedList([]int{1, 2, 3, 4, 5, 6})
	fmt.Println("Original list:")
	printLinkedList(head)

	// Set k (number of nodes to reverse at a time)
	k := 1

	// Reverse the linked list in groups of k
	head = reverseKGroup(head, k)
	fmt.Printf("\nReversed list in groups of %d:\n", k)
	printLinkedList(head)
}
