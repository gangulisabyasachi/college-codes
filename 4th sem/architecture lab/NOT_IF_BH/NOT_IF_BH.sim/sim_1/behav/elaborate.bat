@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto d0dda0b35d90483b8e72cc1f2cfd4254 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot NOT_IF_TBW_behav xil_defaultlib.NOT_IF_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
