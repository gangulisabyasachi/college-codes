@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto d2202b57b784478abf332e4b282d0df0 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot NAND_Gate_TBW_behav xil_defaultlib.NAND_Gate_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
