@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 568ffd139ca8469db224e1f4097b8295 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot OR_Gate_tbw_behav xil_defaultlib.OR_Gate_tbw -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
