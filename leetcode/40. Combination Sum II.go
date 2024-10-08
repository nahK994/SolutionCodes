package main

import (
	"fmt"
	"sort"
)

func rec(ans *[][]int, candidates []int, target int, idx int, list []int, sum int) {
	if sum == target {
		temp := make([]int, len(list))
		copy(temp, list)
		*ans = append(*ans, temp)
		return
	} else if sum > target || idx == len(candidates) {
		return
	}

	for i := idx; i+1 < len(candidates); i++ {
		if candidates[i] == candidates[i+1] {
			continue
		}

		rec(ans, candidates, target, i+1, list, sum)
		break
	}

	list = append(list, candidates[idx])
	rec(ans, candidates, target, idx+1, list, sum+candidates[idx])
}

func combinationSum2(candidates []int, target int) [][]int {
	sort.Slice(candidates, func(i, j int) bool {
		return candidates[i] > candidates[j]
	})
	var ans [][]int
	rec(&ans, candidates, target, 0, []int{}, 0)
	return ans
}

func main() {
	ans := combinationSum2([]int{10, 1, 2, 7, 6, 1, 5}, 8)
	for _, item := range ans {
		fmt.Println(item)
	}
}
