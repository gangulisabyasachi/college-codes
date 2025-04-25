@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 67aa688d9fef426a84709b5735809358 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot NOT_NOR_TBW_behav xil_defaultlib.NOT_NOR_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
