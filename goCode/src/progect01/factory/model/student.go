package model

type student struct {
	Name  string
	score float64
}

func NewStudent(n string, s float64) *student {
	return &student{
		Name:  n,
		score: s,
	}
}

func (s *student) GetScore() float64 {
	return (*s).score //传过来的是一个指针，虽然编译器底层做了优化（s.score)
}
