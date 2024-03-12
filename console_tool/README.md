Пример вызова написан в create_tool.sh (для компиляции на системе нужно после cmake вызвать make imgen)

Данная утилита служит для преобразования набора картинок по образцам. Где образцы - это объекты тип PrinterStack выполняющие подряд несколько искажений.

Вызов происходит из консоли со следующими параметрами :

1. Папка с картинками, которые должны быть преобразованы

2. Название папки или путь куда будут записаны все картинки после преобразования (она создает папку)

3. Файл с описанием операций и их названиями, должен быть составлен в соответствии со следующими правилами :

- Можно писать коментарии начинающиеся с / (я делал с // потому что так лучше видно)

- Описания применимых искажений в рамках одной операции выглядят следующим образом(назначения аргументов было описано на главной в разделе про интерфейсы) : 
    + Line - r_x, r_y, density, black, intensivity, start, end, horizontal, use_memory
    + Blob - r_x, r_y, density, black, intensivity, point_x, point_y, radius_a, radius_b, use_memory
    + Sin - r_x, r_y, density, black, intensivity, start, shift, amplitude, period, horizontal ,use_memory
    + [Пример](config.cf)

- Перед каждым отдельным описанием операции должно быть его название, а после пустая строка

- В конце файла должно быть 2 пустые строки

[Пример вызова](../create_tool.sh)