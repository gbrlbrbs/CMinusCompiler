gdc:
_t0 = v == 0 
if_true _t0 goto L0
param v
_t4 = u / v 
_t3 = _t4 * v 
_t2 = u - _t3
param _t2
_t1 = call gdc, 2
return _t1
L0:
return u 
main:
_t5 = call input, 0
x = _t5
_t6 = call input, 0
y = _t6
param x
param y
_t8 = call gdc, 2
param _t8
_t7 = call output, 1
