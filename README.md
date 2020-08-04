# **Практика, лето 2020**

Студент Юзеев Р.Р. (группа ИУ6-63Б)

Руководитель Григоренко В.М.

###### _Задание:_
А. Предварительный разбор файла *.h языка С++. Требуется создать программу на С++, которая, получив на вход файл *.h, создаёт в памяти заполненную структуру, состоящую из строк и содержащую:
- список файлов #include;
- список объявленных в файле типов структур (struct): первый элемент — комментарий (см. ниже), второй элемент — собственно объявление (struct и NAME), третий элемент — все строки объявления структуры от { до };
- список объявленных в файле классов — аналогично списку объявленных структур. При этом в качестве первого элемента, содержащего структуру или класс, должны быть строки комментариев, находящиеся перед этой структурой или классом. 

Б. Последующий разбор структуры, созданной выше: парсинг третьего элемента списка объявлений структур и классов - создание внутри ранее созданной структуры в третьем элементе списков разбора секции объявления (от { до }). Результат должен содержать структуру в третьем элементе, содержащую тип объявляемой переменной, её имя (раздельно), а также комментарий, относящийся к данному объявлению и стоящий или перед объявлением, или в строке объявления.

В. Если объявлена функция (метод класса или структуры) — создание элемента, содержащего тип значения, строку самого объявления (с параметрами), а также отдельное поле со строками реализации от { до }. Не забыть о строках комментариев, относящихся к этому методу.

###### _Выполнение:_

Программа написана в среде CLion. Собирается с помощью CMakeLists.txt.

На данный момент выполнены первые 2 пункта задания.

Интерфейс:  необходимо ввести имя .h-файла, лежащего в папке проекта, либо букву t (test), чтобы выполнить парсинг уже написанного test/sample.h.

В выводе выписывается содержимое структуры `res` из `main()`. Поочередно выводятся `includes_list`, `struct_list` и `classes_list`. 


