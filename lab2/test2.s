# формат принта
print:
  .string "%d\n" 

# массив
array:
  .byte 127, 255, 2, 3, 4, 5, 6, 7, 8, 9 //создание массива со значениями в формате байта
size: 

.text 
.global main 
.type main, @function 

# main функция
main:
  movq $0, %rcx //зачистка регистра rcx
  movq $array, %rbx //вставка массива в rbx
  movzbq (%rbx), %rax 

  jmp is_last_element 

# запускайте цикл до конца массива
start_loop:
  and $34, %rax //выполняет логическое И, 34 в rax
  cmpq $34, %rax //сравнивает 64-разрядный регистр с %rax 
  jne to_next_element 

  movzbq (%rbx), %rdx # нужно преобразовать из байтового в длинный
  addq %rdx, %rcx //складывает непосредственные данные и записывает в rcx

# переход на след элемент
to_next_element:
  addq $1, %rbx //добавляет единицу для перехо к след элементу
  movzbq (%rbx), %rax # нужно преобразовать из байтового в длинный

# сравните с последним элементом массива
is_last_element:
  cmpq $size, %rbx //сравнивает %rbx (индекс) c размером массива
  jne start_loop

  movq $print, %rdi 
  movq %rcx, %rsi 
  movq $0, %rax 
  callq printf 
  xor %rcx, %rcx 
  xor %rbx, %rbx 
  xor %rax, %rax

  ret //завершение
