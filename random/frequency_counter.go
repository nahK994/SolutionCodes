package main

import (
	"fmt"
	"strconv"
)

func frequency_counter(str string) string {
	var ans string
	counter := 1

	for i := 0; i < len(str); i += counter {
		ans += string(str[i])
		counter = 1
		for j := i + 1; j < len(str); j++ {
			if str[j] != str[j-1] {
				break
			}
			counter++
		}
		ans += strconv.Itoa(counter)
	}

	return ans
}

func main1() {
	str := "aaabbeeeeettX"
	fmt.Println(str, "-->", frequency_counter(str))
}
