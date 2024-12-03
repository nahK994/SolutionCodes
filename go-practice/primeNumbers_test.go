package gopractice

import (
	"math"
	"reflect"
	"testing"
)

func primeGenerator(n int) []int {
	ans := []int{}
	if n >= 2 {
		ans = append(ans, 2)
	}

	var isPrime bool
	for i := 3; i <= n; i += 2 {
		isPrime = true
		for j := 3; j <= int(math.Sqrt(float64(i))); j += 2 {
			if i%j == 0 {
				isPrime = false
				break
			}
		}
		if isPrime {
			ans = append(ans, i)
		}
	}

	return ans
}

func TestPrimeGenerator(t *testing.T) {
	tests := []struct {
		name     string
		input    int
		expected []int
	}{
		{"No primes below 2", 1, []int{}},
		{"Only 2 is prime", 2, []int{2}},
		{"Primes below 10", 10, []int{2, 3, 5, 7}},
		{"Primes below 20", 20, []int{2, 3, 5, 7, 11, 13, 17, 19}},
		{"Edge case with n=0", 0, []int{}},
		{"Edge case with n=100", 100, []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}},
		{"Single odd number", 3, []int{2, 3}},
		{"Single even number", 4, []int{2, 3}},
		{"No primes below negative numbers", -10, []int{}},
	}

	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			result := primeGenerator(test.input)
			if !reflect.DeepEqual(result, test.expected) {
				t.Errorf("For input %d, expected %v but got %v", test.input, test.expected, result)
			}
		})
	}
}
