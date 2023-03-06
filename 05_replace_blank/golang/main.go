package main

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param s string字符串
 * @return string字符串
 */
func ReplaceSpace(s string) string {
	// write code here
	length := len(s)
	for _, c := range s {
		if c == ' ' {
			length += 2
		}
	}

	target := make([]rune, length)
	tmp := []rune(s)
	j := 0
	for i := 0; i < len(s); i++ {
		if tmp[i] == ' ' {
			copy(target[j:j+3], []rune{'%', '2', '0'})
			j += 3
			continue
		}

		target[j] = tmp[i]
		j++
	}

	return string(target)
}
