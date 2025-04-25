@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xsim FULL_ADDER_STRUCTURAL_TBW_behav -key {Behavioral:sim_1:Functional:FULL_ADDER_STRUCTURAL_TBW} -tclbatch FULL_ADDER_STRUCTURAL_TBW.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
