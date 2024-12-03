package gopractice

import "testing"

// Function to check if a string is a palindrome
func isPalindrome(s string) bool {
	i := 0
	j := len(s) - 1

	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}

// Test cases for isPalindrome function
func TestIsPalindrome(t *testing.T) {
	tests := []struct {
		input    string
		expected bool
	}{
		{"12321", true},  // Palindrome
		{"hello", false}, // Not a palindrome
		{"", true},       // Empty string is considered a palindrome
		{"a", true},      // Single character is a palindrome
		{"abba", true},   // Even-length palindrome
		{"abcba", true},  // Odd-length palindrome
	}

	for _, test := range tests {
		result := isPalindrome(test.input)
		if result != test.expected {
			t.Errorf("isPalindrome(%q) = %v; want %v", test.input, result, test.expected)
		}
	}
}
