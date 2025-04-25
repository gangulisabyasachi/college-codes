@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 92da5f19f31949b7a5e643c6a43d1232 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot NOR_Gate_TBW_behav xil_defaultlib.NOR_Gate_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
