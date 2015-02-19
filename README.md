The program serves to demonstrate the emulation of dynamic magnetic strip.
Software adapted to run on the controller STM32f405RG, but can easily be converted floor of any programmable controller.

to adapt the code for your controller must:
1. Correct the initialization GPIO function stripe_init
2. Correct the code inverting output state function stripe_2_toggle
3. Correct function of time delay in the functions vait_stripe_2_half_period, vait_stripe_2_period,

launch CooCox IDE:
1. Open the project: \software\CooCox\simple_dynamic_magnetic_stripe.coproj
2. Recompile the project: Project -> Rebuild (CTRL + R)
3. Record the controller firmware: Flash -> Program Download

Running in Keil MDK-ARM
1. Open the project: \software\IAR_MDK\Project\simple_dynamic_magnetic_stripe\MDK-ARM\Project.uvprojx
2. Recompile the project: Project -> Rebuild all target files
3. Run the debugging: Debug -> Start/Stop Debug Session (CTRL + F5)
4. Run the program: Debug -> Run (F5)

Running in IAR Embedded Workbench
1. Open the project: \software\IAR_MDK\Project\simple_dynamic_magnetic_stripe\EWARM\Project.eww
2. Recompile the project: Project -> Rebuild all
3. Run the debugging: Project -> Download and debug (CTRL + D)
4. Run the program: Debug -> Go (F5)

video
https://vimeo.com/117794013