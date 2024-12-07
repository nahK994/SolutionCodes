package gopractice

import (
	"strconv"
	"testing"
)

func frequencyCounter(s string) string {
	if len(s) == 0 {
		return ""
	}

	ans := []byte{}
	counter := 1
	for i := 1; i < len(s); i++ {
		if s[i] != s[i-1] {
			ans = append(ans, s[i-1])
			counterBytes := []byte(strconv.Itoa(counter))
			ans = append(ans, counterBytes...)
			counter = 1
			continue
		}
		counter++
	}

	ans = append(ans, s[len(s)-1])
	counterBytes := []byte(strconv.Itoa(counter))
	ans = append(ans, counterBytes...)
	return string(ans)
}

func TestFrequencyCounter(t *testing.T) {
	tests := []struct {
		input    string
		expected string
	}{
		{"aabbbcccc", "a2b3c4"},     // case where multiple characters repeat
		{"abc", "a1b1c1"},           // case where all characters are unique
		{"aaabbb", "a3b3"},          // case where two groups of repeated characters
		{"", ""},                    // empty string case
		{"aaa", "a3"},               // case with a single character repeated
		{"zzzzzzzzzzzzzzzz", "z16"}, // case with one repeated character
		{"aabbcc", "a2b2c2"},        // case with equal frequency of different characters
	}

	for _, tt := range tests {
		t.Run(tt.input, func(t *testing.T) {
			got := frequencyCounter(tt.input)
			if got != tt.expected {
				t.Errorf("frequencyCounter(%q) = %q; want %q", tt.input, got, tt.expected)
			}
		})
	}
}
