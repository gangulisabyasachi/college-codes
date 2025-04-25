@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto d016743e40f7497ab8190231321da5e7 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot HFADD_TBW_behav xil_defaultlib.HFADD_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
