# Database-tool

Инструмент для работы с базой данных

Qt Creator - фреймворк для разработки кроссплатформенного программного обеспечения на языке программирования C++

Для работы с базами данных библиотека Qt предоставляет отдельный модуль QSql

Классы модуля QSql разделяются на уровни: 
1. Уровень драйверов (получение данных на физиеском уровне)
2. Ррограммный уровень (предоставление программного интерфейса для обращения к базе данных) 
3. Уровень пользовательского интерфейса (предоставление моделей для отображение результатов запросов в представлениях интервью)

Qt любезно предоставляет ряд других классов, отвечающих за элементы управления, а также возможность применения к ним адаптированных стилей CSS (QSS)

### 1. Логика

Запуск программы, открытие базы данных, проверка на существование (завершение работы программы в случае ошибки открытия БД)

Главное окно содержит блоки выбора и отображения таблиц, а также кнопки для выполнения какой-либо инструкции

Инструкции для кнопок:
1. Выбор заранее сохранённого SQL-запроса для отображения. Форма содержит блок выбора с названиями запросов, в лог сохраняется текст SQL-запроса
2. Работа с записями: добавление, удаление и изменение
3. Информация о разработчике: ФИО, GitHub и почта

Работа с записями включает в себя следующее:
1. Добавление. Открытие новой формы, ввод информации, проверка вводимой информации и выполнение SQL-запроса на добавление. Ошибки и предупреждения сохраняются в лог
2. Изменение. Информирование пользователя, что ячейки таблицы главного окна установлены в режим редактирования. Лог отсутствует
3. Удаление. Открытие новой формы, загрузка вспомогательной информации, необходимой для идентификации записи под удаление. Также происходит удаление зависимых записей. Ошибки и предупреждения сохраняются в лог

**Добавление.** Отдельная форма для каждой таблицы. Механизм сигналов и слотов, передача форме и последующая работа с указателем на модель БД:
1. Проверка на существование записи с вводимыми ключевыми полями. В случае ошибки увеличение счётчика ошибок, сохранение отладочного сообщения в лог, содержащее текст запроса
2. Проверка на корректность вводимых данных. В случае отсутствия ошибок происходит снятие блокировки с кнопки добавления, далее пункт 1
3. Выполнение SQL-запроса на добавление записи. Пункты 1 и 2 гарантируют отсутствие ошибок

**Изменение.** Изначально предполагалась следующая реализация: отдельная форма для каждой таблицы, передача указателя на модель БД посредством механизма сигналов и слотов и последующая работа с ним. Решение отвергнуто ввиду сложности реализации и скорых сроков для сдачи лабораторной работы. А потому ячейки таблицы в главном окне установлены в режим "Чтение и редактирование", позволяющий пользователю изменять собержимое записей

**Удаление.** Отдельная форма для каждой таблицы. Механизм сигналов и слотов, передача форме и последующая работа с указателем на модель БД:
1. Проверка на существование записи для отдельных форм. В случае ошибки увеличение счётчика ошибок и сохранение отладочного сообщения в лог
2. Проверка на корректность вводимых данных. В случае отсутствия ошибок происходит снятие блокировки с кнопки удаления, далее пункт 1, но для отдельных форм
3. Выполнение SQL-запроса на удаление записи. Пункты 1 и 2 гарантируют отсутствие ошибок

### Написание программы

Активно использовась документация фреймворка Qt Creator для версии 5.10, книга Макса шлее "Qt 5.10. Профессиональное программирование на языке С++" а также форумы в Сети

**Проблемы и решение**. В процессе написания программы возникали проблемы, тормозившие процесс разработки. Наибольший вклад в задержку внесли следующие:
1. Драйвер для БД. Отсутствие драйвера для 64-бит версии СУБД на моём ПК, а потому в век научно-технического прогресса пришлось прибегнуть к использованию компилятора MinGW 32-бит вместо MinGW 64-бит
2. Некорректное отображение даты и времени в ячейках таблицы "Занятие", вследствие чего пришлось устанавливать соответствующие делегаты
3. Поздний приход здравой мысли "Использовать механизм сигналов и слотов для передачи не частей модели БД, а её целиком + модели для запросов"
4. Прочие незначительные проблемы. К примеру, отсутствие модуля для отображения изображений, вследствие чего пришлось устанавливать стили для текстовых модулей

Неоценимый вклад в написание программы внесли библиотека `QDebug` и функция `qDebug()`, с помощью которых в лог активно выводилась некоторая отладочная информация. Респект таким пацанам)

### Развёртывание приложения, исходные коды

**Проблемы и решение.** В процессе развёртывания программы столкнулся с некорректной работы программы `windeployqt.exe`, подготавливающей необходимые библиотеки, вследствие чего недостающие файлы пришлось добавлять вручную. Операционная система Windows 10 32/64 бит

### Лицензия

Это программа является свободным программным обеспечением. Вы можете распространять и/или модифицировать её согласно условиям  Стандартной Общественной Лицензии GNU

Эта программа распространяется в надежде, что она будет полезной, но без всяких гарантий, в том числе подразумеваемых гарантий товарного состояния при продаже и годности для определённого применения

![image](https://user-images.githubusercontent.com/78896451/145692245-abaf1067-d3fb-418d-801a-28870ec526ef.png)

### ©️ Konsilerinos
