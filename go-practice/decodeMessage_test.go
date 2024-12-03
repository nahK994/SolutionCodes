package gopractice

import (
	"testing"
)

func decode(s string) string {
	str := []byte(s)
	for i := 0; i < len(str); i++ {
		if str[i] >= 'A' && str[i] <= 'Z' {
			str[i] = 'A' + 'Z' - str[i]
		} else if str[i] >= 'a' && str[i] <= 'z' {
			str[i] = 'a' + 'z' - str[i]
		}
	}
	return string(str)
}

func TestDecode(t *testing.T) {
	tests := []struct {
		input    string
		expected string
	}{
		{"abc", "zyx"},                   // Lowercase letters
		{"ABC", "ZYX"},                   // Uppercase letters
		{"aBcDeFg", "zYxWvUt"},           // Mixed case letters
		{"", ""},                         // Empty string
		{"123", "123"},                   // Non-alphabetic characters (should not change)
		{"Hello World!", "Svool Dliow!"}, // Special characters and spaces should remain unchanged
	}

	for _, test := range tests {
		t.Run(test.input, func(t *testing.T) {
			result := decode(test.input)
			if result != test.expected {
				t.Errorf("For input '%s', expected '%s', but got '%s'", test.input, test.expected, result)
			}
		})
	}
}
