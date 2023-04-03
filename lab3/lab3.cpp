#include <iostream> 
#include <ctime> 
#include <cstdlib> 

void fill(int array[], size_t size); 
void fill(int array[], int array1[], int array2[], size_t size); 
void print_array(const int a[], size_t size); 

int main() //основная функция
{
    std::srand(std::time(nullptr)); //генерация случайных чисел по текущему времени

    const size_t size = rand() % 5 + 1; //константа, генерация случайного числа(остаток от деления на 5 и +1)

    int* array1 = new int[size]; //создание 1 массива
    int* array2 = new int[size]; //создание 2 массива
    int* array = new int[2*size]; //3 массив


    fill(array1, size); //заполнение 1 массива
    fill(array2, size); //заполнение 2 массива
    fill(array, array1, array2, size); //заполнение 3 массива

    print_array(array1, size); //вывод 1 массива
    print_array(array2, size); //вывод 2 массива
    print_array(array, 2*size); //вывод 3 массива

    delete [] array1; //удаление
    delete [] array2; //удаление
    delete [] array; //удаление

    return 0; 
}

void fill(int a[], size_t size) //функция заполнения массива случайными числами 
{
    for (size_t i = 0; i < size; ++i)
    {
        a[i] = std::rand() % 100 + 1; // генерация случайного числа массива(остаток от деления на 100 и +1)
    }
}

void fill(int array[], int array1[], int array2[], size_t size)
{
    asm
    (
        "push %[array]\n\t"                 

        "movl %[size], %%ecx\n\t" 
        "movl %[array1], %%ebx\n\t" 
        "movl %[array], %%edx\n\t"

        "loop1:\n\t"
            "movl (%%ebx), %%eax\n\t" 
            "push %%ecx\n\t"
            "movl (%%edx), %%ecx\n\t" 
            "movl %%eax, %%ecx\n\t"
            "movl %%ecx, (%[array])\n\t" 
            "popl %%ecx\n\t"

            "addl $4, %%ebx\n\t" 
            "addl $8, %%edx\n\t" 
            "decl %%ecx\n\t" 
            "cmpl $0, %%ecx\n\t"
            "jne loop1\n\t"

        "movl %[array2], %%ebx\n\t"
        "pop %%edx\n\t"
        "addl $4, %%edx\n\t"
        "movl %[size], %%ecx\n\t"

        "jmp loop2\n\t"

        "loop2:\n\t"
            "movl (%%ebx), %%eax\n\t" 
            "push %%ecx\n\t"
            "movl (%%edx), %%ecx\n\t" 
            "movl %%eax, %%ecx\n\t"
            "movl %%ecx, (%[array])\n\t" 
            "popl %%ecx\n\t"

            "addl $4, %%ebx\n\t" 
            "addl $8, %%edx\n\t" 
            "decl %%ecx\n\t" 
            "cmpl $0, %%ecx\n\t"
            "jne loop2\n\t"
        :
        :[size]"m"(size),
        [array1]"m"(array1), [array2]"m"(array2), [array]"d"(array)
        :"%ecx", "%ebx"
    );
}

void print_array(const int a[], size_t size) // функция вывода массива 
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << a[i] << ' ';
    }

    std::cout << '\n';
}
