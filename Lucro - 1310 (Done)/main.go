package main

import (
	"fmt"
	"math"
)

func maxSubarray(arr []int) int {
	bestSum := 0
	currSum := 0
	for _, n := range arr {
		currSum = int(math.Max(0, float64(currSum)+float64(n)))
		bestSum = int(math.Max(float64(bestSum), float64(currSum)))
	}
	return bestSum
}

func main() {
	for {
		var days int
		var costPerDay int

		_, err := fmt.Scanf("%d", &days)
		if err != nil {
			break
		}

		fmt.Scanf("%d", &costPerDay)

		profitArr := []int{}
		for i := 0; i < days; i++ {
			var receipt int
			fmt.Scanf("%d", &receipt)
			profitArr = append(profitArr, receipt-costPerDay)
		}

		fmt.Println(maxSubarray(profitArr))
	}

}
