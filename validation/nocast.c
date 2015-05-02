typedef unsigned long my_time __attribute__((nocast));

static my_time f(my_time *t)
{
	my_time other = (my_time __attribute__((force))) 100;
	*t += other;
	return *t;
}

int main(void)
{
	my_time r, t = (my_time __attribute__((force))) 0;
	r = f(&t);
	return (int __attribute__((force))) r;
}

/*
 * check-name: nocast.c
 */
