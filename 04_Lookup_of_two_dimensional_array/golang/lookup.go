package main

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * @param target int整型
 * @param array int整型二维数组
 * @return bool布尔型
 */
func Find(target int, array [][]int) bool {
	// write code here
	high := len(array)
	length := len(array[0])

	for i := 0; i < high; i++ {
		for j := length - 1; j >= 0; j-- {
			// 过滤一列
			if array[i][j] < target {
				break
			}

			if array[i][j] == target {
				return true
			}
		}
	}

	return false
}

func main() {

}
