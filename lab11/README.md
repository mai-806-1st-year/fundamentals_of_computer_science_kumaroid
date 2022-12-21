Отчёт по лабораторной работе №11 по курсу "Фундаментальная информатика"
Студент группы: М80-108Б-22 Иванов Андрей Кириллович, № по списку 10

Контакты e-mail: andr-ushka2@yandex.ru

Работа выполнена: «1» декабря 2022 г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой:

Отчет сдан: «2» декабря 2022 г., 

Подпись преподавателя: ________________

1. Тема
Обработка последовательности литер входного текстового файла. Простейшие приёмы лексического анализа. Диаграммы состояний переходов.

2. Цель работы
Составить программу на языке Си, выполняющую анализ и обработку вводимого текста.

3. Задание (вариант № 36**)
Выделить все восьмиричные числа от 17 до 77 по модулю и распечатать их значения в словесной форме по-испански.

4. Оборудование
Процессор: AMD Ryzen 5 5600H (12) @ 3.600GHz
ОП: 32GiB 3200 MHz LPDDR4
Текстовый редактор: Visual Studio Code версия 1.73.0

5. Программное обеспечение:
Операционная система семейства: Microsoft Windows 11 Pro
Компилятор: GNU Compiler Collection
Текстовый редактор: Visual Studio Code версия 1.73.0

6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Обработать цифру
Проверить её
Вывести в переводе на испанский язык.


7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

 #include <stdio.h> 
 #include <stdbool.h> 
 #include <ctype.h> 
  
 typedef enum 
 { 
     OUTSIDE, 
     INSIDE_0, 
     INSIDE_1, 
     INSIDE_1_1, 
     WRONG_WORD 
 } Conditions; 
  
  
 void fd_ispaniol(char fd) 
 { 
     switch (fd) 
     { 
         case '2':  
             printf("veinti");  
             return; 
         case '3':   
             printf("treinta y ");  
             return; 
         case '4': 
             printf("cuarenta y ");  
             return; 
         case '5':  
             printf("cincuenta y ");  
             return; 
         case '6':  
             printf("sesenta y ");  
             return; 
         case '7':  
             printf("setenta y ");  
             return; 
     } 
 } 
  
 void sd_ispaniol(char sd) 
 { 
     switch (sd) 
     { 
         case '1':  
             printf("uno "); 
             return; 
         case '2':  
             printf("dos ");  
             return; 
         case '3':  
             printf("tres ");  
             return; 
         case '4':  
             printf("cuatro "); 
              return; 
         case '5':  
             printf("cinco ");  
             return; 
         case '6':  
             printf("seis ");  
             return; 
         case '7':  
             printf("siete ");  
             return; 
     } 
 } 
  
 void to_ispaniol(char fd, char sd) 
 { 
     if (sd == '0') 
     { 
         switch (fd) 
         { 
             case '2':  
                 printf("veinte "); 
                 return; 
             case '3':  
                 printf("treinta "); 
                 return; 
             case '4':  
                 printf("cuarenta "); 
                 return; 
             case '5':  
                 printf("cincuenta "); 
                 return; 
             case '6':  
                 printf("sesenta "); 
                 return; 
             case '7':  
                 printf("setenta "); 
                 return; 
         } 
     }else{ 
         fd_ispaniol(fd); 
         sd_ispaniol(sd); 
     } 
 } 
  
  
 bool is_8iric(char ch) 
 { 
     return isdigit(ch) && ch != '8' && ch != '9'; 
 } 
  
 void ispanio() 
 { 
     int temp; 
     int new; 
     int k_0 = 0; 
     bool minus = false; 
     Conditions condition = OUTSIDE; 
     for (int ch = getchar(); ch != EOF; ch = getchar()) 
     { 
         switch (condition)  
         { 
             case OUTSIDE: 
                 k_0 = 0; 
                 minus = false; 
                 if (ch == '0' || ch == '-') 
                 { 
                     if (ch == '-') 
                     { 
                         minus = true; 
                     }else  
                     { 
                         k_0++; 
                     } 
                     condition = INSIDE_0; 
                     continue; 
                 } else if  (is_8iric(ch) && ch != '1') 
                 { 
                     temp = ch; 
                     condition = INSIDE_1; 
                     continue; 
                 }else if  (ch == '1') 
                 { 
                     condition = INSIDE_1_1; 
                     temp = ch; 
                     continue; 
                 }else{ 
                     putchar(ch); 
                     continue; 
                 } 
             case WRONG_WORD: 
                 k_0 = 0; 
                 minus = false; 
                 while (ch != ' ' && ch != EOF) 
                 { 
                     putchar(ch); 
                     ch = getchar(); 
                 } 
                 if (ch == EOF) 
                 { 
                     putchar(ch); 
                     break; 
                 } 
                 putchar(ch); 
                 condition = OUTSIDE; 
             case INSIDE_0: 
                 if (ch == '0') 
                 { 
                     k_0++; 
                     continue; 
                 } else if  (is_8iric(ch) && ch != '1') 
                 { 
                     temp = ch; 
                     condition = INSIDE_1; 
                     continue; 
                 }else if  (ch == '1') 
                 { 
                     condition = INSIDE_1_1; 
                     continue; 
                 }else if(ch == ' ') 
                 { 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar(ch); 
                     k_0 = 0; 
                     minus = false; 
                     condition = OUTSIDE; 
                     continue; 
                 }else 
                 { 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar(ch); 
                     condition = WRONG_WORD; 
                     continue; 
                 } 
             case INSIDE_1: 
                 if (ch == ' ')  
                 { 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar(temp); 
                     putchar(ch); 
                     condition = OUTSIDE; 
                     continue; 
                 }else if (ch == EOF) 
                 { 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar(temp); 
                     putchar(ch); 
                     break; 
                 } 
                 new = getchar(); 
                 if ((is_8iric(ch)) && (new == ' '|| new == EOF || new == '\n' || new == '\t' )) 
                 { 
                     if (minus) 
                     { 
                         printf("menos "); 
                     } 
                     to_ispaniol(temp, ch); 
                     condition = OUTSIDE; 
                     continue; 
                 }else if(is_8iric(ch)){ 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar(temp); 
                     putchar(ch); 
                     putchar(new); 
                     condition = WRONG_WORD; 
                     continue; 
                 }else { 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar(temp); 
                     putchar(ch); 
                     putchar(new); 
                     condition = WRONG_WORD; 
                     continue; 
                 } 
             case INSIDE_1_1: 
                 if (new == ' '|| new == EOF || new == '\n' || new == '\t')  
                 { 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar(ch); 
                     condition = OUTSIDE; 
                     continue; 
                 } 
                 new = getchar(); 
                 if (ch == '7' && (new == ' ' || new == EOF)) 
                 { 
                     if (minus) 
                     { 
                         printf("menos "); 
                     } 
                     printf("diecisiete "); 
                     condition = OUTSIDE; 
                     continue; 
                 }else if (new == EOF || new == '\n' || new == '\t' ){ 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar('1'); 
                     putchar(ch); 
                     putchar(new); 
                     break; 
  
                 }else if (new == ' ' ){ 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar('1'); 
                     putchar(ch); 
                     putchar(new); 
                     condition = OUTSIDE; 
                     continue; 
  
                 }else 
                 { 
                     if (minus) 
                     { 
                         putchar('-'); 
                     } 
                     for (int i = 0; i < k_0; i++){ 
                         putchar('0'); 
                     } 
                     putchar('1'); 
                     putchar(ch); 
                     putchar(new); 
                     condition = WRONG_WORD; 
                     continue; 
                 } 
         } 
  
     } 
  
 } 
  
 int main(){ 
     ispanio(); 
     return 0; 
 } 
  
  
Пункты 1-7 отчета составляются сторого до начала лабораторной работы. Допущен к выполнению работы.
Подпись преподавателя: ________________

8. Распечатка протокола
PS C:\Users\1\Documents\cc> gcc -g laba11.c -pedantic -Wall
PS C:\Users\1\Documents\cc> ./a.exe
17
diecisiete 

17 18 19 20 -22 -21 -23 -00000 -1 -7 17
diecisiete 18 19  veinte menos veintidos menos veintiuno menos veintitres -00000 -1 -7  diecisiete 
9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.
№	Лаб. или дом.	Дата	Время	Событие	Действие по исправлению	Примечание
1	дом.	20.11.22	13:00	Выполнение лабораторной работы	-	-
10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.

11. Выводы
Была написана программа на языке на Си, выполняющая анализ и обработку текста. В результате выполнения работы, были приобретены навыки для работы с текстовыми входными данными и машинами состояний.

Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента: ____________________