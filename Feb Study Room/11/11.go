package main

type Stack struct {
	items []rune
}

func (s *Stack) Push(data rune) {
	s.items = append(s.items, data)
}

func (s *Stack) Pop() {
	if len(s.items) > 0 {
		s.items = s.items[:len(s.items)-1]
	}
}

func (s *Stack) Top(n int) string {
	if len(s.items) >= n {
		return string(s.items[len(s.items)-n:])
	}
	return ""
}

func removeOccurrences(s string, part string) string {
	stack := Stack{}
	partLen := len(part)

	for _, char := range s {
		stack.Push(char)
		if stack.Top(partLen) == part {
			for i := 0; i < partLen; i++ {
				stack.Pop()
			}
		}
	}

	return string(stack.items)
}
