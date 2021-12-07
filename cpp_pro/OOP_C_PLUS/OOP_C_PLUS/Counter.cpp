#include "Counter.h"



Counter::Counter() : Counter(0, 9)
{

}

Counter::Counter(int min, int max) : Counter(min, max, 1)
{

}

Counter::Counter(int min, int max, int current) : Counter(min, max, current, 1)
{

}

Counter::Counter(int min, int max, int current, int step)
{
	SetStep(step);
	SetMin(min);
	SetMax(max);
	SetCurrent(current);
}

void Counter::SetCurrent(int current)
{
	if (current < _min)
	{
		throw "Too low value\n";
	}
	_current = current % (_max + 1);
}

void Counter::SetStep(int step)
{
	_step = step;
}

void Counter::SetMin(int min)
{
	_min = min;
}

void Counter::SetMax(int max)
{
	_max = max;
}

void Counter::SetDefault()
{
	SetStep(1);
	SetMin(0);
	SetMax(9);
	SetCurrent(0);
}

void Counter::Increment()
{
	SetCurrent(_current + 1);
}

void Counter::IncrByStep()
{
	SetCurrent(_current + _step);
}

void Counter::Reset()
{
	SetCurrent(_min);
}

int Counter::GetCurrent() const
{
	return _current;
}

void Counter::Print() const
{
	printf("%10d\n", _current);
}


