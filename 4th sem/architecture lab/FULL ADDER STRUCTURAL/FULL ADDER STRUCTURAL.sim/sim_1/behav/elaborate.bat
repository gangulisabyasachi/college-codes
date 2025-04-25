@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 31ccb1e03756495b9ac66bc10b02be05 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot FULL_ADDER_STRUCTURAL_TBW_behav xil_defaultlib.FULL_ADDER_STRUCTURAL_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
