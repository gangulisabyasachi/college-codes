@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto ab4bcde2d692488d8a281fa1c2916d75 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot OR_IF_TBW_behav xil_defaultlib.OR_IF_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
