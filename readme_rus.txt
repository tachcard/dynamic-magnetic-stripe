Программа служит для демонстрации эмуляции работы динамической магнитной полосы.

Программное обеспечение адаптировано для работы на контроллере STM32f405RG, однако с легкостью может быть переделано пол любой программируемый контроллер.

для адаптации кода под свой контроллер необходимо:
1. Исправить инициализацию порта ввода вывода в функции stripe_init
2. Исправить код инвертирования состояния выводов в функции stripe_2_toggle
3. Исправить функции временной задержки в функциях vait_stripe_2_half_period, vait_stripe_2_period, 

запуск в CooCox IDE:
1. Открыть проект \software\CooCox\simple_dynamic_magnetic_stripe.coproj
2. Перекомпилировать проект Project -> Rebuild  (CTRL+R) 
3. Запись прошивки в контроллер Flash -> Program Download

Запуск в Keil MDK-ARM
1. Открыть проект \software\IAR_MDK\Project\simple_dynamic_magnetic_stripe\MDK-ARM\Project.uvprojx
2. Перекомпилировать проект Project -> Rebuild all target files
3. Запускаем отладку Debug -> Start/Stop Debug Session   (CTRL+F5)
4. Запускаем программу Debug -> Run  (F5) 

Запуск в IAR Embedded Workbench
1. Открыть проект \software\IAR_MDK\Project\simple_dynamic_magnetic_stripe\EWARM\Project.eww
2. Перекомпилировать проект Project -> Rebuild all
3. Запускаем отладку Project -> Download and debug   (CTRL+D)
4. Запускаем программу Debug -> Go  (F5) 
