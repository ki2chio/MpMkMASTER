#include "asmroutine.h"
;Экспортируем asm_func
.global asm_func
;Реализуем функцию
asm_func:
; Параметр будет находиться в R25:R24 (адрес переменной)
; Переносим значение в указатель X
ldi R20, 0
mov R26, R24
mov R27, R25
; Загружаем значение из памяти
M2:
ld R24, X+
;Сравниваем значение
cp R20, R24
;Выбираем большее значение
brsh M1
mov R20, R24
M1:
dec R22
brne M2
mov R24, R20
ret
