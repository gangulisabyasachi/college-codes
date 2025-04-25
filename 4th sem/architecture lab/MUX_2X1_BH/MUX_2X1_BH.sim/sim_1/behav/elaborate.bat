@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 61b5c9c78ba0488ab3878bcfc1f041c6 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot MUX_2X1_BH_TBW_behav xil_defaultlib.MUX_2X1_BH_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
