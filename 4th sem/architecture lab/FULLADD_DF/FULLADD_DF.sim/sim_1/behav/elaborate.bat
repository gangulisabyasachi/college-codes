@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto fbad41a76ebd457eb5fdbeb52ee0543c -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot FULLADD_TBW_behav xil_defaultlib.FULLADD_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
