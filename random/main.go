package main

import "fmt"

func longestValidParentheses(s string) int {
	stack := make([]string, 0)
	ans := 0
	count := 0
	for _, ch := range s {
		if ch == '(' {
			stack = append(stack, "(")
		} else {
			if len(stack) > 0 {
				count += 2
				stack = stack[:len(stack)-1]
			} else {
				if count > ans {
					ans = count
				}
				count = 0
			}
		}
	}
	if count > ans {
		ans = count
	}
	return ans
}

func main() {
	str := "()(()"
	fmt.Println(longestValidParentheses(str))
}
