minloc:
k = low
_t0 = low * 4
_t1 = a[_t0]x = _t1
_t2 = low + 1 
i = _t2
L0:
_t3 = i < high 
if_true !_t3 goto L1
_t5 = i * 4
_t6 = a[_t5]_t4 = _t6 < x 
if_true _t4 goto L2
L2:
_t7 = i * 4
_t8 = a[_t7]x = _t8
k = i
L3:
_t9 = i + 1 
i = _t9
goto L0
L1:
return k 
sort:
i = low
L4:
_t11 = high - 1 
_t10 = i < _t11
if_true !_t10 goto L5
param a
param i
param high
_t12 = call minloc, 3
k = _t12
_t13 = k * 4
_t14 = a[_t13]t = _t14
_t15 = i * 4
_t16 = a[_t15]a = _t16
a = t
_t17 = i + 1 
i = _t17
goto L4
L5:
main:
i = 0
L6:
_t18 = i < 10 
if_true !_t18 goto L7
_t19 = call input, 0
x = _t19
_t20 = i + 1 
i = _t20
goto L6
L7:
param x
param 0
param 10
_t21 = call sort, 3
i = 0
L8:
_t22 = i < 10 
if_true !_t22 goto L9
_t23 = call output, 1
_t24 = i + 1 
i = _t24
goto L8
L9:
