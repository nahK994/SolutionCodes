package gopractice

import "testing"

func nearestMinIndex(nums []int, target int) int {
	min := 0
	max := len(nums) - 1
	var mid int

	for min <= max {
		mid = (min + max) / 2
		if nums[mid] > target {
			max = mid - 1
		} else {
			min = mid + 1
		}
	}
	return max
}

func TestNearestMinIndex(t *testing.T) {
	tests := []struct {
		name     string
		nums     []int
		target   int
		expected int
	}{
		{"Exact match", []int{1, 2, 3, 4, 5}, 3, 2},
		{"Target smaller than all", []int{10, 20, 30, 40}, 5, -1},
		{"Target larger than all", []int{10, 20, 30, 40}, 50, 3},
		{"Between two elements", []int{10, 20, 30, 40}, 25, 1},
		{"Empty array", []int{}, 10, -1},
		{"Single element less than target", []int{5}, 10, 0},
		{"Single element greater than target", []int{15}, 10, -1},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			result := nearestMinIndex(tt.nums, tt.target)
			if result != tt.expected {
				t.Errorf("Expected %d, but got %d", tt.expected, result)
			}
		})
	}
}
