��������� ������ ��� ������������ �������� ������ ������������ ��������� ������.

����������� ����������� ������������ ��� ������ �� ����������� STM32f405RG, ������ � ��������� ����� ���� ���������� ��� ����� ��������������� ����������.

��� ��������� ���� ��� ���� ���������� ����������:
1. ��������� ������������� ����� ����� ������ � ������� stripe_init
2. ��������� ��� �������������� ��������� ������� � ������� stripe_2_toggle
3. ��������� ������� ��������� �������� � �������� vait_stripe_2_half_period, vait_stripe_2_period, 

������ � CooCox IDE:
1. ������� ������ \software\CooCox\simple_dynamic_magnetic_stripe.coproj
2. ����������������� ������ Project -> Rebuild  (CTRL+R) 
3. ������ �������� � ���������� Flash -> Program Download

������ � Keil MDK-ARM
1. ������� ������ \software\IAR_MDK\Project\simple_dynamic_magnetic_stripe\MDK-ARM\Project.uvprojx
2. ����������������� ������ Project -> Rebuild all target files
3. ��������� ������� Debug -> Start/Stop Debug Session   (CTRL+F5)
4. ��������� ��������� Debug -> Run  (F5) 

������ � IAR Embedded Workbench
1. ������� ������ \software\IAR_MDK\Project\simple_dynamic_magnetic_stripe\EWARM\Project.eww
2. ����������������� ������ Project -> Rebuild all
3. ��������� ������� Project -> Download and debug   (CTRL+D)
4. ��������� ��������� Debug -> Go  (F5) 
