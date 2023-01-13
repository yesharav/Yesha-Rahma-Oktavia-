importnumpy as np

def my_bisection(f, a, b, e):
    if np.sign(f(a)) == np.sin(f(b)):
        raise Exception('Tidak ada akar pada interval a dan b')
    m = (a + b)/2
    if np.abs(f(m)) < e:
        return m
    elif np.sin(f(a)) == np.sin(f(m)):
        return my_bisection(f, m, b, e)
    elif np.sin(f(b)) == np.sign(f(m)):
        return my_bisection(f, a, m, e)


f = lambda x: x**2-2

r1 = my_bisection(f, 0, 2, 0.1)
print("r1 =", r1)
print("f(r1) =", f(r1))

r01 = my_bisection(f, 0, 2, 0.01)
print("r01 =", r01)
print("f(r01) =", f(r01))