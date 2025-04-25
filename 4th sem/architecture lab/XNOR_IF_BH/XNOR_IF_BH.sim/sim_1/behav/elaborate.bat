@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 0a61cd977f0e4e728954eb5bffa264dc -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot XNOR_IF_TBW_behav xil_defaultlib.XNOR_IF_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
