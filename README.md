The program serves to demonstrate the emulation of dynamic magnetic strip.
Software adapted to run on the controller STM32f405RG, but can easily be converted floor of any programmable controller.
<BR>
to adapt the code for your controller must:
<BR>
1. Correct the initialization GPIO function stripe_init
<BR>
2. Correct the code inverting output state function stripe_2_toggle
<BR>
3. Correct function of time delay in the functions vait_stripe_2_half_period, vait_stripe_2_period,
<BR>

launch CooCox IDE:
<BR>
1. Open the project: \software\CooCox\simple_dynamic_magnetic_stripe.coproj
<BR>
2. Recompile the project: Project -> Rebuild (CTRL + R)
<BR>
3. Record the controller firmware: Flash -> Program Download
<BR>

Running in Keil MDK-ARM
<BR>
1. Open the project: \software\IAR_MDK\Project\simple_dynamic_magnetic_stripe\MDK-ARM\Project.uvprojx
<BR>
2. Recompile the project: Project -> Rebuild all target files
<BR>
3. Run the debugging: Debug -> Start/Stop Debug Session (CTRL + F5)
<BR>
4. Run the program: Debug -> Run (F5)
<BR>

Running in IAR Embedded Workbench
<BR>
1. Open the project: \software\IAR_MDK\Project\simple_dynamic_magnetic_stripe\EWARM\Project.eww
<BR>
2. Recompile the project: Project -> Rebuild all
<BR>
3. Run the debugging: Project -> Download and debug (CTRL + D)
<BR>
4. Run the program: Debug -> Go (F5)
<BR>

video
<BR>
https://vimeo.com/117794013