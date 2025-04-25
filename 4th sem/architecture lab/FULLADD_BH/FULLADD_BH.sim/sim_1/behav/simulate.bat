@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xsim FULLADD_TBW_behav -key {Behavioral:sim_1:Functional:FULLADD_TBW} -tclbatch FULLADD_TBW.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
