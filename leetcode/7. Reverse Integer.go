package random

import (
	"fmt"
	"math"
	"strconv"
)

func checkOverflow(x int) int {
	if x > math.MaxInt32 || x < math.MinInt32 {
		return 0
	}
	return x
}

func reverse(x int) int {
	if checkOverflow(x) == 0 {
		return 0
	}
	str := strconv.Itoa(x)
	var rev []byte
	for i := len(str) - 1; i >= 0; i-- {
		rev = append(rev, str[i])
	}

	if x < 0 {
		val, _ := strconv.Atoi(string(rev[:len(rev)-1]))
		return checkOverflow(-1 * val)
	} else {
		val, _ := strconv.Atoi(string(rev))
		return checkOverflow(val)
	}
}

func main() {
	fmt.Println(reverse(-43))
	fmt.Println(reverse(123))
	fmt.Println(reverse(1534236469))
}
