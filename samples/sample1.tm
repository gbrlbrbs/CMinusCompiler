* C- Compilation to TM Code
* File: sample1.tm
* Standard prelude:
  0:     LD  5,0(0) 	load gp with maxaddress
  1:    LDA  6,0(5) 	copy gp to mp
  2:     ST  0,0(0) 	clear location 0
* End of standard prelude.
* -> var. decl.
* <- var. decl.
* -> Function (minloc)
  4:     ST  1,-3(5) 	func: store the location of func. entry
* func: unconditional jump to next declaration belongs here
* func: function body starts here
  3:    LDC  1,6(0) 	func: load function location
  6:     ST  0,-1(6) 	func: store return address
* -> param
* a
* <- param
* -> param
* low
* <- param
* -> param
* high
* <- param
* -> compound
* -> assign
* -> Id (k)
  7:    LDC  0,-7(0) 	id: load varOffset
  8:    ADD  0,6,0 	id: calculate the address
  9:    LDA  0,0(0) 	load id address
* <- Id
 10:     ST  0,-8(6) 	assign: push left (address)
* -> Id (low)
 11:    LDC  0,-3(0) 	id: load varOffset
 12:    ADD  0,6,0 	id: calculate the address
 13:     LD  0,0(0) 	load id value
* <- Id
 14:     LD  1,-8(6) 	assign: load left (address)
 15:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (x)
 16:    LDC  0,-6(0) 	id: load varOffset
 17:    ADD  0,6,0 	id: calculate the address
 18:    LDA  0,0(0) 	load id address
* <- Id
 19:     ST  0,-8(6) 	assign: push left (address)
* -> Id (a)
 20:    LDC  0,-2(0) 	id: load varOffset
 21:    ADD  0,6,0 	id: load the memory address of base address of array to ac
 22:     LD  0,0,0 	id: load the base address of array to ac
 23:     ST  0,-9(6) 	id: push base address
* -> Id (low)
 24:    LDC  0,-3(0) 	id: load varOffset
 25:    ADD  0,6,0 	id: calculate the address
 26:     LD  0,0(0) 	load id value
* <- Id
 27:     LD  1,-9(6) 	id: pop base address
 28:    SUB  0,1,0 	id: calculate element address with index
 29:     LD  0,0(0) 	load id value
* <- Id
 30:     LD  1,-8(6) 	assign: load left (address)
 31:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (i)
 32:    LDC  0,-5(0) 	id: load varOffset
 33:    ADD  0,6,0 	id: calculate the address
 34:    LDA  0,0(0) 	load id address
* <- Id
 35:     ST  0,-8(6) 	assign: push left (address)
* -> Op
* -> Id (low)
 36:    LDC  0,-3(0) 	id: load varOffset
 37:    ADD  0,6,0 	id: calculate the address
 38:     LD  0,0(0) 	load id value
* <- Id
 39:     ST  0,-9(6) 	op: push left
* -> Const
 40:    LDC  0,1(0) 	load const
* <- Const
 41:     LD  1,-9(6) 	op: load left
 42:    ADD  0,1,0 	op +
* <- Op
 43:     LD  1,-8(6) 	assign: load left (address)
 44:     ST  0,0(1) 	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> Op
* -> Id (i)
 45:    LDC  0,-5(0) 	id: load varOffset
 46:    ADD  0,6,0 	id: calculate the address
 47:     LD  0,0(0) 	load id value
* <- Id
 48:     ST  0,-8(6) 	op: push left
* -> Id (high)
 49:    LDC  0,-4(0) 	id: load varOffset
 50:    ADD  0,6,0 	id: calculate the address
 51:     LD  0,0(0) 	load id value
* <- Id
 52:     LD  1,-8(6) 	op: load left
 53:    SUB  0,1,0 	op <
 54:    JLT  0,2(7) 	br if true
 55:    LDC  0,0(0) 	false case
 56:    LDA  7,1(7) 	unconditional jmp
 57:    LDC  0,1(0) 	true case
* <- Op
* while: jump to end belongs here
* -> compound
* -> if
* -> Op
* -> Id (a)
 59:    LDC  0,0(0) 	id: load varOffset
 60:    ADD  0,5,0 	id: calculate the address
 61:     ST  0,-8(6) 	id: push base address
* -> Id (i)
 62:    LDC  0,-3(0) 	id: load varOffset
 63:    ADD  0,5,0 	id: calculate the address
 64:     LD  0,0(0) 	load id value
* <- Id
 65:     LD  1,-8(6) 	id: pop base address
 66:    SUB  0,1,0 	id: calculate element address with index
 67:     LD  0,0(0) 	load id value
* <- Id
 68:     ST  0,-8(6) 	op: push left
* -> Id (x)
 69:    LDC  0,-4(0) 	id: load varOffset
 70:    ADD  0,5,0 	id: calculate the address
 71:     LD  0,0(0) 	load id value
* <- Id
 72:     LD  1,-8(6) 	op: load left
 73:    SUB  0,1,0 	op <
 74:    JLT  0,2(7) 	br if true
 75:    LDC  0,0(0) 	false case
 76:    LDA  7,1(7) 	unconditional jmp
 77:    LDC  0,1(0) 	true case
* <- Op
* if: jump to else belongs here
* -> compound
* -> assign
* -> Id (x)
 79:    LDC  0,-4(0) 	id: load varOffset
 80:    ADD  0,5,0 	id: calculate the address
 81:    LDA  0,0(0) 	load id address
* <- Id
 82:     ST  0,-8(6) 	assign: push left (address)
* -> Id (a)
 83:    LDC  0,0(0) 	id: load varOffset
 84:    ADD  0,5,0 	id: calculate the address
 85:     ST  0,-9(6) 	id: push base address
* -> Id (i)
 86:    LDC  0,-3(0) 	id: load varOffset
 87:    ADD  0,5,0 	id: calculate the address
 88:     LD  0,0(0) 	load id value
* <- Id
 89:     LD  1,-9(6) 	id: pop base address
 90:    SUB  0,1,0 	id: calculate element address with index
 91:     LD  0,0(0) 	load id value
* <- Id
 92:     LD  1,-8(6) 	assign: load left (address)
 93:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (k)
 94:    LDC  0,-5(0) 	id: load varOffset
 95:    ADD  0,5,0 	id: calculate the address
 96:    LDA  0,0(0) 	load id address
* <- Id
 97:     ST  0,-8(6) 	assign: push left (address)
* -> Id (i)
 98:    LDC  0,-3(0) 	id: load varOffset
 99:    ADD  0,5,0 	id: calculate the address
100:     LD  0,0(0) 	load id value
* <- Id
101:     LD  1,-8(6) 	assign: load left (address)
102:     ST  0,0(1) 	assign: store value
* <- assign
* <- compound
* if: jump to end belongs here
 78:    JEQ  0,25(7) 	if: jmp to else
103:    LDA  7,0(7) 	jmp to end
* <- if
* -> assign
* -> Id (i)
104:    LDC  0,-3(0) 	id: load varOffset
105:    ADD  0,5,0 	id: calculate the address
106:    LDA  0,0(0) 	load id address
* <- Id
107:     ST  0,-8(6) 	assign: push left (address)
* -> Op
* -> Id (i)
108:    LDC  0,-3(0) 	id: load varOffset
109:    ADD  0,5,0 	id: calculate the address
110:     LD  0,0(0) 	load id value
* <- Id
111:     ST  0,-9(6) 	op: push left
* -> Const
112:    LDC  0,1(0) 	load const
* <- Const
113:     LD  1,-9(6) 	op: load left
114:    ADD  0,1,0 	op +
* <- Op
115:     LD  1,-8(6) 	assign: load left (address)
116:     ST  0,0(1) 	assign: store value
* <- assign
* <- compound
117:    LDA  7,-73(7) 	while: jmp back to test
 58:    JEQ  0,59(7) 	while: jmp to end
* <- while
* -> return
* -> Id (k)
118:    LDC  0,-7(0) 	id: load varOffset
119:    ADD  0,6,0 	id: calculate the address
120:     LD  0,0(0) 	load id value
* <- Id
121:     LD  7,-1(6) 	return: to caller
* <- return
* <- compound
122:     LD  7,-1(6) 	func: load pc with return address
  5:    LDA  7,117(7) 	func: unconditional jump to next declaration
* -> Function (minloc)
* -> Function (sort)
124:     ST  1,-4(5) 	func: store the location of func. entry
* func: unconditional jump to next declaration belongs here
* func: function body starts here
123:    LDC  1,126(0) 	func: load function location
126:     ST  0,-1(6) 	func: store return address
* -> param
* a
* <- param
* -> param
* low
* <- param
* -> param
* high
* <- param
* -> compound
* -> assign
* -> Id (i)
127:    LDC  0,-5(0) 	id: load varOffset
128:    ADD  0,6,0 	id: calculate the address
129:    LDA  0,0(0) 	load id address
* <- Id
130:     ST  0,-7(6) 	assign: push left (address)
* -> Id (low)
131:    LDC  0,-3(0) 	id: load varOffset
132:    ADD  0,6,0 	id: calculate the address
133:     LD  0,0(0) 	load id value
* <- Id
134:     LD  1,-7(6) 	assign: load left (address)
135:     ST  0,0(1) 	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> Op
* -> Id (i)
136:    LDC  0,-5(0) 	id: load varOffset
137:    ADD  0,6,0 	id: calculate the address
138:     LD  0,0(0) 	load id value
* <- Id
139:     ST  0,-7(6) 	op: push left
* -> Op
* -> Id (high)
140:    LDC  0,-4(0) 	id: load varOffset
141:    ADD  0,6,0 	id: calculate the address
142:     LD  0,0(0) 	load id value
* <- Id
143:     ST  0,-8(6) 	op: push left
* -> Const
144:    LDC  0,1(0) 	load const
* <- Const
145:     LD  1,-8(6) 	op: load left
146:    SUB  0,1,0 	op -
* <- Op
147:     LD  1,-7(6) 	op: load left
148:    SUB  0,1,0 	op <
149:    JLT  0,2(7) 	br if true
150:    LDC  0,0(0) 	false case
151:    LDA  7,1(7) 	unconditional jmp
152:    LDC  0,1(0) 	true case
* <- Op
* while: jump to end belongs here
* -> compound
* -> assign
* -> Id (k)
154:    LDC  0,-4(0) 	id: load varOffset
155:    ADD  0,5,0 	id: calculate the address
156:    LDA  0,0(0) 	load id address
* <- Id
157:     ST  0,-8(6) 	assign: push left (address)
* -> Call
* -> Id (a)
158:    LDC  0,0(0) 	id: load varOffset
159:    ADD  0,5,0 	id: calculate the address
160:     LD  0,0(0) 	load id value
* <- Id
161:     ST  0,-11(6) 	call: push argument
* -> Id (i)
162:    LDC  0,-3(0) 	id: load varOffset
163:    ADD  0,5,0 	id: calculate the address
164:     LD  0,0(0) 	load id value
* <- Id
165:     ST  0,-12(6) 	call: push argument
* -> Id (high)
166:    LDC  0,-2(0) 	id: load varOffset
167:    ADD  0,5,0 	id: calculate the address
168:     LD  0,0(0) 	load id value
* <- Id
169:     ST  0,-13(6) 	call: push argument
170:     ST  6,-9(6) 	call: store current mp
171:    LDA  6,-9(6) 	call: push new frame
172:    LDA  0,1(7) 	call: save return in ac
173:     LD  7,-3(5) 	call: relative jump to function entry
174:     LD  6,0(6) 	call: pop current frame
* <- Call
175:     LD  1,-8(6) 	assign: load left (address)
176:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (t)
177:    LDC  0,-2(0) 	id: load varOffset
178:    ADD  0,6,0 	id: calculate the address
179:    LDA  0,0(0) 	load id address
* <- Id
180:     ST  0,-8(6) 	assign: push left (address)
* -> Id (a)
181:    LDC  0,0(0) 	id: load varOffset
182:    ADD  0,5,0 	id: calculate the address
183:     ST  0,-9(6) 	id: push base address
* -> Id (k)
184:    LDC  0,-4(0) 	id: load varOffset
185:    ADD  0,5,0 	id: calculate the address
186:     LD  0,0(0) 	load id value
* <- Id
187:     LD  1,-9(6) 	id: pop base address
188:    SUB  0,1,0 	id: calculate element address with index
189:     LD  0,0(0) 	load id value
* <- Id
190:     LD  1,-8(6) 	assign: load left (address)
191:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (a)
192:    LDC  0,0(0) 	id: load varOffset
193:    ADD  0,5,0 	id: calculate the address
194:     ST  0,-8(6) 	id: push base address
* -> Id (k)
195:    LDC  0,-4(0) 	id: load varOffset
196:    ADD  0,5,0 	id: calculate the address
197:     LD  0,0(0) 	load id value
* <- Id
198:     LD  1,-8(6) 	id: pop base address
199:    SUB  0,1,0 	id: calculate element address with index
200:    LDA  0,0(0) 	load id address
* <- Id
201:     ST  0,-8(6) 	assign: push left (address)
* -> Id (a)
202:    LDC  0,0(0) 	id: load varOffset
203:    ADD  0,5,0 	id: calculate the address
204:     ST  0,-9(6) 	id: push base address
* -> Id (i)
205:    LDC  0,-3(0) 	id: load varOffset
206:    ADD  0,5,0 	id: calculate the address
207:     LD  0,0(0) 	load id value
* <- Id
208:     LD  1,-9(6) 	id: pop base address
209:    SUB  0,1,0 	id: calculate element address with index
210:     LD  0,0(0) 	load id value
* <- Id
211:     LD  1,-8(6) 	assign: load left (address)
212:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (a)
213:    LDC  0,0(0) 	id: load varOffset
214:    ADD  0,5,0 	id: calculate the address
215:     ST  0,-8(6) 	id: push base address
* -> Id (i)
216:    LDC  0,-3(0) 	id: load varOffset
217:    ADD  0,5,0 	id: calculate the address
218:     LD  0,0(0) 	load id value
* <- Id
219:     LD  1,-8(6) 	id: pop base address
220:    SUB  0,1,0 	id: calculate element address with index
221:    LDA  0,0(0) 	load id address
* <- Id
222:     ST  0,-8(6) 	assign: push left (address)
* -> Id (t)
223:    LDC  0,-2(0) 	id: load varOffset
224:    ADD  0,6,0 	id: calculate the address
225:     LD  0,0(0) 	load id value
* <- Id
226:     LD  1,-8(6) 	assign: load left (address)
227:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (i)
228:    LDC  0,-3(0) 	id: load varOffset
229:    ADD  0,5,0 	id: calculate the address
230:    LDA  0,0(0) 	load id address
* <- Id
231:     ST  0,-8(6) 	assign: push left (address)
* -> Op
* -> Id (i)
232:    LDC  0,-3(0) 	id: load varOffset
233:    ADD  0,5,0 	id: calculate the address
234:     LD  0,0(0) 	load id value
* <- Id
235:     ST  0,-9(6) 	op: push left
* -> Const
236:    LDC  0,1(0) 	load const
* <- Const
237:     LD  1,-9(6) 	op: load left
238:    ADD  0,1,0 	op +
* <- Op
239:     LD  1,-8(6) 	assign: load left (address)
240:     ST  0,0(1) 	assign: store value
* <- assign
* <- compound
241:    LDA  7,-106(7) 	while: jmp back to test
153:    JEQ  0,88(7) 	while: jmp to end
* <- while
* <- compound
242:     LD  7,-1(6) 	func: load pc with return address
125:    LDA  7,117(7) 	func: unconditional jump to next declaration
* -> Function (sort)
* -> Function (main)
244:     ST  1,-5(5) 	func: store the location of func. entry
* func: unconditional jump to next declaration belongs here
* func: function body starts here
243:    LDC  1,246(0) 	func: load function location
246:     ST  0,-1(6) 	func: store return address
* -> param
* (null)
* <- param
* -> compound
* -> assign
* -> Id (i)
247:    LDC  0,-2(0) 	id: load varOffset
248:    ADD  0,6,0 	id: calculate the address
249:    LDA  0,0(0) 	load id address
* <- Id
250:     ST  0,-4(6) 	assign: push left (address)
* -> Const
251:    LDC  0,0(0) 	load const
* <- Const
252:     LD  1,-4(6) 	assign: load left (address)
253:     ST  0,0(1) 	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> Op
* -> Id (i)
254:    LDC  0,-2(0) 	id: load varOffset
255:    ADD  0,6,0 	id: calculate the address
256:     LD  0,0(0) 	load id value
* <- Id
257:     ST  0,-4(6) 	op: push left
* -> Const
258:    LDC  0,10(0) 	load const
* <- Const
259:     LD  1,-4(6) 	op: load left
260:    SUB  0,1,0 	op <
261:    JLT  0,2(7) 	br if true
262:    LDC  0,0(0) 	false case
263:    LDA  7,1(7) 	unconditional jmp
264:    LDC  0,1(0) 	true case
* <- Op
* while: jump to end belongs here
* -> compound
* -> assign
* -> Id (x)
266:    LDC  0,-2(0) 	id: load varOffset
267:    ADD  0,5,0 	id: calculate the address
268:     ST  0,-4(6) 	id: push base address
* -> Id (i)
269:    LDC  0,0(0) 	id: load varOffset
270:    ADD  0,5,0 	id: calculate the address
271:     LD  0,0(0) 	load id value
* <- Id
272:     LD  1,-4(6) 	id: pop base address
273:    SUB  0,1,0 	id: calculate element address with index
274:    LDA  0,0(0) 	load id address
* <- Id
275:     ST  0,-4(6) 	assign: push left (address)
* -> Call
276:     IN  0,0,0 	read integer value
* <- Call
277:     LD  1,-4(6) 	assign: load left (address)
278:     ST  0,0(1) 	assign: store value
* <- assign
* -> assign
* -> Id (i)
279:    LDC  0,0(0) 	id: load varOffset
280:    ADD  0,5,0 	id: calculate the address
281:    LDA  0,0(0) 	load id address
* <- Id
282:     ST  0,-4(6) 	assign: push left (address)
* -> Op
* -> Id (i)
283:    LDC  0,0(0) 	id: load varOffset
284:    ADD  0,5,0 	id: calculate the address
285:     LD  0,0(0) 	load id value
* <- Id
286:     ST  0,-5(6) 	op: push left
* -> Const
287:    LDC  0,1(0) 	load const
* <- Const
288:     LD  1,-5(6) 	op: load left
289:    ADD  0,1,0 	op +
* <- Op
290:     LD  1,-4(6) 	assign: load left (address)
291:     ST  0,0(1) 	assign: store value
* <- assign
* <- compound
292:    LDA  7,-39(7) 	while: jmp back to test
265:    JEQ  0,27(7) 	while: jmp to end
* <- while
* -> Call
* -> Id (x)
293:    LDC  0,-2(0) 	id: load varOffset
294:    ADD  0,5,0 	id: calculate the address
295:     LD  0,0(0) 	load id value
* <- Id
296:     ST  0,-6(6) 	call: push argument
* -> Const
297:    LDC  0,0(0) 	load const
* <- Const
298:     ST  0,-7(6) 	call: push argument
* -> Const
299:    LDC  0,10(0) 	load const
* <- Const
300:     ST  0,-8(6) 	call: push argument
301:     ST  6,-4(6) 	call: store current mp
302:    LDA  6,-4(6) 	call: push new frame
303:    LDA  0,1(7) 	call: save return in ac
304:     LD  7,-4(5) 	call: relative jump to function entry
305:     LD  6,0(6) 	call: pop current frame
* <- Call
* -> assign
* -> Id (i)
306:    LDC  0,-2(0) 	id: load varOffset
307:    ADD  0,6,0 	id: calculate the address
308:    LDA  0,0(0) 	load id address
* <- Id
309:     ST  0,-4(6) 	assign: push left (address)
* -> Const
310:    LDC  0,0(0) 	load const
* <- Const
311:     LD  1,-4(6) 	assign: load left (address)
312:     ST  0,0(1) 	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> Op
* -> Id (i)
313:    LDC  0,-2(0) 	id: load varOffset
314:    ADD  0,6,0 	id: calculate the address
315:     LD  0,0(0) 	load id value
* <- Id
316:     ST  0,-4(6) 	op: push left
* -> Const
317:    LDC  0,10(0) 	load const
* <- Const
318:     LD  1,-4(6) 	op: load left
319:    SUB  0,1,0 	op <
320:    JLT  0,2(7) 	br if true
321:    LDC  0,0(0) 	false case
322:    LDA  7,1(7) 	unconditional jmp
323:    LDC  0,1(0) 	true case
* <- Op
* while: jump to end belongs here
* -> compound
* -> Call
* -> Id (x)
325:    LDC  0,-2(0) 	id: load varOffset
326:    ADD  0,5,0 	id: calculate the address
327:     ST  0,-4(6) 	id: push base address
* -> Id (i)
328:    LDC  0,0(0) 	id: load varOffset
329:    ADD  0,5,0 	id: calculate the address
330:     LD  0,0(0) 	load id value
* <- Id
331:     LD  1,-4(6) 	id: pop base address
332:    SUB  0,1,0 	id: calculate element address with index
333:     LD  0,0(0) 	load id value
* <- Id
334:     ST  0,-6(6) 	call: push argument
335:     LD  0,-6(6) 	load arg to ac
336:    OUT  0,0,0 	write ac
* <- Call
* -> assign
* -> Id (i)
337:    LDC  0,0(0) 	id: load varOffset
338:    ADD  0,5,0 	id: calculate the address
339:    LDA  0,0(0) 	load id address
* <- Id
340:     ST  0,-4(6) 	assign: push left (address)
* -> Op
* -> Id (i)
341:    LDC  0,0(0) 	id: load varOffset
342:    ADD  0,5,0 	id: calculate the address
343:     LD  0,0(0) 	load id value
* <- Id
344:     ST  0,-5(6) 	op: push left
* -> Const
345:    LDC  0,1(0) 	load const
* <- Const
346:     LD  1,-5(6) 	op: load left
347:    ADD  0,1,0 	op +
* <- Op
348:     LD  1,-4(6) 	assign: load left (address)
349:     ST  0,0(1) 	assign: store value
* <- assign
* <- compound
350:    LDA  7,-38(7) 	while: jmp back to test
324:    JEQ  0,26(7) 	while: jmp to end
* <- while
* <- compound
351:     LD  7,-1(6) 	func: load pc with return address
245:    LDA  7,106(7) 	func: unconditional jump to next declaration
* -> Function (main)
352:    LDC  0,-4(0) 	init: load globalOffset
353:    ADD  6,6,0 	init: initialize mp with globalOffset
* -> Call
354:     ST  6,0(6) 	call: store current mp
355:    LDA  6,0(6) 	call: push new frame
356:    LDA  0,1(7) 	call: save return in ac
357:    LDC  7,246(0) 	call: unconditional jump to main() entry
358:     LD  6,0(6) 	call: pop current frame
* <- Call
* End of execution.
359:   HALT  0,0,0 	
