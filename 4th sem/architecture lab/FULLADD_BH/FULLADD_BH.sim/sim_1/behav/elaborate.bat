@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto f45dc8a9526f46d0a19ad2c095858e75 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot FULLADD_TBW_behav xil_defaultlib.FULLADD_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
