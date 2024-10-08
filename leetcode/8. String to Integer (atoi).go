package main

import (
	"fmt"
	"math"
	"strconv"
)

func checkOverflow(x int) int {
	fmt.Println(x, math.MinInt32, math.MaxInt32)
	if x > math.MaxInt32 {
		return math.MaxInt32
	} else if x < math.MinInt32 {
		return math.MinInt32
	}
	return x
}

func myAtoi(s string) int {
	isStarted := false
	var bt []byte
	for i := 0; i < len(s); i++ {
		ch := rune(s[i])
		if !isStarted {
			if ch == ' ' {
				continue
			}
			if ch == '-' || ch == '+' {
				isStarted = true
				if ch == '-' {
					bt = append(bt, s[i])
				}
				continue
			}
			if !(ch >= '0' && ch <= '9') {
				return 0
			} else {
				bt = append(bt, s[i])
				isStarted = true
			}
		} else {
			if !(ch >= '0' && ch <= '9') {
				break
			}
			bt = append(bt, s[i])
		}
	}

	if len(bt) == 0 {
		return 0
	} else {
		val, _ := strconv.Atoi(string(bt))
		return checkOverflow(val)
	}
}
