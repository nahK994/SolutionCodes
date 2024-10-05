package main

import (
	"fmt"
	"sort"
)

var candidates []int
var target int
var ans [][]int

func rec(idx int, list []int, sum int) {
	if sum == target {
		temp := make([]int, len(list))
		copy(temp, list)
		ans = append(ans, temp)
		return
	} else if sum > target {
		return
	}

	for i := idx; i < len(candidates); i++ {
		if i > 0 && candidates[i] == candidates[i-1] {
			continue
		}

		rec(i+1, list, sum)
		list = append(list, candidates[i])
		rec(i+1, list, sum+candidates[i])
		list = list[:len(list)-1]
	}
}

func main() {
	candidates = []int{10, 1, 2, 7, 6, 1, 5}
	target = 8

	sort.Slice(candidates, func(i, j int) bool {
		return candidates[i] < candidates[j]
	})

	fmt.Println(candidates, target)
	rec(0, []int{}, 0)
	for _, item := range ans {
		fmt.Println(item)
	}
}
